#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>

#include "./lib/headers/utils.h"
#include "./lib/headers/loadclients.h"
#include "./lib/headers/menu.h"
#include "./lib/headers/addclient.h"
#include "./lib/headers/displayallclients.h"

int main()
{
    int lines = 0;
    char line[LONG_LONG_CHAR];

    char *path;
    FILE *file;
    do
    {
        printf("Entrez l'adresse du fichier a lire : \n");
        gets(path);
        file = fopen(path, "r");

    } while (file == NULL);


    while (fgets(line, sizeof(line), file) != NULL)
    {
        lines++;
    }
    fclose(file);

    Client *list = (Client*) malloc(sizeof(Client)*lines);
    loadClients(list, path);
    Menu(list, lines);
}
