CC = gcc
OBJECTS = src/viterbi.o
CFLAGS = -c -Iinclude

.PHONY: clean

all: $(OBJECTS) codegen/build/libviterbi_decode.a
	gcc -fPIC -shared $(OBJECTS) codegen/build/libviterbi_decode.a -o python/libviterbi.so

codegen/build/libviterbi_decode.a:
	cd codegen;  \
	mkdir build; \
	cd build;    \
	cmake ..;    \
	make;

clean:
	rm -rf codegen/build python/libviterbi.so example $(OBJECTS)

example: codegen/build/libviterbi_decode.a src/example.c
	gcc -Iinclude -o example codegen/build/libviterbi_decode.a src/example.c src/viterbi.c
