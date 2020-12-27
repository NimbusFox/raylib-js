ifdef MODULE
	M = -s MODULARIZE=1 -s 'EXPORT_NAME="$(MODULE)"' 
endif

ifdef ASSETS
	A = --preload-file=$(ASSETS)@/ 
endif

FILES = database/FontDatabase.cpp database/ImageDatabase.cpp core.cpp structs.cpp shapes.cpp textures.cpp
ARGS = $(A)--pre-js settings.js --no-entry -s USE_GLFW=3 --bind -I../raylib/src -I../include -L../raylib/src -lraylib

debug:
	cd ../raylib/src && emmake make PLATFORM=PLATFORM_WEB
	mkdir -p ../bin
	em++ --shell-file=../raylib/src/shell.html -o ../bin/raylib.html --source-map-base / --emit-symbol-map $(M)$(ARGS) $(FILES)

release:
	cd ../raylib/src && emmake make PLATFORM=PLATFORM_WEB
	mkdir -p ../bin
	em++ -o ../bin/raylib.js -s SINGLE_FILE=1 -flto -O3 $(M)$(ARGS) $(FILES)