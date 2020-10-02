void display_menu(int *p_menu, int *p_nbr_of_players, int *p_max_nbr, int *p_want_to_play)
{
    switch (*p_menu)
    {
        case 0:
        printf("\nBye.\n");
        *p_menu = 0;
        break;

        case 1:
        *p_nbr_of_players = 1;
        printf("\nYou will play against your computeur.\n");
        break;

        case 2:
        *p_nbr_of_players = 2;
        printf("\nYou will play against an other player.\n");
        break;

        case 3:
        *p_max_nbr = 100;
        printf("\nThe maximum mysterious number is %d.\n", *p_max_nbr);
        break;

        case 4:
        *p_max_nbr = 1000;
        printf("\nThe maximum mysterious number is %d.\n", *p_max_nbr);
        break;

        case 5:
        *p_max_nbr = 10000;
        printf("\nThe maximum mysterious number is %d.\n", *p_max_nbr);
        break;

        case 6:
        printf("\nNumber of players  : %d.\nMaximum mysterious number : %d.\nLet's play !\n", *p_nbr_of_players, *p_max_nbr);
        *p_want_to_play = 1;
        *p_menu = 0;
        break;

        default:
        printf("\nI did not understand.\n");
        break; 
    }
}

