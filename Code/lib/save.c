#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "./headers/utils.h"
#include "./headers/menu.h"
#include "./headers/save.h"

void save(Client *list, int lines, char *path)
{

    printf("%s", path);
    FILE *file = fopen(path, "w");

    for (int i = 0; i < lines; i++)
    {
        fprintf(file, "%s,%s,%s,%s,%s,%s,%s",
                list[i].prenom,
                list[i].nom,
                list[i].ville,
                list[i].code_postal,
                list[i].tel,
                list[i].mail,
                list[i].job);
    }
    fclose(file);
    printf("\nSauvegarde réussie\n");
}