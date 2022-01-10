#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "./headers/utils.h"

void mergeSort(int start, int end, Client *list, Client *tempList, int choix)
{
    if (end <= start)
    {
        return;
    }
    int halfLines = (start + end) / 2;

    mergeSort(start, halfLines, list, tempList, choix);
    mergeSort(halfLines + 1, end, list, tempList, choix);

    int cursorLeft = start,
        cursorRight = halfLines + 1,
        cursor;

    char *cursorLeftTest,
        *cursorRightTest;

    for (cursor = start; cursor <= end; cursor++)
    {
        switch (choix)
        {
        case 1:
            cursorLeftTest = (char *)malloc(SHORT_CHAR);
            cursorLeftTest = list[cursorLeft].prenom;
            cursorRightTest = (char *)malloc(SHORT_CHAR);
            cursorRightTest = list[cursorRight].prenom;
            break;
        case 2:
            cursorLeftTest = (char *)malloc(SHORT_CHAR);
            cursorLeftTest = list[cursorLeft].nom;
            cursorRightTest = (char *)malloc(SHORT_CHAR);
            cursorRightTest = list[cursorRight].nom;
            break;
        case 3:
            cursorLeftTest = (char *)malloc(LONG_CHAR);
            cursorLeftTest = list[cursorLeft].ville;
            cursorRightTest = (char *)malloc(LONG_CHAR);
            cursorRightTest = list[cursorRight].ville;
            break;
        case 4:
            cursorLeftTest = (char *)malloc(SHORT_CHAR);
            cursorLeftTest = (char *)list[cursorLeft].code_postal;
            cursorRightTest = (char *)malloc(SHORT_CHAR);
            cursorRightTest = (char *)list[cursorRight].code_postal;
            break;
        case 5:
            cursorLeftTest = (char *)malloc(SHORT_CHAR);
            cursorLeftTest = list[cursorLeft].tel;
            cursorRightTest = (char *)malloc(SHORT_CHAR);
            cursorRightTest = list[cursorRight].tel;
            break;
        case 6:
            cursorLeftTest = (char *)malloc(LONG_CHAR);
            cursorLeftTest = list[cursorLeft].mail;
            cursorRightTest = (char *)malloc(LONG_CHAR);
            cursorRightTest = list[cursorRight].mail;
            break;
        case 7:
            cursorLeftTest = (char *)malloc(SHORT_CHAR);
            cursorLeftTest = list[cursorLeft].job;
            cursorRightTest = (char *)malloc(SHORT_CHAR);
            cursorRightTest = list[cursorRight].job;
            break;
        }
        if (cursorLeft == halfLines + 1)
        {
            // tempList[cursor] = list[cursorRight];
            memcpy(&tempList[cursor], &list[cursorRight], sizeof(Client));
            cursorRight++;
        }
        else if (cursorRight == end + 1)
        {
            // tempList[cursor] = list[cursorLeft];
            memcpy(&tempList[cursor], &list[cursorLeft], sizeof(Client));
            cursorLeft++;
        }
        else if (strcoll(cursorLeftTest, cursorRightTest) < 0)
        {
            memcpy(&tempList[cursor], &list[cursorLeft], sizeof(Client));
            // tempList[cursor] = list[cursorLeft];
            cursorLeft++;
        }
        else
        {
            // tempList[cursor] = list[cursorRight];
            memcpy(&tempList[cursor], &list[cursorRight], sizeof(Client));
            cursorRight++;
        }
    }

    for (cursor = start; cursor <= end; cursor++)
    {
        // list[cursor] = tempList[cursor];
        memcpy(&list[cursor], &tempList[cursor], sizeof(Client));
    }
}