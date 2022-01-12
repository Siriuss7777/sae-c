#ifndef _UTILS_H
#define _UTILS_H

#define SHORT_CHAR 20
#define MAX_LEN_TEL 15
#define MAX_LEN_CP 6
#define CHAR 30
#define LONG_CHAR 50
#define LONG_LONG_CHAR 140
#define PATH "test.csv"
#define CACHE "cache.txt"
#define CAPTION "\n Pr\202nom               | Nom                  | Ville                          | Code postal | T\202l.           | Adresse mail                                       | Travail        \n\n"

typedef struct client
{
    char prenom[SHORT_CHAR],
        nom[SHORT_CHAR],
        ville[LONG_CHAR],
        code_postal[SHORT_CHAR],
        tel[SHORT_CHAR],
        mail[LONG_CHAR],
        job[SHORT_CHAR];
} Client;

char *strsep(char **stringp, const char *delim);
int isFilled(char *line, int position);
void displayClient(Client *list, int index, int mode);
char *strtolower(char *input);

#endif // UTILS_H