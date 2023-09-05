#include <ncurses.h>
#include <string.h>

#include "filesystem.h"

/**
 * create_file - creates a new virtual file for the virtual envrionment of the
 *		 stogram command line application
 *
 * @filename: the name of the virtual file to create
 * @data: the content of the file
 *
 * Description: @data can be set to NULL signifying the file to be created is
 *		an empty file
 *
 * Return: return a pointer to the newly created file
*/

file_t *create_file(const char *filename, char *data)
{
	file_t *tmp_file;

	tmp_file->filename = strdup(filename);
	tmp_file->data = strdup(data);

	tmp_file->next = NULL;

	return (tmp_file);
}

/**
 * create_directory - creates a new directory for the virtual envrionment of
 *		      stogram command line application
 *
 * @dirname: the name of the virtual directory to create
 * @files: pointer to files to be contained in the directory
 * @dirs: pointer to sub directories to be contained in the directory
 *
 * Description: @files and @dirs can be NULL, meaning no files and/or
 *		directories present
 *
 * Return: return a pointer to the newly created directory
*/

directory_t *create_directory(const char *dirname, file_t *files,
	dirctory_t dirs)
{
	directory_t *tmp_dir;

	tmp_dir->dirname = strdup(dirname);
	tmp_dir->files = strdup(files);
	tmp_dir->subdir = strdup(dirs);

	tmp_dir->next = NULL;

	return (tmp_dir);
}

/**
 * path - gets the current working directory
 *
 * @dir: the current working directory
 *
 * Return: return nothing
*/

PATH *path(void)
{
	PATH *p = {
		{"/bin", "getenv("HOME")/.stogram/bin"},
		{"/usr", "getenv("HOME")/.stogram/usr"},
		{"/usr/bin", "getenv("HOME")/.stogram/usr/bin"}
	};
}
