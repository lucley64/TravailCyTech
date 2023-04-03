CC = nasm -f elf64
RM = rm -rf
LNK = ld
CP = cp -r -f

srcdir = ./src/
bindir = ./bin/
docdir = ./doc/
savdir = ./backup/
outdir = ./out/

PROG = $(subst $(bindir), $(outdir), $(OBJ:.o=.out))
SRC = $(wildcard $(srcdir)*.asm)
HEAD = $(wildcard $(srcdir)*.h)
OBJ = $(subst $(srcdir), $(bindir), $(SRC:.asm=.o))

all : prog

.PHONY : clean save restore doc init prog

prog : $(PROG)

$(outdir)%.out : $(bindir)%.o
	$(LNK) $^ -o $@

$(bindir)%.o : $(srcdir)%.asm
	$(CC) $^ -o $@


clean : 
	$(RM) $(OBJ) $(PROG) $(docdir)*

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