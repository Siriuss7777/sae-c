#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "./lib/headers/menu.h"
#include "./lib/headers/utils.h"
#include "./lib/headers/addclient.h"
#include "./lib/headers/loadclients.h"
#include "./lib/headers/displayallclients.h"

int main()
{
    int lines = 0;
    char line[LONG_LONG_CHAR],
        *path;
    FILE *file;

    do
    {
        printf("Entrez l'adresse du fichier a lire : \n"); // Hédi
        gets(path);                                        // Hédi
        file = fopen(path, "r");                           // Hédi

    } while (file == NULL);

    while (fgets(line, sizeof(line), file) != NULL)
    {
        lines++;
    }
    fclose(file);

    Client *list = (Client *)malloc(sizeof(Client) * (lines + 1));
    clock_t begin = clock();
    loadClients(list, path);
    clock_t end = clock();
    printf("Temps de chargement: %ldms\n", (end - begin) * 1000 / CLOCKS_PER_SEC);
    Menu(list, lines, path);
}
