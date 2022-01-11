#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./headers/menu.h"
#include "./headers/save.h"
#include "./headers/sort.h"
#include "./headers/edit.h"
#include "./headers/utils.h"
#include "./headers/filter.h"
#include "./headers/search.h"
#include "./headers/addclient.h"
#include "./headers/loadclients.h"
#include "./headers/displayallclients.h"
#include "./headers/displayemptyclients.h"

void editClient() {}

void deleteClient() {}

void Menu(Client *list, int lines, char *path) // Hédi
{
    int choice;
    do
    {
        printf("Que voulez vous faire :\n"
               "\t1: Ajouter un client \n"
               "\t2: Modifier un client \n"
               "\t3: Supprimer un client \n"
               "\t4: Afficher tous les clients\n"
               "\t5: Afficher les clients avec un filtre\n"
               "\t6: Rechercher un client\n"
               "\t7: Afficher tous les clients ayant au moins une donn\202e manquante\n"
               "\t8: Trier s\202mantiquement les clients\n"
               "\t9: Sauvegarder et quitter\n"
               "\t10: Quitter sans sauvegarder\n");
        scanf("%d", &choice); // ------------------ CHANGER SAISIE ^^

        int menuChoice;
        switch (choice)
        {
        case 1:
            list = addClient(list, &lines);
            break;
        case 2:
            edit(list, lines);
            break;
        case 3:
            deleteClient();
            break;
        case 4:
            displayAllClients(list, lines);
            break;
        case 5:
            filter(list, lines); // Tri par initiale
            break;
        case 6:
            search(list, lines);
            break;
        case 7:
            displayEmptyClients(list, lines);
            break;
        case 8:
            do
            {
                printf("Trier par:\n"
                       "\t1. Pr\202nom\n"
                       "\t2. Nom\n"
                       "\t3. Ville\n"
                       "\t4. Code postal\n"
                       "\t5. T\202l.\n"
                       "\t6. Mail\n"
                       "\t7. Travail\n\n");
                scanf("%d", &menuChoice);
            } while (menuChoice > 8 || menuChoice < 0);
            Client *tempList = (Client *)malloc(lines * sizeof(Client));

            mergeSort(0, lines - 1, list, tempList, menuChoice);
            free(tempList);
            displayAllClients(list, lines);
            break;
        case 9:
            save(list, lines, path); // Fix y'a rien ds fichier
            break;
            choice = 10;
        case 99:
            printf("debug :)");
            break;
        }
    } while (choice != 10);
}