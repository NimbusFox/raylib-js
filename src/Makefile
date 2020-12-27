ifdef MODULE
	M = -s MODULARIZE=1 -s 'EXPORT_NAME="$(MODULE)"' 
endif

ifdef ASSETS
	A = --preload-file=$(ASSETS)@/ 
endif

FILES = core.cpp structs.cpp shapes.cpp textures.cpp text.cpp models.cpp
ARGS = $(A)--pre-js settings.js --no-entry -s USE_GLFW=3 --bind -I../raylib/src -I../include -L../raylib/src -lraylib

debug:
	cd ../raylib/src && emmake make PLATFORM=PLATFORM_WEB RAYLIB_BUILD_MODE=DEBUG
	mkdir -p ../bin
	em++ -g4 --shell-file=../raylib/src/shell.html -o ../bin/raylib.html --source-map-base / --emit-symbol-map $(M)$(ARGS) $(FILES)

release:
	cd ../raylib/src && emmake make PLATFORM=PLATFORM_WEB
	mkdir -p ../bin
	em++ -o ../bin/raylib.js -s SINGLE_FILE=1 -flto -O3 $(M)$(ARGS) $(FILES)
