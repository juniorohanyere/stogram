#ifndef LISTDIR_H
#define LISTDIR_H

#include <ncurses.h>

typedef struct dirent dirent_t;

int list_dir(WINDOW *win, char *command, char *args[]);

#endif	/* LISTDIR_H */
