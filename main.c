#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    if(argc != 2){
        printf("Usage: ./main -s or ./main -a.\n");
        return 1;
    }

    if(strlen(argv[1]) != 2){
        printf("Flag's format: '-x'.\n");
        return 1;
    }
    
    char flags[2] = {'a', 's'};
    char flag = argv[1][1];

    int i;
    for(i = 0; i < 2; i++) 
    {
        if(flag == flags[i]) 
        {
            i = 5;
            break;
        }
    }

    if(i != 5)
    {
        printf("%c: not a valid flag.\n", flag);
        return 1;
    }

    if(flag == 'a')
    {
        printf("Estoy haciendo cualquiera.\n");
        //system("cd ../");
    }
    else if(flag == 's')
    {
        printf("Me trabe.\n");
    }
    else
    {
        printf("Unexpected error.\n");
        return 1;
    }

    printf("\n");

    return 0;
}