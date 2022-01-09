#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "./headers/menu.h"
#include "./headers/utils.h"
#include "./headers/addclient.h"
#include "./headers/displayallclients.h"

void displayEmptyClients(Client *list, int lines)
{
    printf("\n%s", CAPTION);
    for (int i = 0; i < lines; i++)
    {
        if (*list[i].prenom == '\0' ||
            *list[i].nom == '\0' ||
            *list[i].ville == '\0' ||
            *list[i].code_postal == '\0' ||
            *list[i].tel == '\0' ||
            *list[i].mail == '\0' ||
            *list[i].job == '\n')
        {
            displayClient(list, i, 2);
        }
    }
    printf("\n");
}