#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "client.h"

/**
 * connect_to_server - connects to a host on a specific local host and port and
 *		       communicates data with the host
 *
 * @data: the data to share
 * @address: the IP address of the host
 * @port: the port number of the host
 *
 * Return: return 0 on success
 *	   return 1 on failure
*/

int connect_to_server(char *data, char *address, int port)
{
	int c_socket;
	sockaddr_in_t s_address;
	char *hex_data;
	ssize_t bytes_received;

	/* create a socket */
	c_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (c_socket == -1)
	{
		dprintf(STDERR_FILENO, "Error: Unable to create a socket\n");
		return (1);
	}

	/* configure the server address */
	s_address.sin_family = AF_INET;
	s_address.sin_port = htons(port);	/* server port */
	s_address.sin_addr.s_addr = inet_addr(address);	/* server IP */

	/* connect to the server */
	if (connect(c_socket, (sockaddr_t *)&s_address,
		sizeof(s_address)) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Unable to establish a connection\n");
		close(c_socket);
		return (1);
	}

	/* send data to the server */
        send(c_socket, data, strlen(data), 0);

	/* receive the response in hexadecimal format from the (python) server */
	hex_data = malloc(sizeof(data) * 2);
	bytes_received = recv(c_socket, hex_data, sizeof(hex_data) * 2, 0);

	if (bytes_received <= 0)
	{
		dprintf(STDERR_FILENO,
			"Error: Connection close unexpectedly\n");
		return (1);
	}

	hex_data[bytes_received] = '\0';	/* null termination */
	printf("Server response in hexadecimal format: %s\n", hex_data);

	/* close the socket */
	close(c_socket);

	return 0;
}

int main(void)
{
	connect_to_server("Hello Server", "127.0.0.1", 12345);

	return (0);
}
