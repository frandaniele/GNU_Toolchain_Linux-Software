#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>

int main(int argc, char **argv)
{
    int next_option;
    int s = 0;
    int a = 0;
    
    const char* const short_options = "sa"; 

    const struct option long_options[] = {
    { "ejuno", 0, NULL, 's' },
    { "ejdos", 0, NULL, 'a' },
    { NULL, 0, NULL, 0 } 
    };

    next_option = getopt_long(argc, argv, short_options, long_options, NULL);
    switch (next_option)
    {
    case 's': 
        s = 1;
        break;
    case 'a': 
        a = 1;
        break;
    case '?': 
        return 1;
    case -1: 
        printf("Usage: ./main -s or ./main -a.\n");
        return 1;
    default: 
        printf("Unexpected error.\n");
        return 1;
    }
    
    if(s)
    {
        system("./labs/cpuinfo");
        system("./labs/meminfo");
        printf("Se ejecuto el ejercicio 1 del laboratorio 2 por haberse ejecutado el programa con opcion -s\n");
    }
    else if(a)
    {
        system("./labs/arreglos 0");
        system("./labs/arreglos 1");
        printf("Se ejecuto el ejercicio 1 del laboratorio 2 por haberse ejecutado el programa con opcion -a\n");
    }
    else
    {
        printf("Unexpected error.\n");
        return 1;
    }

    printf("\n");

    return 0;
}