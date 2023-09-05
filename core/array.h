#ifndef STRING_H
#define STRING_H

#include <unistd.h>
#include <ncurses.h>
#include <panel.h>

size_t a_winlen(WINDOW **wins);
size_t a_panlen(PANEL **pans);
size_t a_strlen(char **str);

#endif	/* STRING_H */
