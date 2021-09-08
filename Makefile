OFLAGS = -Wall -Werror -pedantic
RM = rm -f

all:	main

main: main.o libjson.a
		$(MAKE) libjson.a	libinfofs.so
		gcc $(CFLAGS) $(OFLAGS) -o main main.o -L. -ljson -ldl
		export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
		$(MAKE) -C labs 
		$(RM) *.o *.a

main.o: main.c
		gcc $(CFLAGS) $(OFLAGS) -c main.c

libjson.a:	cJSON.o
		$(MAKE) cJSON.o
		ar cr libjson.a cJSON.o

cJSON.o: cJSON.c cJSON.h
		gcc $(CFLAGS) $(OFLAGS) -fPIC -c cJSON.c

libinfofs.so:	infofs.o cJSON.o
		$(MAKE) cJSON.o
		gcc -shared -o libinfofs.so infofs.o cJSON.o 

infofs.o: infofs.c infofs.h
		gcc $(CFLAGS) $(OFLAGS) -fPIC -c infofs.c

clean:
		$(RM) *.o *.a *.so main
		$(MAKE) -C labs clean