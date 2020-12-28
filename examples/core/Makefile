
OBJS = ../../src/WebAssembly/structs.o ../../src/WebAssembly/core.o ../../src/WebAssembly/shapes.o ../../src/WebAssembly/textures.o ../../src/WebAssembly/text.o ../../src/WebAssembly/models.o ../../src/WebAssembly/shaders.o ../../src/WebAssembly/raylibWeb.o

ARGS = -s INITIAL_MEMORY=671088640 -fsanitize=address -s ALLOW_MEMORY_GROWTH=1 --source-map-base /example/core/ --emit-symbol-map --bind -g4 --no-entry -s USE_GLFW=3 -I../../raylib/src -I../../include -L../../raylib/src/ -lraylib --shell-file=../../raylib/src/shell.html $(OBJS)

all: basicWindow

basicWindow:
	em++ --pre-js BasicWindow/src.js -o BasicWindow.html $(ARGS)
