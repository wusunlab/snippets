# compiler & linker settings
CC = /usr/local/bin/gcc-8
CCFLAGS = -g -Wall -Wextra -pedantic -std=c99 -O3 -march=native
LDFLAGS = -g
PROGRAM = test_expint

# source file and objects
SRCS=$(wildcard *.c)
OBJS=$(patsubst %.c, %.o, $(SRCS))

# rules for building
$(OBJS): %.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

$(PROGRAM): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

test_expint.o: expint.o

# utilities
.PHONY: clean debug default all

default: $(PROGRAM)

debug:
	@echo "SRCS = $(SRCS)"
	@echo "OBJS = $(OBJS)"
	@echo "PROGRAM = $(PROGRAM)"

clean:
	rm -f *.o $(PROGRAM)
	rm -rf $(PROGRAM).dSYM

all: clean default
