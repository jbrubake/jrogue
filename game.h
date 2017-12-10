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
#ifndef GAME_H
#define GAME_H

#include "character.h"

typedef struct Game Game;

/*
 * Game
 * 
 * Data and functions for game management
 * 
 * Members:
 *     loop - game event/input loop
 *     load - load savegame or create a new one
 *
 *     pc - player character
 */
struct Game {
    int (*loop) (Game *);
    int (*load) (Game *);

    Character *pc;
};

extern Game jrogue;

#endif /* !GAME_H */


