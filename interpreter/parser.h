#ifndef PARSER_H
#define PARSER_H

#include <ncurses.h>
#include <panel.h>

char **parse(WINDOW **wins, PANEL **pans, char *buffer, char *delimiter);

#endif	/* PARSER_H */
