ifdef MODULE
	M = -s MODULARIZE=1 -s 'EXPORT_NAME="raylib"' 
endif

ifdef ASSETS
	assets = --preload-file=$(ASSETS)@/ 
endif

#"borrowed" from raylib make file
# Determine PLATFORM_OS in case PLATFORM_DESKTOP selected
ifeq ($(PLATFORM),PLATFORM_DESKTOP)
    # No uname.exe on MinGW!, but OS=Windows_NT on Windows!
    # ifeq ($(UNAME),Msys) -> Windows
    ifeq ($(OS),Windows_NT)
        PLATFORM_OS = WINDOWS
    else
        UNAMEOS = $(shell uname)
        ifeq ($(UNAMEOS),Linux)
            PLATFORM_OS = LINUX
        endif
        ifeq ($(UNAMEOS),FreeBSD)
            PLATFORM_OS = BSD
        endif
        ifeq ($(UNAMEOS),OpenBSD)
            PLATFORM_OS = BSD
        endif
        ifeq ($(UNAMEOS),NetBSD)
            PLATFORM_OS = BSD
        endif
        ifeq ($(UNAMEOS),DragonFly)
            PLATFORM_OS = BSD
        endif
        ifeq ($(UNAMEOS),Darwin)
            PLATFORM_OS = OSX
        endif
    endif
endif
ifeq ($(PLATFORM),PLATFORM_RPI)
    UNAMEOS = $(shell uname)
    ifeq ($(UNAMEOS),Linux)
        PLATFORM_OS = LINUX
    endif
endif
ifeq ($(PLATFORM),PLATFORM_DRM)
    UNAMEOS = $(shell uname)
    ifeq ($(UNAMEOS),Linux)
        PLATFORM_OS = LINUX
    endif
endif

OBJS = raylibWeb.o cacheDatabase.o structs.o core.o shapes.o textures.o text.o models.o shaders.o
ARGS = $(A)--pre-js settings.js --no-entry -s USE_GLFW=3 --bind 
CFLAGS = --bind --no-entry -s USE_GLFW=3
LINKS = -L../../raylib/src -lraylib
INCLUDES = -I../../raylib/src -I../../include

BUILD ?= RELEASE

ifeq ($(BUILD),RELEASE)
	CFLAGS += -Os
	ARGS += -Os -o ../../bin/raylib.js 
else
	CFLAGS += -g
	ARGS += -g4 --shell-file=../../raylib/src/shell.html -o ../../bin/raylib.html --source-map-base / --emit-symbol-map
endif

all: build static

build: $(OBJS) dependencies
	em++ $(M)$(ARGS) $(LINKS) $(OBJS)

static: $(OBJS) dependencies
	em++ -shared $(LINKS) $(OBJS) -o ../../bin/raylibweb.bc

examples: $(OBJS) dependencies
	em++ $(M)$(ARGS) -s INITIAL_MEMORY=671088640 -fsanitize=address -s ALLOW_MEMORY_GROWTH=1 $(LINKS) $(OBJS)

dependencies:
	cd ../../raylib/src && emmake make PLATFORM=PLATFORM_WEB
	mkdir -p ../../bin

cacheDatabase.o: cacheDatabase.cpp
	em++ -c $< $(CFLAGS) $(INCLUDES)

raylibWeb.o: raylibWeb.cpp
	em++ -c $< $(CFLAGS) $(INCLUDES)
	
structs.o: structs.cpp
	em++ -c $< $(CFLAGS) $(INCLUDES)

core.o: core.cpp
	em++ -c $< $(CFLAGS) $(INCLUDES)

shapes.o: shapes.cpp
	em++ -c $< $(CFLAGS) $(INCLUDES)

textures.o: textures.cpp
	em++ -c $< $(CFLAGS) $(INCLUDES)

text.o: text.cpp
	em++ -c $< $(CFLAGS) $(INCLUDES)

models.o: models.cpp
	em++ -c $< $(CFLAGS) $(INCLUDES)

shaders.o: shaders.cpp
	em++ -c $< $(CFLAGS) $(INCLUDES)

clean:
ifeq ($(PLATFORM_OS),WINDOWS)
	del *.o /s
	del /Q /S ../bin
else
	rm -fv *.o 
	rm -rfv ../bin
endif
