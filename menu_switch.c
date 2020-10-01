#include <stdio.h>
#include <stdlib.h>



// Pas besoin d'appeler la fonction main en C.
int main(int argc, char *argv[])
{
    int choix_menu = 3, nombre = 0;

    while (choix_menu)
    {
        printf("### Menu ###\n0. Quitter\n1. Lire\n2. Ecrire\n\nEntrez votre choix : ");
        scanf("%d", &choix_menu);

        switch (choix_menu)
        {
            case 0:
                printf("\nBye.\n");
                break;
            case 2:
                printf("\nEntrez votre nombre : \n");
                scanf("%d", &nombre);
                break;
            default:
                printf("\nVotre nombre : %d.\n", nombre);
                break;
        }
    }

    return 0;
}

/* 
cd /home/jaenne/langage_c/o_c
gcc hello_world.c
./a.out
*/