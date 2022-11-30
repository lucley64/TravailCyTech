CC = gcc -Wall
RM = rm -f
LNK = -lm
CP = cp -r -f

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

.PHONY : clean save restore doc init

clean : 
	$(RM) $(OBJ) $(PROG)

save : 
	$(CP) $(srcdir)* $(savdir)

restore : 
	$(CP) $(savdir)* $(srcdir)

doc : Doxyfile
	doxygen Doxyfile

Doxyfile :
	doxygen -g
	sed -i "s/\(PROJECT_NAME *=\).*/\1 \""$$(basename "$$(pwd)")"\"/g" ./Doxyfile
	sed -i "s/\(OUTPUT_DIRECTORY *=\).*/\1 \"$(subst /,\/,$(docdir))\"/g" ./Doxyfile
	sed -i "s/\(OUTPUT_LANGUAGE *=\).*/\1 \"French\"/g" ./Doxyfile
	sed -i "s/\(INPUT *=\).*/\1 \"$(subst /,\/,$(srcdir))\"/g" ./Doxyfile
	sed -i "s/\(RECURSIVE *=\).*/\1 YES/g" ./Doxyfile

init : 
	mkdir backup/ src/ bin/ doc/

#TODO give