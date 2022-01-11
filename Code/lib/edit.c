#include <stdio.h>

#include "./headers/edit.h"
#include "./headers/utils.h"
#include "./headers/search.h"

void edit(Client *list, int lines)
{

    int choix,
        position;
    char *reponse;

    position = search(list, lines);

    do
    {
        printf("Saisissez: \n"
               "\t1: Pr\202nom \n"
               "\t2: Nom \n"
               "\t3: Ville \n"
               "\t4: Code postal \n"
               "\t5: Num\202ro de t\202l\202phone \n"
               "\t6: Mail \n"
               "\t7: M\202tier\n"
               "\t8: Quitter\n");

        scanf("%d", &choix);

        switch (choix)
        {

        case 1:
            printf("\nSaisissez le nouveau pr\202nom: ");
            fflush(stdin);
            gets(list[position].prenom);
            break;

        case 2:
            printf("\nSaisissez le nouveau nom: ");
            fflush(stdin);
            gets(list[position].nom);
            break;

        case 3:
            printf("\nSaisissez la nouvelle ville: ");
            fflush(stdin);
            gets(list[position].ville);
            break;

        case 4:
            printf("\nSaisissez le nouveau code postal: ");
            fflush(stdin);
            gets(list[position].code_postal);
            break;

        case 5:
            printf("\nSaisissez le nouveau t\202l.: ");
            fflush(stdin);
            gets(list[position].tel);
            break;

        case 6:
            printf("\nSaisissez le nouveau mail: ");
            fflush(stdin);
            gets(list[position].mail);
            break;

        case 7:
            printf("\nSaisissez le nouveau travail: ");
            fflush(stdin);
            gets(list[position].job);
            break;

        default:
            edit(list, lines);
            break;
        }
    } while (choix != 8);
    return;
}