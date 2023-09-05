#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#define SYSROOT "46"	/* / */
#define ROOT "16212117"	/* /root */
#define HOME "30214315"	/* /home */
#define BIN "412042"	/* /bin */
#define SHELL "192616/412042/382630"	/* /usr/bin/xsh */
#define TMP "174322"	/* /tmp */

/**
 * for sending and retrieving shared data between other programming languages
 * that will be used to build this project
*/
#define DATA_SHARE "DATA_SHARE"

#define PATH "/bin:/usr:/usr/bin:"
#define HISTSIZE 1000

/**
 * struct filesystem - type definition for a file system structure
 *
 * @files: pointer to files
 * @dirnames: pointer to directories
 *
 * Description: this type definition might be used later
 *
 * Return: return nothing
*/

typedef struct filesystem
{
	directory_t *dirs;
} filesystem_t;

/**
 * struct files - type definition for a file structure
 *
 * @filename: the name of the file
 * @data: the content of the file
 * @next: pointer to the next file
 *
 * Return: return nothing
*/

typedef struct files
{
	char *filename
	char *data;
	struct files *next;
} file_t;

/**
 * struct directories - type definition for a directory structure
 *
 * @dirname: the name of a directory
 * @files: pointer to an array of files
 * @subdir: pointer to sub directories
 * @next: pointer to the next directory
 *
 * Return: return nothing
*/

typedef struct directories
{
	char *dirname;
	file_t *files
	struct directories *subdir;
	struct directories *next;
} directory_t;

#ifndef	/* FILESYSTEM_H */
