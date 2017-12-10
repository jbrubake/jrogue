/*--------------------------------------------------------------------*\
| This file is part of jrogue
|
| Copyright 2013, Jeremy Brubaker <jbru362@gmail.com>
|---------------------------------------------------------------------*\
| jrogue is free software: you can redistribute it and/or modify       |
| it under the terms of the GNU General Public License as published by |
| the Free Software Foundation, either version 3 of the License, or    |
| (at your option) any later version.                                  |
|                                                                      |
| jrogue is distributed in the hope that it will be useful,            |
| but WITHOUT ANY WARRANTY; without even the implied warranty of       |
| MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the         |
| GNU General Public License for more details.                         |
|                                                                      |
| You should have received a copy of the GNU General Public License    |
| along with jrogue. If not, see <http://www.gnu.org/licenses/>.       |
\*--------------------------------------------------------------------*/
#include <stdio.h>
#include <stdarg.h>

void
db_trace (const char *fmt, ...)
{
    va_list args;
    va_start (args, fmt);
    vfprintf (stderr, fmt, args);
    va_end (args);
}

