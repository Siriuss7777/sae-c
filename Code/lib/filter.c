#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./headers/menu.h"
#include "./headers/utils.h"
#include "./headers/filter.h"

void filter(Client *list, int lines) // Hédi
{
    int gOption,
        option;
    char *recherche = (char *)malloc(LONG_CHAR),
         *champ;                     //
    printf("\nType de filtre: \n");  //
    printf("\t1: Valeur exacte \n"); //
    printf("\t2: Valeur commencant par la saisie \n");

    scanf("%d", &gOption);
    if (gOption == 1)
    {
        printf("\nFiltrer par: \n"); //
        printf("\t1: Pr\202nom \n"); //
        printf("\t2: Nom \n");       //
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
            free(recherche);
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
            free(recherche);

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
            free(recherche);

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
            free(recherche);
            break;

        default:
            filter(list, lines);
            break;
        }
    }

    if (gOption == 2)

    {
        printf("\nFiltrer par: \n"); //
        printf("\t1: Pr\202nom \n"); //
        printf("\t2: Nom \n");       //
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
                if (strncmp(recherche, champ, strlen(recherche)) == 0) //
                {
                    displayClient(list, i, 1);
                }
            }
            free(recherche);
            break;

        case 2:
            for (int i = 0; i < lines; i++)
            {
                champ = strtolower(list[i].nom);
                if (strncmp(recherche, champ, strlen(recherche)) == 0) //
                {
                    displayClient(list, i, 1);
                }
            }
            free(recherche);

            break;
        case 3:
            for (int i = 0; i < lines; i++)
            {
                champ = strtolower(list[i].ville);
                if (strncmp(recherche, champ, strlen(recherche)) == 0) //
                {
                    displayClient(list, i, 1);
                }
            }
            free(recherche);

            break;

        case 4:
            for (int i = 0; i < lines; i++)
            {
                champ = strtolower(list[i].job);
                recherche[strlen(recherche)] = '\n';
                if (strncmp(recherche, champ, strlen(recherche)) == 0) //
                {
                    displayClient(list, i, 1);
                }
            }
            free(recherche);

            break;

        default:
            filter(list, lines);
            break;
        }
    }
}