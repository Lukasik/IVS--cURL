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

test: testCurl testParity
	@rm -f fit vut wget_vut wget_fit

testCurl: xvokra00
	@./xvokra00 www.fit.vut.br.cz fit www.vutbr.cz vut > /dev/null
	@wget www.fit.vut.br.cz -O wget_fit -q
	@wget www.vutbr.cz -O wget_vut -q

	@[ "`md5sum < wget_fit`" = "`md5sum < fit`" ] && printf '%s\n' "Download OK" || printf '%s\n' "Download FAILED"
	@[ "`md5sum < wget_vut`" = "`md5sum < vut`" ] && printf '%s\n' "Download OK" || printf '%s\n' "Download FAILED"

testParity: xvokra00
	@[ `./xvokra00 fit` = "1" ] && printf '%s\n' "Parity OK" || printf '%s\n' "Parity FAILED"
	@[ `./xvokra00 vut` = "0" ] && printf '%s\n' "Parity OK" || printf '%s\n' "Parity FAILED"