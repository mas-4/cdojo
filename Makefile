OBJECTS=
CFLAGS = -g -Wall -O3 -std=gnu11
LDLIBS=-lgsl -lgslcblas -lm
CC=gcc

$(P): $(OBJECTS)
