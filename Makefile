#********************************************************************
#-------------------------------------------Déclaration des variables
#********************************************************************

#------------------------------------------En dur
CC=clang++
EXTEN=.cpp
PATHBIN=bin/
PATHSRC=src/
EXEC=$(PATHBIN)exec
GRAM=$(PATHSRC)expr*
SRC=$(wildcard $(PATHSRC)*$(EXTEN))
OBJ=$(SRC:$(PATHSRC)%$(EXTEN)=$(PATHBIN)%.o)
ANTLR=/shares/public/tp/ANTLR4-CPP/bin/antlr4#The path to your antlr4 executable
ANTLRRUNTIME=/shares/public/tp/ANTLR4-CPP#Same, but here the runtime is located
#----------------------Compilation conditionnelle
ifeq ($(DEBUG),yes)
	CONST=-DMAP
	CFLAGS=-ansi -g
	LDFLAGS=$(ANTLRRUNTIME)/lib/libantlr4-runtime.a
else
	ifeq ($(TREE),yes)
		CONST=-DTREEVISIT
	else
		CONST=
	endif
	CFLAGS=-ansi -std=c++11
	LDFLAGS=$(ANTLRRUNTIME)/lib/libantlr4-runtime.a
endif

#********************************************************************
#---------------------------------------------------------Dépendances
#********************************************************************

#------------------------------Cible particulière
.PHONY: clean rmproper test

#---------------------------------Cibles diverses
all:$(EXEC)

$(EXEC): Grammaire $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)
	
$(PATHBIN)%.o: $(PATHSRC)%$(EXTEN)
	$(CC) -I $(ANTLRRUNTIME)/antlr4-runtime/ -o $@ -c $(CONST)  $< $(CFLAGS)

Grammaire: $(PATHSRC)expr.g4
	$(ANTLR) -visitor -no-listener -Dlanguage=Cpp $<
	@echo "Do not delete this file" > Grammaire
	
#--------------------------------Les cibles PHONY
clean:
	rm -rf $(OBJ)

rmproper:
	rm -rf $(OBJ) $(EXEC)
