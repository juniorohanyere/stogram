#include "logo.h"
#include "externs.h"

/**
 * logo_stg - the stogram ascii logo
 *
 * @y: the horizontal position to display the logo on @win
 * @x: the vertical position to display the logo on @win
 *
 * Return: return nothing
*/

void logo_stg(int y, int x)
{
	/* print the stogram logo in ascii format */
	mvwprintw(wins[0], y++, x, " SSSSSTTTTTTTTGGGGG");
	mvwprintw(wins[0], y++, x, "SSS      TT  GG");
	mvwprintw(wins[0], y++, x, " SSSSS   TT  GG  GGG");
	mvwprintw(wins[0], y++, x, "    SSS  TT  GG   GG");
	mvwprintw(wins[0], y++, x, " SSSSS   TT   GGGGG");
	mvwprintw(wins[0], y++, x, "    MAKE IT HAPPEN");
}
