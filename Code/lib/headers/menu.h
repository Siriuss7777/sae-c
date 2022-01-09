#ifndef _MENU_H
#define _MENU_H

#include "utils.h"

void Menu(Client *list, int lines, char *path);

void loadClients(Client *list, char *path);

void editClient();

void deleteClient();

void Filter();

void Search();

void displayEmptyClients();

#endif // _MENU_H