ANTLR=/shares/public/tp/ANTLR4-CPP/bin/antlr4 #Put here your path to antlr
ANTLRRUNTIME=/shares/public/tp/ANTLR4-CPP #Same, but to antlr runtime
CC=g++
PATHBIN=bin/ #Useless, indeed, but how knows, maybe later ?
PATHSRC=src/
EXEC=exec
SRC=$(wildcard $(PATHSRC)*$(EXTEN))
OBJ=$(SRC:$(PATHSRC)%$(EXTEN)=$(PATHBIN)%.o) #See previous comment

.PHONY: clean

antlr: $(PATHSRC)expr.g4
	$(ANTLR) -visitor -no-listener -Dlanguage=Cpp  $(PATHSRC)expr.g4
	clang++ -DTRACE -g -std=c++11   -I $(ANTLRRUNTIME)/antlr4-runtime/ $(PATHSRC)*.cpp -o $(EXEC) $(ANTLRRUNTIME)/lib/libantlr4-runtime.a
