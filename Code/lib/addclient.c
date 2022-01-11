#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "./headers/menu.h"
#include "./headers/utils.h"
#include "./headers/addclient.h"
#include "./headers/displayallclients.h"

Client *addClient(Client *list, int *lines) // Hédi
{
    list = (Client *)realloc(list, sizeof(Client) * (int)(lines + 1));
    *lines = *lines + 1;

    fflush(stdin);

    do
    {
        printf("Saisissez le pr\202nom: ");
        gets(list[*lines - 1].prenom);
    } while (strlen(list[*lines - 1].prenom) > SHORT_CHAR);

    do
    {
        printf("Saisissez le nom: ");
        gets(list[*lines - 1].nom);
    } while (strlen(list[*lines - 1].nom) > SHORT_CHAR);
    do
    {
        printf("Saisissez la ville: ");
        gets(list[*lines - 1].ville);
    } while (strlen(list[*lines - 1].ville) > LONG_CHAR);

    do
    {
        printf("Saisissez le code postal: ");
        gets(list[*lines - 1].code_postal);
    } while (strlen(list[*lines - 1].code_postal) > MAX_LEN_CP);

    do
    {
        printf("Saisissez le num\202ro de t\202l\202phone (forme 00.00.00.00.00): ");
        gets(list[*lines - 1].tel);
    } while (strlen(list[*lines - 1].tel) > MAX_LEN_TEL);

    do
    {
        printf("Saisissez le mail: ");
        gets(list[*lines - 1].mail);
    } while (strlen(list[*lines - 1].mail) > LONG_CHAR);

    do
    {
        printf("Saisissez le m\202tier: ");
        gets(list[*lines - 1].job);
    } while (strlen(list[*lines - 1].job) > SHORT_CHAR);

    printf("Le client suivant sera saisi:\n");
    displayClient(list, *lines - 1, 0);
    printf("\nConfirmer ? (o/n)\n");
    char input = getc(stdin); // ------------------- CHANGER CHOIX
    if (input == 'n')
    {
        addClient(list, lines);
    }
    else
        return (list);
}