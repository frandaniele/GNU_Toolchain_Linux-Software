#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include "cJSON.h"
#include "labs/read_text_file.h"

int main(int argc, char **argv)
{
    int next_option;
    int s = 0;
    int a = 0;
    int j = 0;
    int d = 0;
    
    const char* const short_options = "sajd"; 

    const struct option long_options[] = {
    { "shell", 0, NULL, 's' },
    { "arrays", 0, NULL, 'a' },
    { "json", 0, NULL, 'j' },
    { "dll", 0, NULL, 'd' },
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
        case 'd': 
            d = 1;
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
    
    if(!a && !s && !d)
    {
        if(j)
        {
            printf("Option -j must be used with -s or -a.\n");
        }
        else
        {
            printf("main: usage: ./main [-sj] [-aj] [-d].\n");
        }
        return 1;
    }
    if(s)
    {
        if(j)
        {
            system("./labs/cpuinfo > aux.txt");
            char cpu_txt[250];
            read("aux.txt", 250, cpu_txt);

            system("./labs/meminfo > aux.txt");
            char mem_txt[250];
            read("aux.txt", 250, mem_txt);

            system("rm aux.txt");

            char *ptr = NULL;
            ptr = strtok(cpu_txt, "\n");
            char *marca = ptr;
            ptr = strtok(NULL, "\n");
            char *cores_cpu = ptr;
            ptr = strtok(NULL, "\n");
            char *threads_core = ptr;

            ptr = strtok(marca, " ");
            for(int i=0; i<5; i++) 
            {
                ptr = strtok(NULL, " ");
            }
            marca = ptr;
            ptr = strtok(NULL, " ");
            char *modelo = ptr;
            ptr = strtok(NULL, " ");
            strcat(modelo, ptr);
            ptr = strtok(NULL, " ");
            ptr = strtok(NULL, " ");
            ptr = strtok(NULL, " ");
            char *frec = ptr;

            ptr = strtok(cores_cpu, " ");
            for(int i=0; i<7; i++) 
            {
                ptr = strtok(NULL, " ");
            }
            int c_cpu = atoi(ptr);

            ptr = strtok(threads_core, " ");
            for(int i=0; i<7; i++) 
            {
                ptr = strtok(NULL, " ");
            }
            int t_core = atoi(ptr);

            ptr = strtok(mem_txt, "\n");
            ptr = strtok(NULL, "\n");
            char *total = ptr;
            ptr = strtok(NULL, "\n");
            char *libre = ptr;
            ptr = strtok(NULL, "\n");
            char *disp = ptr;

            total = strtok(total, " ");
            total = strtok(NULL, " ");
            libre = strtok(libre, " ");
            libre = strtok(NULL, " ");
            disp = strtok(disp, " ");
            disp = strtok(NULL, " ");
            

            cJSON *root, *cpu, *ram;
            char *out;
            root = cJSON_CreateObject();
            cJSON_AddItemToObject(root, "CPU", cpu = cJSON_CreateObject());
            cJSON_AddStringToObject(cpu, "Fabricante", marca);
            cJSON_AddStringToObject(cpu, "Modelo", modelo);
            cJSON_AddStringToObject(cpu, "Frecuencia", frec);
            cJSON_AddNumberToObject(cpu, "Cores/CPU", c_cpu);
            cJSON_AddNumberToObject(cpu, "Threads/Core", t_core);
            cJSON_AddItemToObject(root, "RAM [MB]", ram = cJSON_CreateObject());
            cJSON_AddNumberToObject(ram, "Total", atoi(total));
            cJSON_AddNumberToObject(ram, "Libre", atoi(libre));
            cJSON_AddNumberToObject(ram, "Disponible", atoi(disp));
            out = cJSON_Print(root);
            printf("%s\n", out);
            cJSON_Delete(root);
            free(out);

            printf("Los resultados se mostraron en formato json por opcion -j\n");
        }
        else
        {
            system("./labs/cpuinfo");
            system("./labs/meminfo");
        }
        printf("Se ejecuto el ejercicio 1 del lab2 por haberse ejecutado ./main -s\n");
    }

    if(a)
    {
        if(j)
        {
            system("./labs/arreglos 0 > aux.txt");
            char arr_txt[180];
            read("aux.txt", 180, arr_txt);
            system("rm aux.txt");

            cJSON *root, *palabras;
            char *out;
            root = cJSON_CreateObject();
            cJSON_AddItemToObject(root, "palabras", palabras = cJSON_CreateObject());

            int i = 0;
            char index[3];

            char *ptr = NULL;
            ptr = strtok(arr_txt, "\n");
            ptr = strtok(NULL, "\n");

            ptr = strtok(ptr, " ");
            do
            {
                if(ptr != NULL)
                {
                    i++;
                    sprintf(index, "%i", i);
                    cJSON_AddStringToObject(palabras,index, ptr);
                    ptr = strtok(NULL, " ");
                } 
            }while(ptr != NULL);

            out = cJSON_Print(root);
            printf("\n%s\n", out);
            cJSON_Delete(root);
            free(out);

            printf("Los resultados se mostraron en formato json por opcion -j\n");
        }
        else
        {
            system("./labs/arreglos 0");
        }
        printf("Se ejecuto el ejercicio 2 del lab2 por haberse ejecutado ./main -a\n");
    }

    if(d)
    {
        printf("Option -d.\n");
    }

    printf("\n");

    return 0;
}