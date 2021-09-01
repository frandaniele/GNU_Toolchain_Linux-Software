#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "read_text_file.h"

int main(){
    char lectura[10000];
    char *modelo_cpu = NULL;
    char *cant_cores = NULL;
    char *cant_threads = NULL;
    
    read("/proc/cpuinfo", 10000, lectura);

    modelo_cpu = strtok(lectura, "\n");
    
    while(1)
    {
        modelo_cpu = strtok(NULL, "\n");
        if (strncmp(modelo_cpu,"model name",10) == 0){
            break;
        } 
    }

    while(1)
    {
        cant_threads = strtok(NULL, "\n");
        if (strncmp(cant_threads,"siblings",8) == 0){
            break;
        } 
    }

    while(1)
    {
        cant_cores = strtok(NULL, "\n");
        if (strncmp(cant_cores,"cpu cores",9) == 0){
            break;
        } 
    }

    modelo_cpu = strtok(modelo_cpu, ":");
    modelo_cpu = strtok(NULL, "\n");

    cant_cores = strtok(cant_cores,":");
    cant_cores = strtok(NULL, "\n");
    
    cant_threads = strtok(cant_threads,":");
    cant_threads = strtok(NULL, "\n");

    int cores_num = atoi(cant_cores);
    int threads_num = atoi(cant_threads)/cores_num;

    printf("El modelo de CPU es%s.\n", modelo_cpu);
    printf("La cantidad de cores por CPU es %i.\n", cores_num);
    printf("La cantidad de threads por cores es %i. Esto significa que el procesador soporta la tecnología HyperThreading.\n", threads_num);
    
    printf("\n");
    return 0;
}