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
#ifndef ITEM_H
#define ITEM_H

#include "interface.h"
#include "types.h"

typedef struct Item Item;

/*
 * Item
 * 
 * All items
 * 
 * Members:
 *     MEMBER DESCRIPTION
 */
struct Item {
    int type;
    Sprite *sprite;    

    void (*free) (Item *);
};

Item *new_item (int);

#endif /* !ITEM_H */


