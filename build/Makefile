#Set project directory one level above Makefile directory
PROJDIR := $(realpath $(CURDIR)/..)
SOURCEDIR := $(PROJDIR)/src
BUILDDIR := $(PROJDIR)/build
GRAMMARFILE := $(PROJDIR)/sources/parser/expr.g4

#Name fo te final executable
TARGET = compiler

#Decide whether the commands will be shown or not
VERBOSE= TRUE

#Create the list of directories
DIRS = ast lib main parser
SOURCEDIRS = $(foreach dir, $(DIRS), $(addprefix $(SOURCEDIR)/, $(dir)))
TARGETDIRS = $(foreach dir, $(DIRS), $(addprefix $(BUILDDIR)/, $(dir)))

#Generate the GCC includes parameters by adding -I before each source folder
INCLUDES = $(foreach dir, $(SOURCEDIRS), $(addprefix -I, $(dir)))

VPATH = $(SOURCEDIRS)

#Create a list of *.c sources in DIRS
SOURCES = $(foreach dir, $(SOURCEDIRS), $(wildcard $(dir)/*.cpp))

#Define objects for all sources
OBJS := $(subst $(SOURCEDIR), $(BUILDDIR), $(SOURCES:.cpp=.o))

#NDefine dependencies files for all objects
DEPS = $(OBJS:.o=.d)

#Name the compiler
CC=clang++
ANTLR=~/Documents/Projets/ANTLR4-CPP/bin/antlr4#The path to your antlr4 executable
ANTLRSRC=/usr/local/include/antlr4-runtime#Same, but here the runtime is located
ANTLRRUNTIME=/usr/local/

CFLAGS=-ansi -std=c++11
LDFLAGS=$(ANTLRRUNTIME)/lib/libantlr4-runtime.a

#OS specific part
ifeq ($(OS), Windows_NT)
	RM = del /F /Q
	RMDIR = -RMDIR /S /Q
	MKDIR = -mkdir
	ERRIGNORE = 2>NUL || true
	SEP = \\
else
	RM = rm -rf
	RMDIR = rm -rf
	MKDIR= mkdir -p
	ERRIGNORE = 2>fichierErreur
	SEP=/
endif

#Remove space after seperator
PSEP=$(strip $(SEP))

#Hide or not the calls depending of VERBOSE
ifeq ($(VERBOSE), TRUE)
	HIDE=
else
	HIDE=@
endif

#Define the function that will generate each rule
define generateRules
$(1)/%.o: %.cpp
	@echo Building $$@
	$(HIDE)$(CC) $(CFLAGS) -I $(ANTLRSRC) -c $$(INCLUDES) -o $$(subst /,$$(PSEP),$$@) $$(subst /,$$(PSEP),$$<) -MMD
endef

.PHONY: all clean directories

all: directories $(TARGET)

$(TARGET): $(OBJS)
	@echo "Path to src: $(SOURCEDIRS)"
	@echo "Sources : $(SOURCES)"
	@echo "OBJS : $(OBJS)"
	$(HIDE)echo Linking $@
	$(HIDE)$(CC) $(OBJS) $(LDFLAGS) -o $(TARGET) 

#Include dependencies
-include $(DEPS)

#Generate rules
$(foreach targetdir, $(TARGETDIRS), $(eval $(call generateRules, $(targetdir))))

directories:
	$(HIDE)$(MKDIR) $(subst /,$(PSEP),$(TARGETDIRS)) $(ERRIGNORE)

Grammaire: $(GRAMMARFILE)
	$(ANTLR) -visitor -no-listener -Dlanguage=Cpp $<
	@echo "Do not delete this file" > Grammaire

#Remove all objects, dependencies and executable files generated during the build
clean:
	$(HIDE)$(RMDIR) $(subst /,$(PSEP),$(TARGETDIRS)) $(ERRIGNORE)
	$(HIDE)$(RM) $(TARGET) $(ERRIGNORE)
	@echo Cleaning done !