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
#include <stdio.h>

#include "interface.h"
#include "game.h"
#include "debug.h"

/* TODO: Need to rename 'free' methods as that could conflict with free(3) */
/*
 * shutdown
 * 
 * Cleanly stops the interface and exits
 * 
 * Returns:
 *     Exits with value of 0
 * Asserts:
 *     Nothing 
 */
static void
shutdown (void)
{
    gui.stop (&gui);
    exit (0);
}

/*
 * main
 * 
 * DESCRIPTION
 * 
 * Returns:
 *     RETURN VALUES
 */
int
main (int argc, const char **argv)
{
    atexit (shutdown);
    gui.start (&gui);
    jrogue.load (&jrogue);

    jrogue.loop (&jrogue);

    exit (0);
}
