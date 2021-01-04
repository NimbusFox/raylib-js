debug: dependencies
	../../node_modules/.bin/tsc -p ./tsconfig.debug.json

release: dependencies ts_release
	
examples: ts_release
	cd ../WebAssembly && emmake make examples MODULE=TRUE

ts_release:
	../../node_modules/.bin/tsc -p ./tsconfig.release.json

dependencies:
	cd ../WebAssembly && emmake make build MODULE=TRUE
