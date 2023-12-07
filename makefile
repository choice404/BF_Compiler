# Makefile for Austin Choi's braifuck compiler

MAIN		= ./main.cpp
INCLUDES	= ./sources/lexer.cpp ./sources/translator.cpp
OUTFILE		= ./fck

all: a.out

a.out: main.cpp
	g++ $(MAIN) $(INCLUDES) -o $(OUTFILE)

clean:
	rm -rf $(OUTFILE)
