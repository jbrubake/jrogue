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
#ifndef CHARACTER_H
#define CHARACTER_H

#include "interface.h"
#include "types.h"

typedef struct Character Character;

/*
 * Character
 * 
 * Player, NPCs and monsters
 * 
 * Members:
 *     MEMBER DESCRIPTION
 */
struct Character {
    int type;
    Sprite *sprite;    

    void (*free) (Character *);
};

Character *new_character (int);

#endif /* !CHARACTER_H */


