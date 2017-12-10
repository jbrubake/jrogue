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

#include "item.h"
#include "interface.h"

/*
 * item_free
 * 
 * Cleanly delete an Item
 * 
 * Parameters:
 *     i - Item * to free
 * Asserts:
 *     ASSERTIONS
 */
void
item_free (Item *this)
{
   this->sprite->free (this->sprite);
   free (this);
}

/*
 * new_item
 * 
 * Create and return a pointer to a new Item of the specified type
 * 
 * Parameters:
 *     int type - type of Item to create
 * Returns:
 *     Pointer to created Item
 *     NULL on failure
 * Asserts:
 *     ASSERTIONS
 */
Item *
new_item (int type)
{
   Item *i = malloc (sizeof (Item));
   if (i == 0)
       return 0;

   i->sprite = new_sprite (type);
   i->free = item_free;
   return i;
}

