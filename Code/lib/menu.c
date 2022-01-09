#include <stdio.h>
#include <string.h>

#include "./headers/menu.h"
#include "./headers/save.h"
#include "./headers/utils.h"
#include "./headers/addclient.h"
#include "./headers/loadclients.h"
#include "./headers/displayallclients.h"
#include "./headers/displayemptyclients.h"

void editClient() {}

void deleteClient() {}

void Filter() {}

void Search() {}

void Menu(Client *list, int lines, char *path) // Hédi
{
    int choix;
    do
    {
        printf("Que voulez vous faire :\n");
        printf("\t1: Ajouter un client \n");
        printf("\t2: Modifier un client \n");
        printf("\t3: Supprimer un client \n");
        printf("\t4: Afficher tous les clients\n");
        printf("\t5: Afficher les clients avec un filtre\n");
        printf("\t6: Chercher un client\n");
        printf("\t7: Afficher tous les clients ayant au moins une donn\202e manquante\n");
        printf("\t8: Sauvegarder\n");
        scanf("%d", &choix); // ------------------ CHANGER SAISIE

        switch (choix)
        {
        case 1:
            list = addClient(list, &lines);
            break;
        case 2:
            editClient();
            break;
        case 3:
            deleteClient();
            break;
        case 4:
            displayAllClients(list, lines);
            break;
        case 5:
            Filter();
            break;
        case 6:
            Search();
            break;
        case 7:
            displayEmptyClients(list, lines);
            break;
        case 8:
            save(list, lines, path);
            break;

        default:
            Menu(list, lines, path);
            break;
        }
    } while (choix != 9);
}