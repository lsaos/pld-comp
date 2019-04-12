# PLD-COMP
PLD Compilateur
By the super hexanome whatever its number is (kidding, its 4404).

## How to build the compiler ?

### Setup the makefile

You will first need to make sure that the Makefile is actually referencing your antlr-cpp runtime.
Therefore, you will have to open the Makefile, and take a look at lines 36 through 39 :

	ANTLR=/shares/public/tp/ANTLR4-CPP/bin/antlr4#The path to your antlr4 executable
	ANTLRRUNTIME=/shares/public/tp/ANTLR4-CPP#Main folder of antlrcpp
	ANTLRSRC=$(ANTLRRUNTIME)/antlr4-runtime#Same, but here the runtime is located
	LDFLAGS=$(ANTLRRUNTIME)/lib/libantlr4-runtime.a

You may have to change *ANTLR*, *ANTLRRUNTIME*, *ANTLRSRC* and *LDFLAGS* such that they all point to your personnal antlr files or installation directories.

_Remark_ : The current Makefile is already adapted to the INSA IT department's computers.

### Build the executable

First of all, make sure the grammar is up to date by running :
> make Grammaire

Now, just run :
> make

in order to build the whole executable. It will be named "./compiler"

Last but not least, if you want to run tests, you can either write :
> make test

or
> cd tests && bash mktest.sh && cd ..

Which is basically the content of the test target.

## What can I find in this folder ?

Here's a description of the folder hierarchy :
<ul>
<li>src : Source code
	<ul>
	<li>parser : Every bit of code dealing with the antlr lexers and parsers. You'll find there the grammar (expr.g4) and the visitors' implementation (visitor.cpp)</li>
	<li>ast : You will find here every class modelling what our C program consists of, i.e. AST...</li>
	<li>ir : You will find every item about IR.</li>
	<li>main : This folder name is perhaps obvious about its content.</li></ul>
<li>tests : You will find here a list of tests that can be run with the command /$make test/. Every category of test is arranged in subfolders.
	<ul>
	<li> ValidPrograms : programs that should normally compile with our executable.</li>
	<li> LexError : Program generating a Lexer Error.</li>
	<li> SyntaxError : Same, with syntax.</li>
	<li> SemanticError : Same, with semantics.</li>
	<li> Moodle : All the tests that were downloaded from Moodle<ul>
		<li> Front</li>
		<li> Back</li>
	</ul></li></ul></li>
<li> build : It's useless to take a look at it, unless you know how to read .o files.</li>
</ul>

