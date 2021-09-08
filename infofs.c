#include "infofs.h"
#include <stdio.h>

int read_filesystems()
{
    char fs_txt[800];
    char *ptr = NULL;
    cJSON *root, *mounted, *unmounted;
    char *out;
    int i = 0;
    int j = 0;
    char index[3];

    root = cJSON_CreateObject();
    cJSON_AddItemToObject(root, "Mounted fs", mounted = cJSON_CreateObject());
    cJSON_AddItemToObject(root, "Unmounted fs", unmounted = cJSON_CreateObject());

    system("cat /proc/filesystems > aux.txt");
    read("aux.txt", 800, fs_txt);

    ptr = strtok(fs_txt, "\n");
    if(strstr(ptr, "nodev"))
    {
        i++;
        sprintf(index, "%i", i);
        cJSON_AddStringToObject(unmounted, index, ptr);
    }
    else
    {
        j++;
        sprintf(index, "%i", j);
        cJSON_AddStringToObject(mounted, index, ptr);
    }

    do
    {
        ptr = strtok(NULL, "\n");
        if(ptr != NULL)
        {
            if(strstr(ptr, "nodev"))
            {
                i++;
                sprintf(index, "%i", i);
                cJSON_AddStringToObject(unmounted, index, ptr);
            }
            else
            {
                j++;
                sprintf(index, "%i", j);
                cJSON_AddStringToObject(mounted, index, ptr);
            }
        }
    }while(ptr != NULL);

    out = cJSON_Print(root);
    printf("%s", out);
    cJSON_Delete(root);
    free(out);

    printf("\n");
    return 0;
}
