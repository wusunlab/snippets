# compiler & linker settings
FC = /usr/local/bin/gfortran
FCFLAGS = -g -Wall -Wextra -pedantic -std=f2008 -O3 -march=native \
	-fimplicit-none -fcheck=all -fbacktrace
FLFLAGS = -g
PROGRAM = test_eps

# source file and objects
SRCS=$(wildcard *.f90)
OBJS=$(patsubst %.f90, %.o, $(SRCS))

# rules for building
$(OBJS): %.o: %.f90
	$(FC) $(FCFLAGS) -c $< -o $@

$(PROGRAM): $(OBJS)
	$(FC) $(FLFLAGS) -o $@ $^

# utilities
.PHONY: clean debug default all

default: $(PROGRAM)

debug:
	@echo "SRCS = $(SRCS)"
	@echo "OBJS = $(OBJS)"
	@echo "PROGRAM = $(PROGRAM)"

clean:
	rm -f *.o *.mod $(PROGRAM)
	rm -rf $(PROGRAM).dSYM

all: clean default
