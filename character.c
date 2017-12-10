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
#include <stdlib.h>

#include "character.h"
#include "interface.h"

/*
 * character_free
 * 
 * Cleanly delete a Character
 * 
 * Parameters:
 *     c - Character * to free
 * Asserts:
 *     ASSERTIONS
 */
void
character_free (Character *this)
{
    this->sprite->free (this->sprite);
    free (this);
}

/*
 * new_character
 * 
 * Create and return a pointer to a new Character of the specified type
 * 
 * Parameters:
 *     PARAMETERS
 * Returns:
 *     Pointer to created Character
 *     NULL on failure
 * Asserts:
 *     ASSERTIONS
 */
Character *
new_character (int type)
{
    type = 2; /* XXX: Temporary hack */
    Character *c = malloc (sizeof (Character));
    if (c == 0)
        return 0;

    c->sprite = new_sprite (type);
    c->free = character_free;
    return c;
}

