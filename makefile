# Makefile for Austin Choi's braifuck compiler

MAIN		= ./main.cpp
INCLUDES	= ./includes/lexer.cpp ./includes/translator.cpp
OUTFILE		= ./bfCompile

all: a.out

a.out: main.cpp
	g++ $(MAIN) $(INCLUDES) -o $(OUTFILE)

clean:
	rm -rf $(OUTFILE)
