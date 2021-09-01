default:
		gcc $(CFLAGS) -Wall -Werror -Pedantic

main: main.c
		gcc $(CFLAGS) -Wall -Werror -pedantic main.c -o main
		$(MAKE) -C labs 
clean:
		rm -f *.o main
		$(MAKE) -C labs clean