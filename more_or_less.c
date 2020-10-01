#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
####### CONSIGNE : ###########################################################

C'est un petit jeu que j'appelle « Plus ou moins ».

Le principe est le suivant.

    L'ordinateur tire au sort un nombre entre 1 et 100.

    Il vous demande de deviner le nombre. Vous entrez donc un nombre entre 1 et 100.

    L'ordinateur compare le nombre que vous avez entré avec le nombre « mystère » qu'il a tiré au sort. Il vous dit si le nombre mystère est supérieur ou inférieur à celui que vous avez entré.

    Puis l'ordinateur vous redemande le nombre.

    … Et il vous indique si le nombre mystère est supérieur ou inférieur.

    Et ainsi de suite, jusqu'à ce que vous trouviez le nombre mystère.

Le but du jeu, bien sûr, est de trouver le nombre mystère en un minimum de coups.

    #include <time.h>
    srand(time(NULL));
    nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;
*/

int main(int argc, char *argv[])
{
    int proposed_nbr, mysterious_nbr;
    const int MIN = 1, MAX = 100;

    // Generate the mysterious number :
    srand(time(NULL));
    mysterious_nbr = (rand() % (MAX - MIN + 1)) + MIN;

    // Ask a number until the mysterious number is discovered.
    do
    {
        printf("Suggest a number between 1 and 100 inclusive : \n");
        scanf("%d", &proposed_nbr);

        if (proposed_nbr > mysterious_nbr)
        {
            printf("It's less !\n");
        }
        else if (proposed_nbr < mysterious_nbr)
        {
            printf("It's more !\n");
        }
    }while (proposed_nbr != mysterious_nbr);

    // The mysterious number has been found :
    printf("Congratz !\n");

    return 0;
}

/* 
cd /home/jaenne/langage_c/o_c
gcc more_or_less.c
./a.out
*/