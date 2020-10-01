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

/*
######### AMELIORATIONS #########################################
- compteur de coups => ok
- menu quitter/continuer #done ! => ok
- mode 2 joueurs => ok
- Niveaux de difficulté => ok
*/

int main(int argc, char *argv[])
{
    int proposed_nbr, mysterious_nbr, tries_counter, want_to_play, menu, max_nbr = 100, nbr_of_players = 1;
    const int MIN = 1;

    do
    {
        menu = 1, want_to_play = 0;
        while (menu)
        {    
            // MENU        
            printf("\n### MENU ###\n0. Quitt\n1. 1 player mode (default)\n2. 2 players mode\n3. Maximum number is 100 (default)\n4. Maximum number is 1000\n5. Maximum number is 10 000\n6. Play\nYour choice : ");
            scanf("%d", &menu);

            switch (menu)
            {
                case 0:
                printf("\nBye.\n");
                menu = 0;
                break;

                case 1:
                nbr_of_players = 1;
                printf("\nYou will play against your computeur.\n");
                break;

                case 2:
                nbr_of_players = 2;
                printf("\nYou will play against an other player.\n");
                break;

                case 3:
                max_nbr = 100;
                printf("\nThe maximum mysterious number is %d.\n", max_nbr);
                break;

                case 4:
                max_nbr = 1000;
                printf("\nThe maximum mysterious number is %d.\n", max_nbr);
                break;

                case 5:
                max_nbr = 10000;
                printf("\nThe maximum mysterious number is %d.\n", max_nbr);
                break;

                case 6:
                printf("\nNumber of players  : %d.\nMaximum mysterious number : %d.\nLet's play !\n", nbr_of_players, max_nbr);
                want_to_play = 1;
                menu = 0;
                break;

                default:
                printf("\nI did not understand.\n");
                break; 
            }
        }

        // Generate the mysterious number :

        if (nbr_of_players == 1 && want_to_play) // 1 player mode.
        {
            srand(time(NULL));
            mysterious_nbr = (rand() % (max_nbr - MIN + 1)) + MIN;
        }

        if (nbr_of_players == 2 && want_to_play) // 2 players mode.
        {
            do
            {
                printf("Choose the mysterious number between %d and %d : ", MIN, max_nbr);
                scanf("%d", &mysterious_nbr);
            }while (mysterious_nbr < MIN || mysterious_nbr > max_nbr);
            
            
            system("clear");
        }


        tries_counter = 0;

        // Ask a number until the mysterious number is discovered.
        while (proposed_nbr != mysterious_nbr && want_to_play)
        {
            printf("\nSuggest a number between %d and %d inclusive : \n", MIN, max_nbr);
            scanf("%d", &proposed_nbr);
            tries_counter ++;

            if (proposed_nbr > mysterious_nbr)
            {
                printf("It's less !\n");
            }

            else if (proposed_nbr < mysterious_nbr)
            {
                printf("It's more !\n");
            }

            else // The mysterious number has been found :
            {    
                if (tries_counter > 1)
                {
                    printf("\nCongratz ! You find the mysterious number in %d tries.\n", tries_counter);
                }

                else
                {
                    printf("\nCongratz ! You find the mysterious number in 1 try. What luck !\n");
                }
            }
        }
   
    }while (want_to_play);
    
    
    return 0;
}

/* 
cd /home/jaenne/langage_c/o_c
gcc more_or_less.c
./a.out
*/