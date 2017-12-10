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
#include <stdio.h>

#include "game.h"
#include "interface.h"
#include "map.h"

/*
 * main_loop
 * 
 * Main game loop. Everything happens here
 * 
 * Returns:
 *     RETURN VALUES
 * Asserts:
 *     ASSERTIONS
 */
int
main_loop (Game *this)
{
    int k = 0;
    Dungeon *d = new_dungeon (30, 30);

    /*for (;;) {*/
        d->draw (d);
        gui.update (&gui);
        gui.getkey (&gui);
    /*}*/

    d->free (d);

    return 0; 
}

/*
 * load_game
 * 
 * Either load a savegame or create a new one
 * 
 * Returns:
 *     RETURN VALUES
 * Asserts:
 *     ASSERTIONS
 */
int
load_game (Game *this)
{
    /* XXX: No type specified yet */
    this->pc = new_character (0);
    return 0;
}

Game jrogue = {
    main_loop,
    load_game,
    0
};


