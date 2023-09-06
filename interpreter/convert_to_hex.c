#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * convert_to_hex - converts a string data to hexadecimal
 *
 * @data: the string data to convert
 *
 * Return: return a pointer to the hexadecimal value of @data
*/

char *convert_to_hex(const char *data)
{
	int i, length;
	char *hex_data, *new_hex;

	length = strlen(data);
	new_hex = calloc(sizeof(char), 1024);

	for (i = 0; i < length; i++)
	{
		if (data[i] == '/')
		{
			strcat(new_hex, "/");
		}
		else if (data[i] == ' ')
		{
			strcat(new_hex, " ");
		}
		else
		{
			hex_data = malloc(sizeof(data) * 2 + 1);
			sprintf(hex_data, "%02x", data[i]);
			strcat(new_hex, hex_data);
			free(hex_data);
		}
	}

	return (new_hex);
}
