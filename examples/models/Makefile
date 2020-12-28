
OBJS = ../../src/structs.o ../../src/core.o ../../src/shapes.o ../../src/textures.o ../../src/text.o ../../src/models.o ../../src/shaders.o ../../src/raylibWeb.o

all: meshGeneration

meshGeneration:
	em++ -s ALLOW_MEMORY_GROWTH=1 --source-map-base /models/ --emit-symbol-map --bind -g4 --no-entry -s USE_GLFW=3 -I../../raylib/src -I../../include --pre-js MeshGeneration/src.js -o MeshGeneration.html -L../../raylib/src/ -lraylib --shell-file=../../raylib/src/shell.html $(OBJS)
