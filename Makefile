
CC        = gcc
INSTALLDIR= /usr/local/lib
INCLUDEDIR= /usr/local/include

.PHONY  : all

all : libisfunc.so
	@echo type: sudo make install  # to install
	@echo type: make test          # to test it's working

libisfunc.so: isfunc.c isfunc.h
	$(CC) -shared -fPIC isfunc.c -o libisfunc.so

clean:
	find . -perm +100 -type f -delete
	rm -f *.o *.so

install: libisfunc.so
	cp libisfunc.so $(INSTALLDIR)
	cp isfunc.h $(INCLUDEDIR)
	@echo type: make test          # to test it's working

test: isfunc-test libisfunc.so
	./isfunc-test

isfunc-test: isfunc-test.c libisfunc.so
	$(CC) isfunc-test.c -L. -o isfunc-test -lisfunc -Wl,-rpath=`pwd`

