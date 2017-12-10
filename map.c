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
            ; i < this->rows * this->cols; i++) {
\*--------------------------------------------------------------------*/
#include <stdlib.h>
#include <assert.h>

#include "map.h"
#include "interface.h"
#include "debug.h"

/*
 * dungeon_free
 * 
 * Cleanly delete a Dungeon
 * 
 * Parameters:
 *     d - pointer to Dungeon to free
 * Asserts:
 *     ASSERTIONS
 */
void
dungeon_free (Dungeon *this)
{
    int i = 0;
    Tile **tiles = this->tiles;

    for (i = 0; i < this->rows * this->cols; i++) {
        (*tiles)->free (*tiles);
        tiles++;
    }
    free (this);
}

void
dungeon_draw (Dungeon *this)
{
    int y = 0;
    int x = 0;
    int i = 0;

    for (y = 0; y < this->rows; y++) {
        for (x = 0; x < this->cols; x++) {
            if (this->tiles[i]->dirty) {
                gui.writesprite (&gui, y, x, this->tiles[i]->sprite);
                this->tiles[i]->dirty = 0;
            }
            i++;
        }
    }
}

/*
 * new_dungeon
 * 
 * Create a new dungeon with the given parameters
 * 
 * Parameters:
 *     rows, cols - Dungeon dimensions
 * Returns:
 *     Pointer to new Dungeon
 *     0 on failure
 * Asserts:
 *     ASSERTIONS
 */
Dungeon *
new_dungeon (int rows, int cols)
{
    assert (rows * cols < MAX_DUNGEON_SIZE);

    int y = 0; int x = 0; int i = 0;

    Dungeon *d = malloc (sizeof (Dungeon));
    if (d == 0)
        return 0;

    d->free = dungeon_free;
    d->draw = dungeon_draw;

    d->rows = rows;
    d->cols = cols;

    for (y = 0; y < d->rows; y++) {
        for (x = 0; x < d->cols; x++) {
            d->tiles[i] = new_tile (1);
            d->tiles[i]->dirty = 1;
            i++;
        }
    }

    return d;
}

/*
 * tile_free
 * 
 * Cleanly delete a Tile
 * 
 * Parameters:
 *     s - pointer to Tile to free
 * Asserts:
 *     ASSERTIONS
 */
void
tile_free (Tile *this)
{
    this->sprite->free (this->sprite);
    free (this); 
}

/*
 * new_tile
 * 
 * Create and return a pointer to a Tile of the specified type
 * 
 * Parameters:
 *     int type - type of Tile to create
 * Returns:
 *     Pointer to created Tile
 *     NULL on failure
 * Asserts:
 *     ASSERTIONS
 */
Tile *
new_tile (int type)
{
    type = 1; /* XXX: Temporary hack */
    Tile *t = malloc (sizeof (Tile));
    if (t == NULL)
        return NULL;

    t->sprite = new_sprite (type);
    t->free = tile_free;

    return t;
}
