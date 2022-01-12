#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "./headers/utils.h"

char *strsep(char **stringp, const char *delim) // Internet, source: intégré aux machines Linux, x-compatibilité
{
    char *start = *stringp, *p = start ? strpbrk(start, delim) : NULL;

    if (!p)
    {
        *stringp = NULL;
    }
    else
    {
        *p = 0;
        *stringp = p + 1;
    }

    return start;
}

int isFilled(char *line, int position) // Bastien
{
    char *copy;
    int i,
        j;
    copy = line;
    for (i = 0; i < position; i++)
    {
        copy = strpbrk(copy, ",");
        copy = copy + 1;
    }
    if (copy[0] == ',' || copy[0] == '\0')
    {
        return 1;
    }
    return 0;
}

void displayClient(Client *list, int index, int mode) // Hédi
// mode 0: affichage sans formatage
// mode 1: affichage avec formatage à gauche
// mode 2: affichage avec formatage à droite
{
    switch (mode)
    {
    case 0:
        printf("\n %s | %s | %s | %s | %s | %s | %s ",
               list[index].prenom,
               list[index].nom,
               list[index].ville,
               list[index].code_postal,
               list[index].tel,
               list[index].mail,
               list[index].job);
        break;
    case 1:
        printf("\n %-20s | %-20s | %-30s | %-11s | %-14s | %-50s | %-20s ",
               list[index].prenom,
               list[index].nom,
               list[index].ville,
               list[index].code_postal,
               list[index].tel,
               list[index].mail,
               list[index].job);
        break;
    case 2:
        printf("\n %20s | %20s | %30s | %11s | %14s | %50s | %20s ",
               list[index].prenom,
               list[index].nom,
               list[index].ville,
               list[index].code_postal,
               list[index].tel,
               list[index].mail,
               list[index].job);
        break;
    }
}

char *strtolower(char *input)
{
    char *output = (char *)malloc(strlen(input) * sizeof(char));
    strcpy(output, input);
    for (int i = 0; i < strlen(output); i++)
        output[i] = tolower(output[i]);
    return output;
}

char *input(char *buffer, int size)
{
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    return buffer;
}