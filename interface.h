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
#ifndef INTERFACE_H
#define INTERFACE_H

#include <curses.h>

typedef struct Interface Interface;
typedef struct Sprite Sprite;

Sprite *new_sprite (int);

/*
 * Interface
 * 
 * Provides interface to IO functions
 * 
 * Members:
 *     start - interface initialization function
 *     stop - interface shutdown function
 *     getkey - get keypress/mouse click from user
 *     redraw - refresh screen
 */
struct Interface {
    int (*start) (Interface *);
    int (*stop) (Interface *);
    int (*getkey) (Interface *);

    int (*update) (Interface *);
    int (*wipe) (Interface *);

    int (*writech) (Interface *, int, int, const chtype);
    int (*writesprite) (Interface *, int, int, Sprite *);

    int (*printmsg) (Interface *, const char *);
};

extern Interface gui;

/*
 * Sprite
 * 
 * Character or item graphic
 * 
 * Members:
 *     char symbol - ASCII character graphic
 */
struct Sprite {
    char symbol;

    void (*free) (Sprite *);
};


#endif /* !INTERFACE_H */
