#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "stogram.h"
#include "error.h"
#include "exit.h"

/**
 * convert_to_hex - converts a string data to hexadecimal
 *
 * @wins: array of window objects
 * @pans: array of panel objects
 * @data: the string data to convert
 *
 * Return: return a pointer to the hexadecimal value of @data
*/

char *convert_to_hex(WINDOW **wins, PANEL **pans, const char *data)
{
	int i, length;
	char *hex_data, *new_hex;

	length = strlen(data);
	new_hex = calloc(sizeof(char), BUFFER_SIZE);
	if (new_hex == NULL)
	{
		malloc_error(), clean_up(wins, pans);
		free(pans), free(wins), exit(EXIT_FAILURE);
	}

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
			if (hex_data == NULL)
			{
				malloc_error();
				free(new_hex);
				clean_up(wins, pans);
				free(wins), free(pans);
				exit(EXIT_FAILURE);
			}
			sprintf(hex_data, "%02x", data[i]);
			strcat(new_hex, hex_data);
			free(hex_data);
		}
	}
	return (new_hex);
}
