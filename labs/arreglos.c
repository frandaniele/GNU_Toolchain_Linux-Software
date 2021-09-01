#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#include "read_text_file.h"
#include "arreglos.h"

int main(int argc, char *argv[]){
    int operacion = atoi(argv[1]); 

    assert((operacion == 0 || operacion == 1) && "modo de uso: ./arreglos 0 o 1" );

    char lectura[500];

    read("/proc/version", 500, lectura);

    if(operacion)
    {
        arreglo_ch_a_ch(lectura);
    }
    else
    {
        arreglo_2d(lectura);
    }

    printf("\n");

    return 0;
}

int arreglo_ch_a_ch(char *lectura)
{
    char *token = NULL;
    char *c;
    c = (char *) malloc(sizeof(char));
    int i = 0;
    int j = 0;
    int imprime = 0;

    token = strtok(lectura, " ");
    
    while(token[i])
    {
        if(isalpha(token[i]))
        {
            imprime = 1;
            c = (char *) realloc(c, (1 + strlen(c)) * sizeof(char));
            c[j] = toupper(token[i]);
            j++;
        }
        i++;
    }

    i = 0;
    if(imprime)
    {
        c = (char *) realloc(c, (1 + strlen(c)) * sizeof(char));
        c[j] = ' ';
        j++;
        imprime = 0;
    }
    while(token != NULL)
    {
        token = strtok(NULL, " ");
        if(token != NULL)
        {
            while(token[i])
            {
                if(isalpha(token[i]))
                {
                    imprime = 1;
                    c = (char *) realloc(c, (1 + strlen(c)) * sizeof(char));
                    c[j] = toupper(token[i]);
                    j++;
                }
                i++;
            }
            
            i = 0;
            if(imprime)
            {
                c = (char *) realloc(c, (1 + strlen(c)) * sizeof(char));
                c[j] = ' ';
                j++;
                imprime = 0;
            }
        }
    }

    printf("Palabras de /proc/version en mayúsculas (agregando char por char):\n%s\n", c);

    free(c);
    c = NULL;

    return 0;
}

int arreglo_2d(char *lectura)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *token = NULL;
    int imprime = 0;
    char **c = (char **) malloc(sizeof(*c));;
    c[i] = (char *) malloc(sizeof(char));
    
    token = strtok(lectura, " ");

    while(token[k])
    {
        if(isalpha(token[k]))
        {
            imprime = 1;
            c[i] = (char *) realloc(c[i], (1 + strlen(c[i])) * sizeof(char));
            c[i][j] = toupper(token[k]);
            j++;
        }
        k++;
    }
    k = 0;
    j = 0;

    if(imprime)
    {
        i++;
        c[i] = (char *) malloc(sizeof(char));
        imprime = 0;
    }

    while(token != NULL)
    {
        token = strtok(NULL, " ");

        if(token != NULL)
        {
            while(token[k])
            {
                if(isalpha(token[k]))
                {
                    imprime = 1;
                    c[i] = (char *) realloc(c[i], (1 + strlen(c[i])) * sizeof(char));
                    c[i][j] = toupper(token[k]);
                    j++;
                }
                k++;
            }
            k = 0;
            j = 0;

            if(imprime)
            {
                c = (char **) realloc(c, (1 + i) * sizeof(*c) + 1);
                i++;
                c[i] = (char *) malloc(sizeof(char));
                imprime = 0;
            }
        }
    }

    printf("Palabras de /proc/version en mayúsculas (usando array 2d):\n");
    
    for(k = 0; k<i; k++)
    {
        printf("%s ", c[k]);
        free(c[k]);
        c[k] = NULL;
    }
    printf("\n");

    free(c);
    c = NULL;


    return 0;
}