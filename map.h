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
#ifndef MAP_H
#define MAP_H

#include "interface.h"

#define MAX_DUNGEON_SIZE 1000

typedef struct Dungeon Dungeon;
typedef struct Tile Tile;

Dungeon *new_dungeon (int, int);
Tile *new_tile (int);

/*
 * Tile
 * 
 * Map tile graphic
 * 
 * Members:
 *     Sprite *sprite - graphic representation
 *
 *     free - pointer to destructor
 */
struct Tile {
    Sprite *sprite;

    int dirty;

    void (*free) (Tile *);
};

/*
 * Dungeon
 * 
 * DESCRIPTION
 * 
 * Members:
 *     MEMBER DESCRIPTION
 */
struct Dungeon {
    int rows;
    int cols;

    Tile *tiles[MAX_DUNGEON_SIZE];

    void (*free) (Dungeon *);
    void (*draw) (Dungeon *);
};

#endif /* !MAP_H */
