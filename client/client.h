#ifndef CLIENT_H
#define CLIENT_H

typedef struct sockaddr sockaddr_t;
typedef struct sockaddr_in sockaddr_in_t;

int connect_to_server(char *data, char *address, int port);

#endif	/* CLIENT_H */
