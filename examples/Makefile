ARGS = -s INITIAL_MEMORY=671088640 -fsanitize=address -s ALLOW_MEMORY_GROWTH=1 --emit-symbol-map --bind -g4 --no-entry -s USE_GLFW=3 -I../../raylib/src -I../../include -L../../raylib/src/ -lraylib --shell-file=../../raylib/src/shell.html ../../bin/raylibweb.bc

all: core models

core: dependency
	cd core && emmake make ARGS="--source-map-base /example/core/ $(ARGS)"

models: dependency
	cd models && emmake make ARGS="--source-map-base /example/models/ $(ARGS)"

dependency:
	cd ../src/WebAssembly && emmake make static BUILD=DEBUG
