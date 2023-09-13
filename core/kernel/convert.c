#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "error.h"
#include "exit.h"
#include "convert.h"
#include "externs.h"

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
	new_hex = calloc(sizeof(char), BUFFER_SIZE);
	if (new_hex == NULL)
	{
		malloc_error(), clean_up();
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
				clean_up();
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

/**
 * convert_to_string - converts an hexadecimal to string
 *
 * @data: the haxadecimal data to convert
 *
 * Return: return a pointer to the string representation of @data
*/

char *convert_to_string(const char *data)
{
        int i, length;
        unsigned int b;
        char *new_string, *string_data;

        length = strlen(data);
        new_string = calloc(sizeof(char), length + 1);
        if (new_string == NULL)
        {
                malloc_error();
                free(pans), free(wins), exit(EXIT_FAILURE);
        }

        for (i = 0; i < length; i += 0)
        {
		if (data[i] == '/')
		{
			strcat(new_string, "/");
			i += 1;
		}
		else
		{
	                string_data = calloc(sizeof(char), 4);
	                string_data[0] = data[i];
	                string_data[1] = data[i + 1];
	                string_data[2] = '\0';
	                sscanf(string_data, "%02x", &b);
	                strcat(new_string, (char *)&b);
	                free(string_data);
			i += 2;
		}
        }
        return (new_string);
}
