void modify(Client *lilst, int lines)
{

    int choix;
    char reponse;

    search(list, lines);

    printf("Que voulez vous modifiez: \n"
           "1: Pr\202nom \n"
           "2: Nom \n"
           "3: Ville \n"
           "4: Code postal \n"
           "5: Num\202ro de t\202l\202phone \n"
           "6: Mail \n"
           "7: M\202tier\n");

    gets(choix);

    switch (choix)
    {

    case 1:
        printf("Entrez le pr\202nom à modifier:");
        gets(reponse);

        list[millieu].prenom = reponse;
        break;

    case 2:
        printf("Entrez le nom à modifier:");
        gets(reponse);

        list[millieu].nom = reponse;
        break;

    case 3:
        printf("Entrez la ville à modifier:");
        gets(reponse);

        list[millieu].ville = reponse;
        break;

    case 4:
        printf("Entrez le code postal à modifier:");
        gets(reponse);

        list[millieu].code_postal = reponse;
        break;

    case 5:
        printf("Entrez le num\202ro de t\202l\202phone à modifier:");
        gets(reponse);

        list[millieu].tel = reponse;
        break;

    case 6:
        printf("Entrez le mail à modifier:");
        gets(reponse);

        list[millieu].mail = reponse;
        break;

    case 7:
        printf("Entrez le pr\202nom à modifier:");
        gets(reponse);

        list[millieu].job = reponse;
        break;

    case default:
        modify(lilst, lines);
        break;
    }
}