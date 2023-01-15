#include <stdio.h>
void board(char array_4[6][7]);
void slot(int no, int player);
void slot2(int num, char playchar);
int check(char array_4[6][7], int player);
char array_4[6][7] = {{' ', ' ', ' ', ' ', ' ', ' ', ' '},
                      {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                      {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                      {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                      {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                      {' ', ' ', ' ', ' ', ' ', ' ', ' '}};
int turn = 1, player, con = 0, no, win = 0;
int main()
{

    printf("Welcome to connect_4 Game! It will be fun So let's begin \n\n");
    board(array_4);

    do
    {
        player = (turn % 2) ? 1 : 2;
        if (player == 1)
        {
            printf("Player-1 plz Enter slot no. (0-6) >> ");
        }
        else
        {
            printf("Player-2 plz Enter slot no. (0-6) >> ");
        }
        scanf("%d", &no);
        slot(no, player);
        win = check(array_4, player);

    } while (con < 42 && win == 0);
    if (player == 1 && win == 1)
    {
        printf("Player-1 won the game!");
    }
    else if (player == 2 && win == 1)
    {
        printf("Player-2 won the game!");
    }
    else
    {
        printf("Game is Tie Plz Try again !");
        main();
    }
    return 0;
}
void board(char array_4[6][7])
{
    printf("| 0 | 1 | 2 | 3 | 4 | 5 | 6 | \n\n");
    printf("| %c | %c | %c | %c | %c | %c | %c | \n", array_4[0][0], array_4[0][1], array_4[0][2], array_4[0][3], array_4[0][4], array_4[0][5], array_4[0][6]);
    printf("| %c | %c | %c | %c | %c | %c | %c | \n", array_4[1][0], array_4[1][1], array_4[1][2], array_4[1][3], array_4[1][4], array_4[1][5], array_4[1][6]);
    printf("| %c | %c | %c | %c | %c | %c | %c | \n", array_4[2][0], array_4[2][1], array_4[2][2], array_4[2][3], array_4[2][4], array_4[2][5], array_4[2][6]);
    printf("| %c | %c | %c | %c | %c | %c | %c | \n", array_4[3][0], array_4[3][1], array_4[3][2], array_4[3][3], array_4[3][4], array_4[3][5], array_4[3][6]);
    printf("| %c | %c | %c | %c | %c | %c | %c | \n", array_4[4][0], array_4[4][1], array_4[4][2], array_4[4][3], array_4[4][4], array_4[4][5], array_4[4][6]);
    printf("| %c | %c | %c | %c | %c | %c | %c | \n", array_4[5][0], array_4[5][1], array_4[5][2], array_4[5][3], array_4[5][4], array_4[5][5], array_4[5][6]);
    printf("----------------------------- \n");
}
void slot(int no, int player)
{
    char playchar;
    if (player == 1)
    {
        playchar = 'X';
    }
    else
    {
        playchar = 'O';
    }
    switch (no)
    {
    case 0:
        slot2(0, playchar);
        break;
    case 1:
        slot2(1, playchar);
        break;
    case 2:
        slot2(2, playchar);
        break;
    case 3:
        slot2(3, playchar);
        break;
    case 4:
        slot2(4, playchar);
        break;
    case 5:
        slot2(5, playchar);
        break;
    case 6:
        slot2(6, playchar);
        break;
    default:
        printf("Plz Enter Between (0-6) \n");
        break;
    }
}
void slot2(int num, char playchar)
{
    for (int i = 0; i < 6; i++)
    {
        if ((array_4[i][num] == ' ' && array_4[i + 1][num] != ' '))
        {
            array_4[i][num] = playchar;
            board(array_4);
            turn++;
            con++;
            break;
        }
        if (array_4[i][num] != ' ')
        {
            printf("This colume is already full \n ");
            break;
        }
    }
}
int check(char array_4[6][7], int player)
{
    char playchar;
    if (player == 1)
    {
        playchar = 'X';
    }
    else
    {
        playchar = 'O';
    }
    for (int i = 0; i < 6; i++)
    {
        if ((array_4[i][0] == playchar && array_4[i][1] == playchar && array_4[i][2] == playchar && array_4[i][3] == playchar) || (array_4[i][1] == playchar && array_4[i][2] == playchar && array_4[i][3] == playchar && array_4[i][4] == playchar) || (array_4[i][2] == playchar && array_4[i][3] == playchar && array_4[i][4] == playchar && array_4[i][5] == playchar) || (array_4[i][3] == playchar && array_4[i][4] == playchar && array_4[i][5] == playchar && array_4[i][6] == playchar))
        {
            return 1;
        }
    }
    for (int i = 0; i < 7; i++)
    {
        if ((array_4[0][i] == playchar && array_4[1][i] == playchar && array_4[2][i] == playchar && array_4[3][i] == playchar) || (array_4[1][i] == playchar && array_4[2][i] == playchar && array_4[3][i] == playchar && array_4[4][i] == playchar) || (array_4[2][i] == playchar && array_4[3][i] == playchar && array_4[4][i] == playchar && array_4[5][i] == playchar))
        {
            return 1;
        }
    }
    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            if ((array_4[i][j] == playchar) && (array_4[i + 1][j + 1] == playchar) && (array_4[i + 2][j + 2] == playchar) && (array_4[i + 3][j + 3] == playchar))
            {
                return 1;
            }
        }
    }
    for (int i = 0; i <= 3; i++)
    {
        for (int j = 6; j > 0; j--)
        {
            if (array_4[i][j] == playchar && array_4[i + 1][j - 1] == playchar && array_4[i + 2][j - 2] == playchar && array_4[i + 3][j - 3] == playchar)
            {
                return 1;
            }
        }
    }

    return 0;
}