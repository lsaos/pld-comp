ANTLR=/shares/public/tp/ANTLR4-CPP/bin/antlr4
ANTLRRUNTIME=/shares/public/tp/ANTLR4-CPP
CC=g++
PATHBIN=bin/
PATHSRC=src/
EXEC=exec
SRC=$(wildcard $(PATHSRC)*$(EXTEN))
OBJ=$(SRC:$(PATHSRC)%$(EXTEN)=$(PATHBIN)%.o)

.PHONY: clean

antlr: $(PATHSRC)expr.g4
	$(ANTLR) -visitor -no-listener -Dlanguage=Cpp  $(PATHSRC)expr.g4
	clang++ -DTRACE -g -std=c++11   -I $(ANTLRRUNTIME)/antlr4-runtime/ $(PATHSRC)*.cpp -o $(EXEC) $(ANTLRRUNTIME)/lib/libantlr4-runtime.a
	
clean:
	rm -rf $(PATHSRC)expr*.cpp $(PATHSRC)expr*.h $(PATHSRC)expr*.tokens $(PATHSRC)expr*.interp
	
rmproper:
	clean
	rm -rf $(EXEC)
