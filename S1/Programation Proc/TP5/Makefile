CC = gcc -Wall
RM = rm -f
LNK = -lm

srcdir = ./src/
bindir = ./bin/
docdir = ./doc/
savdir = ./backup/

PROG = $(bindir)a.out
SRC = $(wildcard $(srcdir)*.c)
HEAD = $(wildcard $(srcdir)*.h)
OBJ = $(subst $(srcdir), $(bindir), $(SRC:.c=.o))

all : $(PROG)

$(PROG) : $(OBJ)
	$(CC) $^ -o $@ $(LNK)

$(bindir)%.o : $(srcdir)%.c
	$(CC) -c $^ -o $@

.PHONY : clean

clean : 
	$(RM) $(OBJ) $(PROG)