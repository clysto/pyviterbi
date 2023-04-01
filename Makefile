CC = gcc
OBJECTS = src/viterbi.o
CFLAGS = -c -I include

all: $(OBJECTS) codegen/build/libviterbi_decode.a
	gcc -fPIC -shared $(OBJECTS) codegen/build/libviterbi_decode.a -o py/libviterbi.so

codegen/build/libviterbi_decode.a:
	cd codegen;  \
	mkdir build; \
	cd build;    \
	cmake ..;    \
	make;