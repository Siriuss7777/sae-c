#include <stdio.h>
#include <string.h>

#include "./headers/utils.h"
#include "./headers/menu.h"
#include "./headers/loadclients.h"
#include "./headers/addclient.h"
#include "./headers/displayallclients.h"


void editClient() {}

void deleteClient() {}

void Filter() {}

void Search() {}

void displayEmptyClients() {}

void Save() {}

void Menu(Client *list, int lines) // Hédi
{
    int choix,
        *lineCount = &lines;
    printf("Que voulez vous faire :\n");
    printf("\t1: Ajouter un client \n");
    printf("\t2: Modifier un client \n");
    printf("\t3: Supprimer un client \n");
    printf("\t4: Afficher tous les clients\n");
    printf("\t5: Afficher les clients avec un filtre\n");
    printf("\t6: Chercher un client avec une donnée\n");
    printf("\t7: Clients ayant une donnée manquante (au moins)\n");
    printf("\t8: Sauvegarder\n");
    scanf("%d", &choix); // ------------------ CHANGER SAISIE

    switch (choix)
    {
    case 1:
        addClient(list, lineCount);
        break;
    case 2:
        editClient();
        break;
    case 3:
        deleteClient();
        break;
    case 4:
        displayAllClients(list, *lineCount);
        break;
    case 5:
        Filter();
        break;
    case 6:
        Search();
        break;
    case 7:
        displayEmptyClients();
        break;
    case 8:
        Save();
        break;

    default:
        Menu(list, lines);
        break;
    }
}
