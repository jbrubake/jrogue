/*--------------------------------------------------------------------*\
| This file is part of jrogue
|
| Copyright 2013, Jeremy Brubaker <jbru362@gmail.com>
|-----------------------------------------------------------------------
| jrogue is free software: you can redistribute it and/or modify
| it under the terms of the GNU General Public License as published by
| the Free Software Foundation, either version 3 of the License, or
| (at your option) any later version.
|
| jrogue is distributed in the hope that it will be useful,
| but WITHOUT ANY WARRANTY; without even the implied warranty of
| MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
| GNU General Public License for more details.
|
| You should have received a copy of the GNU General Public License
| along with jrogue. If not, see <http://www.gnu.org/licenses/>.
\*--------------------------------------------------------------------*/
#include <ncurses.h>
#include <stdlib.h>

#include "interface.h"
#include "debug.h"

/*
 * sprite_free
 * 
 * Cleanly delete a Sprite
 * 
 * Parameters:
 *     s - pointer to Sprite to free
 * Asserts:
 *     ASSERTIONS
 */
void
sprite_free (Sprite *this)
{
   free (this); 
}

/*
 * new_sprite
 * 
 * Create and return a pointer to a Sprite of the specified type
 * 
 * Parameters:
 *     int type - type of Sprite to create
 * Returns:
 *     Pointer to created Sprite
 *     NULL on failure
 * Asserts:
 *     ASSERTIONS
 */
Sprite *
new_sprite (int type)
{
    Sprite *s = malloc (sizeof (Sprite));
    if (s == NULL)
        return NULL;

    switch (type) {
        case 1:
            s->symbol = '.';
            break;
        case 2:
            s->symbol = '@';
            break;
        default:
            s->symbol = ' ';
            break;
    }

    s->free = sprite_free;

    return s;
}

/*
 * start_curses
 * 
 * Setup GUI and keymap data structures
 * and do any necessary initialization
 * 
 * Returns:
 *     0 on success
 *    -1 on failure
 * Asserts:
 *     ASSERTIONS
 */
int
start_curses (Interface *this)
{
    initscr ();
    clear ();
    noecho ();
    cbreak ();
    curs_set (0);

    return 0;
}

/*
 * stop_curses
 * 
 * Cleanly stop the interface
 * 
 * Returns:
 *     0 on succes
 *    -1 on failure
 * Asserts:
 *     ASSERTIONS
 */
int
stop_curses (Interface *this)
{
    if (endwin () != ERR)
        return 0;
    else
        return -1;
}

/*
 * getkey_curses
 * 
 * Block until user presses a key
 * 
 * Returns:
 *     Value of key pressed
 *     -1 on failure
 * Asserts:
 *     ASSERTIONS
 */
int
getkey_curses (Interface *this)
{
    int k = getch ();
    if (k != ERR)
        return k;
    else
        return -1;
}

/*
 * update_curses
 * 
 * DESCRIPTION
 * 
 * Parameters:
 *     PARAMETERS
 * Returns:
 *     RETURN VALUES
 * Asserts:
 *     ASSERTIONS
 */
int
update_curses (Interface *this)
{
    if (refresh () != ERR)
        return 0;
    else
        return -1;
}
/*
 * wipe_curses
 * 
 * Clear the screen
 * 
 * Returns:
 *     0 on success
 *    -1 on failure
 * Asserts:
 *     ASSERTIONS
 */
int
wipe_curses (Interface *this)
{
    /* FIXME: How to I get this to dirty the screen? */
    if (clear () != ERR)
        return 0;
    else
        return -1;
}

/*
 * mvaddch_curses
 * 
 * Write a character to the screen
 * 
 * Parameters:
 *     PARAMETERS
 * Returns:
 *     RETURN VALUES
 * Asserts:
 *     ASSERTIONS
 */
int
writech_curses (Interface *this, int y, int x, const chtype ch)
{
    return mvaddch (y, x, ch);    
}

/*
 * writesprite_curses
 * 
 * DESCRIPTION
 * 
 * Parameters:
 *     PARAMETERS
 * Returns:
 *     RETURN VALUES
 * Asserts:
 *     ASSERTIONS
 */
int
writesprite_curses (Interface *this, int y, int x, Sprite *s)
{
    return this->writech (this, y, x, s->symbol);    
}

/* XXX: This is a temporary hack for development. Make it better */
/*
 * printmsg_curses
 * 
 * Print a line of text to the message window
 * 
 * Parameters:
 *     const char *s - string to output
 * Returns:
 *     0 on success
 *    -1 on failure
 * Asserts:
 *     ASSERTIONS
 */
int
printmsg_curses (Interface *this, const char *s)
{
   if (printw ("%s\n", s) != ERR)
       return 0;
   else
       return -1;
}

Interface gui = {
    start_curses,
    stop_curses,
    getkey_curses,
    update_curses,
    wipe_curses,
    writech_curses,
    writesprite_curses, 
    printmsg_curses
};

