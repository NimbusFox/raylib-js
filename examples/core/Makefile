
OBJS = ../../src/structs.o ../../src/core.o ../../src/shapes.o ../../src/textures.o ../../src/text.o ../../src/models.o ../../src/shaders.o ../../src/raylibWeb.o

all: basicWindow

basicWindow:
	em++ --source-map-base /core/ --emit-symbol-map --bind -g4 --no-entry -s USE_GLFW=3 -I../../raylib/src -I../../include --pre-js BasicWindow/src.js -o BasicWindow.html -L../../raylib/src/ -lraylib --shell-file=../../raylib/src/shell.html $(OBJS)
