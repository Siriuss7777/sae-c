#include <stdio.h>
#include <stdlib.h>

#include "./headers/utils.h"
#include "./headers/search.h"

void deleteClient(Client *list, int *lines) // Bastien
{
    int position;
    position = clientSearch(list, *lines, "Chercher le client \205 supprimer par: ", 0);

    printf("Le client suivant va etre supprim\202: \n");
    displayClient(list, position, 0);
    printf("Confirmer? (o/n)\n");
    char input = getc(stdin); // A CHANGER AUSSI ^^
    if (input == 'n')
    {
        deleteClient(list, lines);
    }
    else
    {
        for (int i = position; i < *lines - 1; i++)
        {
            list[i] = list[i + 1];
        }
        *lines = *lines - 1;
        list = (Client *)realloc(list, sizeof(Client) * (unsigned long long)(lines - 1));
    }
}