debug: copyDefinitions
	tsc -p ./tsconfig.debug.json

release: copyDefinitions
	tsc -p ./tsconfig.release.json
	./node_modules/.bin/browserify ../../bin/js/raylibWeb.js -o ../../bin/raylibWeb.js

copyDefinitions:
	cp -r ./definitions/*.d.ts ../../bin/typescript
