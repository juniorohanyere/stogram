#include "logo.h"

/**
 * logo_stg - the stogram ascii logo
 *
 * @win: the window to display the logo
 * @y: the horizontal position to display the logo on @win
 * @x: the vertical position to display the logo on @win
 *
 * Return: return nothing
*/

void logo_stg(WINDOW *win, int y, int x)
{
	/* print the stogram logo in ascii format */
	mvwprintw(win, y++, x, " SSSSSTTTTTTTTGGGGG");
	mvwprintw(win, y++, x, "SSS      TT  GG");
	mvwprintw(win, y++, x, " SSSSS   TT  GG  GGG");
	mvwprintw(win, y++, x, "    SSS  TT  GG   GG");
	mvwprintw(win, y++, x, " SSSSS   TT   GGGGG");
	mvwprintw(win, y++, x, "    MAKE IT HAPPEN");
}
