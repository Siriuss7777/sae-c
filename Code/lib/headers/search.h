#ifndef _SEARCH_H
#define _SEARCH_H

#include "utils.h"

int search(Client *list, int lines, int option, int dispClient);
int clientSearch(Client *list, int lines, char *text, int dispClient);

#endif // _SEARCH_H