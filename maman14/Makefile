program_NAME := assembler
CFLAGS += -ansi -pedantic -Wall -g -O
program_C_SRCS := $(wildcard *.c)
program_C_OBJS := ${program_C_SRCS:.c=.o}
program_INCLUDE_DIRS :=
program_LIBRARY_DIRS :=
program_LIBRARIES :=

LDFLAGS += $(foreach librarydir,$(program_LIBRARY_DIRS),-L$(librarydir))
LDFLAGS += $(foreach library,$(program_LIBRARIES),-l$(library))

.PHONY: all clean distclean

all: $(program_NAME)

$(program_NAME): $(program_C_OBJS)
	gcc $(program_C_OBJS) -o $(program_NAME)

clean:
	@- $(RM) $(program_NAME)
	@- $(RM) $(program_C_OBJS)

distclean: clean