#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>

#define SHORT_CHAR 20
#define LONG_CHAR 40
#define LONG_LONG_CHAR 140
#define PATH "test.csv"
#define CACHE "cache.txt"

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

void loadClients(Client list[])
{
    char line[LONG_LONG_CHAR];

    FILE *file = fopen(PATH, "r");
    int clientCount = 0;

    while (fgets(line, LONG_LONG_CHAR, file) != NULL)
    {
        int i;
        while(line[i] != '\n'){
            if(line[i] == ',' && line[i+1] == ','){
                while(line[i]!='\n'){
                    line[i+1]=line[i];
                    printf("shift ligne %d\n", i);
                }
                line[i]=' ';
            }
        }
        char *token = strtok(line, ",");
        int count=0;
        clientCount++;
        while (token != NULL)
        {
            if(count==0){
                memcpy(list[clientCount].prenom, token, SHORT_CHAR);
                printf("client %d: %s | ", clientCount ,list[clientCount].prenom);
            }else if(count==1){
                memcpy(list[clientCount].nom, token, SHORT_CHAR);
                printf("%s | ", list[clientCount].nom);
            }else if(count==2){
                memcpy(list[clientCount].ville, token, LONG_CHAR);
                printf("%s | ", list[clientCount].ville);
            }else if(count==3){
                memcpy(list[clientCount].code_postal, token, SHORT_CHAR);
                printf("%s | ", list[clientCount].code_postal);
            }else if(count==4){
                memcpy(list[clientCount].tel, token, SHORT_CHAR);
                printf("%s | ", list[clientCount].tel);
            }else if(count==5){
                memcpy(list[clientCount].mail, token, LONG_CHAR);
                printf("%s | ", list[clientCount].mail);
            }else if(count==6){
                memcpy(list[clientCount].job, token, SHORT_CHAR);
                printf("%s", list[clientCount].job);
            }
            token=strtok(NULL, ",");
            count++;
        }
    }
}

void showClients() {}

int main()
{
    int lines = 0;
    char line[LONG_LONG_CHAR];

    FILE *file = fopen(PATH, "r");

    while (fgets(line, sizeof(line), file) != NULL)
    {
        lines++;
    }
    fclose(file);

    Client list[lines];
    loadClients(list);
}

