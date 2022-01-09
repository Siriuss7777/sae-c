#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./headers/menu.h"
#include "./headers/utils.h"
#include "./headers/filter.h"

void filter(Client *list, int lines)
{
    int option;
    char *recherche = (char *)malloc(LONG_CHAR),
         *champ; //

    printf("\nFiltrer par: \n"); //
    printf("\t2: Pr\202nom \n"); //
    printf("\t1: Nom \n");       //
    printf("\t3: Ville \n");     //
    printf("\t4: M\202tier\n");  //

    scanf("%d", &option); //

    printf("\nEntrez la valeur \205 chercher (insensible \205 la casse): ");
    fflush(stdin);
    gets(recherche);
    recherche = strtolower(recherche);
    printf("%s", CAPTION);

    switch (option)
    {
    case 1:
        for (int i = 0; i < lines; i++)
        {
            champ = strtolower(list[i].prenom);
            if (strcmp(champ, recherche) == 0) //
            {
                displayClient(list, i, 1);
            }
        }
        break;

    case 2:
        for (int i = 0; i < lines; i++)
        {
            champ = strtolower(list[i].nom);
            if (strcmp(champ, recherche) == 0) //
            {
                displayClient(list, i, 1);
            }
        }

        break;
    case 3:
        for (int i = 0; i < lines; i++)
        {
            champ = strtolower(list[i].ville);
            if (strcmp(champ, recherche) == 0) //
            {
                displayClient(list, i, 1);
            }
        }

        break;

    case 4:
        for (int i = 0; i < lines; i++)
        {
            champ = strtolower(list[i].job);
            recherche[strlen(recherche)] = '\n';
            if (strcmp(champ, recherche) == 0) //
            {
                displayClient(list, i, 1);
            }
        }

        break;

    default:
        filter(list, lines);
        break;
    }
}