#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <dlfcn.h>
#include "cJSON.h"
#include "labs/read_text_file.h"

void imprimirJSON(cJSON *obj);
char* busca_palabras(char* str, char* separator, int n);

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
            break;
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

            ptr = busca_palabras(marca, " ", 5);
            marca = ptr;
            ptr = strtok(NULL, " ");
            char *modelo = ptr;
            ptr = strtok(NULL, " ");
            strcat(modelo, ptr);
            ptr = strtok(NULL, " ");
            ptr = strtok(NULL, " ");
            ptr = strtok(NULL, " ");
            char *frec = ptr;

            ptr = busca_palabras(cores_cpu, " ", 7);
            int c_cpu = atoi(ptr);

            ptr = busca_palabras(threads_core, " ", 7);
            int t_core = atoi(ptr);

            ptr = busca_palabras(mem_txt, "\n", 1);
            char *total = ptr;
            ptr = strtok(NULL, "\n");
            char *libre = ptr;
            ptr = strtok(NULL, "\n");
            char *disp = ptr;

            total = busca_palabras(total, " ", 1);
            libre = busca_palabras(libre, " ", 1);
            disp = busca_palabras(disp, " ", 1);
            
            cJSON *root, *cpu, *ram;
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
            
            imprimirJSON(root);
            cJSON_Delete(root);
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
            root = cJSON_CreateObject();
            cJSON_AddItemToObject(root, "palabras", palabras = cJSON_CreateObject());

            int i = 0;
            char index[3];

            char *ptr = busca_palabras(arr_txt, "\n", 1);

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

            imprimirJSON(root);
            cJSON_Delete(root);
        }
        else
        {
            system("./labs/arreglos 0");
        }
        printf("Se ejecuto el ejercicio 2 del lab2 por haberse ejecutado ./main -a\n");
    }

    if(d)
    {
        void *handle;
        int (*fptr)(char*);
        char fs_txt[800];

        read("/proc/filesystems", 800, fs_txt);
        
        handle = dlopen("./libinfofs.so", RTLD_LAZY);
        if (!handle) {
            fprintf(stderr, "%s\n", dlerror());
            exit(EXIT_FAILURE);
        }
        dlerror(); 

        *(void**)(&fptr) = dlsym(handle, "read_filesystems");
        (*fptr)(fs_txt);

        char *error = dlerror();
        if (error != NULL) {
            fprintf(stderr, "%s\n", error);
            exit(EXIT_FAILURE);
        }
        dlclose(handle);

        printf("Opcion -d. Vimos los filesystems soportados y si estan montados en algun dispositivo o no.\n");
    }
    printf("\n");

    return 0;
}

void imprimirJSON(cJSON *obj)
{
    char *out;
    out = cJSON_Print(obj);
    printf("\n%s\n", out);
    free(out);

    printf("Los resultados se mostraron en formato json por opcion -j\n");
}

char* busca_palabras(char* str, char* separator, int n)
{
    char *ptr = strtok(str, separator);
    for(int i=0; i<n; i++) 
    {
        ptr = strtok(NULL, separator);
    }
    return ptr;
}