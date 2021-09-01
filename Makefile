OFLAGS = -Wall -Werror -pedantic

all:	main

main: main.c
		$(MAKE) cjson
		gcc $(CFLAGS) $(OFLAGS) main.c -o main -L. -ljson
		$(MAKE) -C labs 

cjson:	cJSON.c cJSON.h
		gcc $(OFLAGS) -c cJSON.c
		ar cr libjson.a cJSON.o

clean:
		rm -f *.o *.a main 
		$(MAKE) -C labs clean