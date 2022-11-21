CC = gcc -Wall
RM = rm -f
SRC = $(wildcard *.c)
HEAD = $(wildcard *.h)
OBJ = $(SRC:.c=.o)
LNK = -lm
PROG = a.out

all : $(PROG)

$(PROG) : $(OBJ)
	$(CC) $^ -o $@ $(LNK)

.c.o :
	$(CC) -c $^ -o $@

.PHONY : clean

clean : 
	$(RM) $(OBJ) $(PROG)