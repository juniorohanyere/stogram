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
	char *hex_data, *new_hex, *dup;

	length = strlen(data);
	hex_data = malloc(sizeof(data) * 2 + 1);
	new_hex = malloc(sizeof(char) * 1024);

	for (i = 0; i < length; i++)
	{
		if (data[i] == '/')
		{
			sprintf(hex_data + (i * 2), "%02c", '/');
			strcat(new_hex, "/");
		}
		else if (data[i] == ' ')
		{
			sprintf(hex_data + (i * 2), "%02c", ' ');
			strcat(new_hex, " ");
		}
		else
		{
			sprintf(hex_data + (i * 2), "%02x", data[i]);
			strcat(new_hex, (char *)&hex_data[strlen(hex_data) - 2]);
			strcat(new_hex, (char *)&hex_data[strlen(hex_data) - 1]);
		}
	}

	return (new_hex);
}

int main(void)
{
	char *s = convert_to_hex("b in/ls\n");
	printf("%s\n", s);
}
