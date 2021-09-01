#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "read_text_file.h"

int main(){
    char lectura[1500];
    char *total = NULL;
    char *libre = NULL;
    char *disponible = NULL;
    char *swapTotal = NULL;
    char *swapLibre = NULL;
    
    read("/proc/meminfo", 1500, lectura);

    total = strtok(lectura, "\n");
    libre = strtok(NULL, "\n");
    disponible = strtok(NULL, "\n");
    while(1){
        swapTotal = strtok(NULL, "\n");
        if (strncmp(swapTotal, "SwapT", 5) == 0){
            break;
        }
    }
    swapLibre = strtok(NULL, "\n");

    total = strtok(total, ":");
    total = strtok(NULL, " ");
    libre = strtok(libre, ":");
    libre = strtok(NULL, " ");
    disponible = strtok(disponible, ":");
    disponible = strtok(NULL, " ");
    swapTotal = strtok(swapTotal, ":");
    swapTotal = strtok(NULL, " ");
    swapLibre = strtok(swapLibre, ":");
    swapLibre = strtok(NULL, " ");

   
    int totalNum = atoi(total)/1000;
    int disponibleNum = atoi(disponible)/1000;
    int libreNum = atoi(libre)/1000;
    int swapTotalNum = atoi(libre)/1000;
    int swapLibreNum = atoi(libre)/1000;
    int swapOcupada = swapTotalNum - swapLibreNum;

    printf("El estado de la Memoria RAM de la computadora es el siguiente:\n");
    printf("Total: %i MB\n", totalNum);
    printf("Libre: %i MB\n", libreNum);
    printf("Disponible: %i MB\n", disponibleNum);

    printf("La memoria swap ocupada es: %i MB\n", swapOcupada);

    printf("\n");
    return 0;
}