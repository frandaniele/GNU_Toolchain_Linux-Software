OFLAGS = -Wall -Werror -pedantic

all:	main

main: main.o libjson.a
		$(MAKE) libjson.a	libinfofs.so
		gcc $(CFLAGS) $(OFLAGS) -o main main.o -L. -ljson -ldl
		$(MAKE) -C labs 
		rm -f *.o *.a

main.o: main.c
		gcc $(CFLAGS) $(OFLAGS) -c main.c

libjson.a:	cJSON.o
		$(MAKE) cJSON.o
		ar cr libjson.a cJSON.o

cJSON.o: cJSON.c cJSON.h
		gcc $(CFLAGS) $(OFLAGS) -fPIC -c cJSON.c

libinfofs.so:	infofs.o cJSON.o
		$(MAKE) cJSON.o
		gcc -shared -fPIC -o libinfofs.so infofs.o cJSON.o 

infofs.o: infofs.c
		gcc $(CFLAGS) $(OFLAGS) -fPIC -c infofs.c

clean:
		rm -f *.o *.a *.so main
		$(MAKE) -C labs clean