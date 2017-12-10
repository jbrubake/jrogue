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
#ifndef DEBUG_H
#define DEBUG_H

/*
 * Usage: TRACE((level, fmt, ...))
 *
 * level: debug level at which output will appear
 * fmt: printf(3) format string
 * ...: format string args
 *
 * NOTE: DOUBLE PARENS ARE *REQUIRED*
 */
#ifdef DEBUG
#   define TRACE(x) db_trace x
#else
#   define TRACE(x) do {if (0) db_trace x; } while (0)
#endif /* DEBUG */

void db_trace (const char *, ...);

#endif /* !DEBUG_H */


