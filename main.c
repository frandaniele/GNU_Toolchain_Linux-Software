#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>

int main(int argc, char **argv)
{
    int next_option;
    int s = 0;
    int a = 0;
    int j = 0;
    
    const char* const short_options = "saj"; 

    const struct option long_options[] = {
    { "shell", 0, NULL, 's' },
    { "arrays", 0, NULL, 'a' },
    { "json", 0, NULL, 'j' },
    { NULL, 0, NULL, 0 } 
    };

    do
    {
        next_option = getopt_long(argc, argv, short_options, long_options, NULL);
        switch (next_option)
        {
        case 's': 
            s = 1;
            break;
        case 'a': 
            a = 1;
            break;
        case 'j': 
            j = 1;
            break;
        case '?': 
            return 1;
        case -1: 
            break;
        default: 
            printf("Unexpected error.\n");
            return 1;
        }
    }while (next_option != -1); 
    
    if(s)
    {
        if(j)
        {
            printf("Los resultados se mostraron en formato json por opcion -j\n");
        }
        else
        {
            system("./labs/cpuinfo");
            system("./labs/meminfo");
        }
        printf("Se ejecuto el ejercicio 1 del lab2 por haberse ejecutado ./main -s\n");
    }
    else if(a)
    {
        if(j)
        {
            printf("Los resultados se mostraron en formato json por opcion -j\n");
        }
        else
        {
            system("./labs/arreglos 0");
            system("./labs/arreglos 1");
        }
        printf("Se ejecuto el ejercicio 2 del lab2 por haberse ejecutado ./main -a\n");
    }
    else
    {
        printf("main: usage: ./main [-sj] [-aj].\n");
        return 1;
    }

    printf("\n");

    return 0;
}