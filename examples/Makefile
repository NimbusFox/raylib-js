
all: core models

core: dependency
	cd core && emmake make

models: dependency
	cd models && emmake make

dependency:
	cd ../src && emmake make static BUILD=DEBUG
