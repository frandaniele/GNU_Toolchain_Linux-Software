OFLAGS = -Wall -Werror -pedantic

all:	main

main: main.o libjson.a
		$(MAKE) libjson.a
		gcc $(CFLAGS) $(OFLAGS) main.o -o main -L. -ljson
		$(MAKE) -C labs 

main.o: main.c
		gcc $(CFLAGS) $(OFLAGS) -c main.c

libjson.a:	cJSON.o
		$(MAKE) cJSON.o
		ar cr libjson.a cJSON.o

cJSON.o: cJSON.c cJSON.h
		gcc $(OFLAGS) -c cJSON.c

libinfofs.so:	infofs.o cJSON.o
		$(MAKE) cJSON.o
		gcc -shared -fPIC -o libinfofs.so infofs.o cJSON.o 

infofs.o: infofs.c
		gcc $(OFLAGS) -c infofs.c

clean:
		rm -f *.o *.a *.so main
		$(MAKE) -C labs clean