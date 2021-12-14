#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>

#define SHORT_CHAR 20
#define LONG_CHAR 60
#define LONG_LONG_CHAR 120
#define PATH "test.csv"
#define CACHE "cache.txt"

typedef struct client
{
    char prenom[SHORT_CHAR],
        nom[SHORT_CHAR],
        ville[LONG_CHAR],
        code_postal[LONG_CHAR],
        tel[SHORT_CHAR],
        mail[LONG_CHAR],
        job[SHORT_CHAR];
} Client;

bool startswith(char *prefixe, char *texte)
{ // Bastien
  return strncmp(prefixe, texte, strlen(prefixe)) == 0;
}

char *charger_clients(char *chemin)
{
  char ligne[LONG_LONG_CHAR];

  FILE *fic = fopen(chemin, "r");
  if (fic == NULL)
  {
    printf("Erreur: problème d'ouverture du fichier annuaire");
    exit(EXIT_FAILURE);
  }

  FILE *cache = fopen(CACHE, "a");
  if (cache == NULL)
  {
    printf("Erreur: problème d'ouverture du fichier cache");
    exit(EXIT_FAILURE);
  }

  while (fgets(ligne, LONG_LONG_CHAR, fic) != NULL)
  {

    char c = '\0';
    char *token = strtok(ligne, "\n");

    while (token != NULL)
    {
      char *line = malloc(LONG_LONG_CHAR);
      memcpy(line, token, LONG_LONG_CHAR);
      char *c_token = strtok(line, ",");
      while (c_token != NULL)
      {
        if (strlen(c_token)!=0){
          printf("%s | ", c_token);
        }else{
          printf(" | ");
        }
        c_token = strtok(NULL, ",");
      }
      free(line);
      printf("\n");
      fprintf(cache, "%s\n", token);
      token = strtok(NULL, "\n");
    }
  }
}

void obtenir_client(char *nom, char *prenom, char *contact)
{ // Bastien
  char ligne[LONG_LONG_CHAR];
  int n_client = 1, compteur;
  Client client;

  FILE *fic = fopen(PATH, "r");
  if (fic == NULL)
  {
    printf("Erreur: problème d'ouverture du fichier annuaire");
    exit(EXIT_FAILURE);
  }
}

void ajouter() // Hédi
{
    FILE *file = fopen(PATH, "a");

    if (file == NULL)
    {
        printf("Le fichier n'existe pas");
        exit(EXIT_FAILURE);
    }

    Client nouveau_client;
    fflush(stdin);
    printf("\nEntrez un pr\202nom:");
    gets(nouveau_client.prenom);
    printf("\nEntrez un nom:");
    gets(nouveau_client.nom);
    printf("\nEntrez une ville :");
    gets(nouveau_client.ville);
    printf("\nEntrez un code postal:");
    gets(nouveau_client.code_postal);
    printf("\nEntrez le numero de telephone (forme 00.00.00.00.00):");
    gets(nouveau_client.tel);
    printf("\nEntrez la mail:");
    gets(nouveau_client.mail);
    printf("\nEntrez le travail:");
    gets(nouveau_client.job);

    fprintf(file, "%s,%s,%s,%s,%s,%s,%s\n", 
                  nouveau_client.prenom, 
                  nouveau_client.nom, 
                  nouveau_client.ville, 
                  nouveau_client.code_postal, 
                  nouveau_client.tel, 
                  nouveau_client.mail, 
                  nouveau_client.job);
    fclose(file);
}

int modifier()
{
  printf("Modifier");
}
int supprimer()
{
  printf("Supprimer");
}
int afficher()
{ // Bastien
  printf("Afficher");
}
int filtrer()
{
  printf("Filtrer");
}
int chercher()
{
  printf("Chercher");
}
int donnees_manquantes()
{
  printf("Donn\202es manquantes");
}
int sauvegarder()
{
  printf("Sauvegarder");
}

int menu() // Hédi
{
  int choix;
  printf("Que voulez vous faire :\n");
  printf("\t1: Ajouter un client \n");
  printf("\t2: Modifier un client \n");
  printf("\t3: Supprimer un client \n");
  printf("\t4: Afficher tous les données des clients\n");
  printf("\t5: Afficher les clients avec un filtre\n");
  printf("\t6: Chercher un client avec une donnée\n");
  printf("\t7: Clients ayant une donnée manquante (au moins)\n");
  printf("\t8: Sauvegarder\n");
  scanf("%d", &choix);

  switch (choix)
  {
  case 1:
    ajouter();
    break;
  case 2:
    modifier();
    break;
  case 3:
    supprimer();
    break;
  case 4:
    afficher();
    break;
  case 5:
    filtrer();
    break;
  case 6:
    chercher();
    break;
  case 7:
    donnees_manquantes();
    break;
  case 8:
    sauvegarder();
    break;

  default:
    menu();
    break;
  }
}

int main()
{
  menu();
}