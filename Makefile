CC := gcc
LINT := splint
CTAGS := ctags
CSCOPE := cscope
RM := rm
MKDEPEND := $(CC) -MM

INCLUDES :=
CFLAGS := -c -Wall -ansi $(INCLUDES) -DDEBUG -g
LDFLAGS := -lncurses

SOURCES := main.c interface.c game.c character.c item.c debug.c \
	map.c
OBJECTS := $(SOURCES:.c=.o)
HEADERS := $(SOURCES:.c=.h) types.h
EXE := 
PROGNAME := jrogue$(EXE)
COREFILE := 

TAGFILE := .git/tags

all: $(SOURCES) $(PROGNAME)

$(PROGNAME): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

depend: $(SOURCES) $(HEADERS)
	$(MKDEPEND) $(SOURCES) > .depend

TAGS:
	$(CTAGS) -f $(TAGFILE) -R *

cscope:
	$(CSCOPE) -R -b

lint: $(SOURCES) $(HEADERS)
	$(LINT) $(SOURCES)

clean:
	-$(RM) $(SOURCES:.c=.o) $(PROGNAME) $(COREFILE)

-include .depend
