#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "./headers/sort.h"
#include "./headers/utils.h"
#include "./headers/search.h"

int clientSearch(Client *list, int lines, char *text, int dispClient) // Hédi
{
    int option,
        result;

    printf("%s \n"
           "1: Nom/Pr\202nom \n"
           "2: Mail\n"
           "3: T\202l.\n",
           text);

    scanf("%d", &option);
    result = search(list, lines, option, dispClient);
    return result;
}

int search(Client *list, int lines, int option, int dispClient) // Hédi
{
    // mergeSort(0, lines - 1, list, lines);

    int start = 0,
        end = lines - 1,
        namesCounter;
    int mid = (start + end) / 2;

    char *toSearch = (char *)malloc(LONG_CHAR),
         *prenom = (char *)malloc(LONG_CHAR),
         *nom = (char *)malloc(LONG_CHAR),
         *champ;

    Client *sortedList = (Client *)malloc(lines * sizeof(Client)),
           *tempList = (Client *)malloc(lines * sizeof(Client)),
           *namesList = (Client *)malloc(lines * sizeof(Client));

    if (option != 1)
    {
        printf("Saisissez la valeur \205 rechercher: ");
        fflush(stdin);
        gets(toSearch);
    }
    switch (option)
    {
    case 1:
        printf("Recherche non fonctionnelle");
        break;
        //     printf("Entrez le pr\202nom \205 chercher :\n");
        //     fflush(stdin);
        //     gets(prenom);
        //     prenom = strtolower(prenom);
        //     printf("Entrez le nom \205 chercher :\n");
        //     fflush(stdin);
        //     gets(nom);
        //     nom = strtolower(nom);

        //     for (int i = 0; i < lines - 1; i++)
        //     {
        //         champ = strtolower(list[i].prenom);
        //         if (strcmp(champ, prenom) == 0) //
        //         {
        //             namesList[namesCounter] = list[i];
        //             namesCounter++;
        //             printf("ajoute:");
        //             displayClient(namesList, namesCounter, 0);
        //         }
        //     }

        //     while (start < namesCounter)
        //     {
        //         mid = (start + namesCounter) / 2;
        //         mergeSort(0, namesCounter, namesList, tempList, 0);

        //         if (strcmp(namesList[mid].nom, nom) == 0)
        //         {

        //             displayClient(list, mid, 1);
        //             free(toSearch);
        //             free(tempList);
        //             free(sortedList);
        //             free(namesList);
        //             free(prenom);
        //             free(nom);
        //             return mid;
        //         }

        //         else if (strcmp(list[mid].nom, nom) < 0)
        //         {
        //             start = mid + 1;
        //         }

        //         else if (strcmp(list[mid].nom, nom) > 0)
        //         {
        //             namesCounter = mid;
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
                if (dispClient)
                {
                    displayClient(list, mid, 1);
                    printf("\n");
                }
                free(toSearch);
                free(tempList);
                free(sortedList);
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
                if (dispClient)
                {
                    displayClient(list, mid, 1);
                    printf("\n");
                }
                free(toSearch);
                free(tempList);
                free(sortedList);
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
        search(list, lines, option, dispClient);
        break;
    }

    printf("\n%s introuvable. \n\n", toSearch);
}