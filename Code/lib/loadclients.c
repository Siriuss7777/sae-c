#include <stdio.h>
#include <string.h>

#include "./headers/loadclients.h"
#include "./headers/menu.h"
#include "./headers/utils.h"

void loadClients(Client *list, char* path) // Bastien
{
    char line[LONG_LONG_CHAR],
        copy[LONG_LONG_CHAR],
        *token;

    FILE *file = fopen(path, "r");
    int clientCount = 0;

    while (fgets(line, LONG_LONG_CHAR, file) != NULL)
    {
        strcpy(copy, line);

        char *ptr = line;
        int count = 0;
        while ((token = strsep(&ptr, ",")) != NULL)
        {
            switch (count)
            {
            case 0:
                strcpy(list[clientCount].prenom, token);
                // printf("client #%d: %s | ", clientCount, list[clientCount].prenom);
                break;

            case 1:
                strcpy(list[clientCount].nom, token);
                // printf("%s | ", list[clientCount].nom);
                break;

            case 2:
                strcpy(list[clientCount].ville, token);
                // printf("%s | ", list[clientCount].ville);
                break;

            case 3:
                strcpy(list[clientCount].code_postal, token);
                // printf("%s | ", list[clientCount].code_postal);
                break;

            case 4:
                strcpy(list[clientCount].tel, token);
                // printf("%s | ", list[clientCount].tel);
                break;

            case 5:
                strcpy(list[clientCount].mail, token);
                // printf("%s | ", list[clientCount].mail);
                break;

            case 6:
                strcpy(list[clientCount].job, token);
                // printf("%s\n", list[clientCount].job);
                break;
            default:
                printf("ERREUR");
                break;
            }
            count++;
        }
        clientCount++;
    }
}
