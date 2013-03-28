flags = -pedantic -std=c99 -Wextra -Wall

all: xvokra00

obj:
	gcc *.c -c $(flags)

xvokra00: obj
	gcc wget.o parity.o xvokra00.o error.o $(flags) -I../curl/include/ -L ../curl/lib/.libs/ -lcurl -o xvokra00

pack: clean
	tar -cf xvokra00.tar.gz *

clean:
	rm -fR  *.o xvokra00 doc

debug: flags = -pedantic -std=c99 -Wextra -Wall -g3
debug: xvokra00

doc:
	doxygen
	make -C doc