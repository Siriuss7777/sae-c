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
            cursorLeftTest = list[cursorLeft].prenom;
            cursorRightTest = list[cursorRight].prenom;
            break;
        case 2:
            cursorLeftTest = list[cursorLeft].nom;
            cursorRightTest = list[cursorRight].nom;
            break;
        case 3:
            cursorLeftTest = list[cursorLeft].ville;
            cursorRightTest = list[cursorRight].ville;
            break;
        case 4:
            cursorLeftTest = (char *)list[cursorLeft].code_postal;
            cursorRightTest = (char *)list[cursorRight].code_postal;
            break;
        case 5:
            cursorLeftTest = list[cursorLeft].tel;
            cursorRightTest = list[cursorRight].tel;
            break;
        case 6:
            cursorLeftTest = list[cursorLeft].mail;
            cursorRightTest = list[cursorRight].mail;
            break;
        case 7:
            cursorLeftTest = list[cursorLeft].job;
            cursorRightTest = list[cursorRight].job;
            break;
        }
        if (cursorLeft == halfLines + 1)
        {
            tempList[cursor] = list[cursorRight];
            cursorRight++;
        }
        else if (cursorRight == end + 1)
        {
            tempList[cursor] = list[cursorLeft];
            cursorLeft++;
        }
        else if (strcoll(cursorLeftTest, cursorRightTest) < 0)
        {
            tempList[cursor] = list[cursorLeft];
            cursorLeft++;
        }
        else
        {
            tempList[cursor] = list[cursorRight];
            cursorRight++;
        }
    }

    for (cursor = start; cursor <= end; cursor++)
    {
        list[cursor] = tempList[cursor];
    }
}