default:
		gcc $(CFLAGS) -Wall -Werror -Pedantic

main: 
		gcc $(CFLAGS) -Wall -Werror -pedantic main.c -o main

clean:
		rm -f *.o main