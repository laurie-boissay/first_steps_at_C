#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "menu.h"
#include "menu.c"


int main(int argc, char *argv[])
{
    int proposed_nbr, mysterious_nbr, tries_counter, want_to_play, menu, max_nbr = 100, nbr_of_players = 1;
    const int MIN = 1;

    do
    {
        menu = 1, want_to_play = 0;
        while (menu)
        {    
            printf("\n### MENU ###\n0. Quitt\n1. 1 player mode (default)\n2. 2 players mode\n3. Maximum number is 100 (default)\n4. Maximum number is 1000\n5. Maximum number is 10 000\n6. Play\nYour choice : ");
            scanf("%d", &menu);
            display_menu(&menu, &nbr_of_players, &max_nbr, &want_to_play);
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
cd /home/jaenne/langage_c/more_or_less_game
gcc main.c
./a.out
*/