#include "infofs.h"

int read_filesystems(char *txt)
{
    char *ptr = NULL;
    cJSON *root, *mounted, *unmounted;
    char *out;
    int i = 0;
    int j = 0;
    char index[3];

    root = cJSON_CreateObject();
    cJSON_AddItemToObject(root, "Mounted fs", mounted = cJSON_CreateObject());
    cJSON_AddItemToObject(root, "Unmounted fs", unmounted = cJSON_CreateObject());

    ptr = strtok(txt, "\n");
    if(strstr(ptr, "nodev"))
    {
        i++;
        sprintf(index, "%i", i);
        cJSON_AddStringToObject(unmounted, index, ptr+6);
    }
    else
    {
        j++;
        sprintf(index, "%i", j);
        cJSON_AddStringToObject(mounted, index, ptr+1);
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
                cJSON_AddStringToObject(unmounted, index, ptr+6);
            }
            else
            {
                j++;
                sprintf(index, "%i", j);
                cJSON_AddStringToObject(mounted, index, ptr+1);
            }
        }
    }while(ptr != NULL);

    out = cJSON_Print(root);
    printf("%s\n", out);
    cJSON_Delete(root);
    free(out);

    printf("\n");
    return 0;
}