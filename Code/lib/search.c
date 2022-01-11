#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "./headers/sort.h"
#include "./headers/utils.h"
#include "./headers/search.h"

int search(Client *list, int lines)
{
    // mergeSort(0, lines - 1, list, lines);

    int option, start = 0,
                end = lines - 1;
    int mid = (start + end) / 2;

    char *toSearch = (char *)malloc(LONG_CHAR),
         *prenom,
         *nom;

    Client *sortedList = (Client *)malloc(lines * sizeof(Client)),
           *tempList = (Client *)malloc(lines * sizeof(Client));

    printf("Chercher avec: \n"
           "1: Nom/Pr\202nom \n"
           "2: Mail\n"
           "3: T\202l.\n");

    scanf("%d", &option);

    if (option != 1)
    {
        printf("Saisissez la valeur \205 rechercher: ");
        fflush(stdin);
        gets(toSearch);
    }
    switch (option)
    {

        // case 1:
        //     printf("Entrez le prénom a chercher :\n");
        //     gets(prenom);
        //     printf("Entrez le nom a chercher :\n");
        //     gets(nom);

        //     while (start < end)
        //     {
        //         mid = (start + end) / 2;
        //         mergeSort(0, lines, list, tempList, 0);

        //         if (strcmp(list[mid].prenom, prenom) == 0)
        //         {

        //             displayClient(list, mid, 1);
        //             return mid;
        //         }

        //         else if (strcmp(list[mid].prenom, prenom) < 0)
        //         {
        //             start = mid + 1;
        //         }

        //         else if (strcmp(list[mid].prenom, prenom) > 0)
        //         {
        //             end = mid;
        //         }
        //     }

        //     break;

    case 2:

        mergeSort(0, lines - 1, list, tempList, 6);

        while (start < end)
        {
            mid = (start + end) / 2;

            if (strcmp(list[mid].mail, toSearch) == 0)
            {
                displayClient(list, mid, 1);
                return mid;
            }

            else if (strcmp(list[mid].mail, toSearch) < 0)
            {
                start = mid + 1;
            }

            else if (strcmp(list[mid].mail, toSearch) > 0)
            {
                end = mid;
            }
        }

        break;

    case 3:

        mergeSort(0, lines - 1, list, tempList, 5);

        while (start < end)
        {

            mid = (start + end) / 2;

            if (strcmp(list[mid].tel, toSearch) == 0)
            {
                displayClient(list, mid, 1);
                return mid;
            }

            else if (strcmp(list[mid].tel, toSearch) < 0)
            {
                start = mid + 1;
            }

            else if (strcmp(list[mid].tel, toSearch) > 0)
            {
                end = mid;
            }
        }

        break;

    default:
        search(list, lines);
        break;
    }

    printf("\n%s introuvable. \n\n", toSearch);
}