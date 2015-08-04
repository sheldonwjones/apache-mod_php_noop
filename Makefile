##
##  Makefile for the php_noop Apache module
##

all: activate clean

# build mod_php_noop.so
build:
	apxs -c mod_php_noop.c

# Install mod_php_noop.so
install:
	apxs -i -c mod_php_noop.c

# Activate php_noop_module in httpd.conf
activate:
	apxs -a -i -c mod_php_noop.c

# cleanup
clean:
	-rm -rf mod_php_noop.o mod_php_noop.lo mod_php_noop.slo mod_php_noop.la .libs
