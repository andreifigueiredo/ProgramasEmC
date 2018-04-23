#include <stdio.h>
 
char gridChar(int i) 
{
    switch(i) 
    {
        case -1:
            return 'X';
        case 0:
            return ' ';
        case 1:
            return 'O';
    }
}
 
void draw(int b[9]) 
{
    printf(" %c | %c | %c\n",gridChar(b[0]),gridChar(b[1]),gridChar(b[2]));
    printf("\xBA\xBA\xBA+\xBA\xBA\xBA+\xBA\xBA\xBA\n");
    printf(" %c | %c | %c\n",gridChar(b[3]),gridChar(b[4]),gridChar(b[5]));
    printf("\xBA\xBA\xBA+\xBA\xBA\xBA+\xBA\xBA\xBA\n");
    printf(" %c | %c | %c\n",gridChar(b[6]),gridChar(b[7]),gridChar(b[8]));
}
 
int win(const int board[9]) 
{
    //Determina se um jogador ganha returns 0 caso contrário.
    unsigned wins[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int i;
    for(i = 0; i < 8; ++i) 
    {
        if(board[wins[i][0]] != 0 &&
           board[wins[i][0]] == board[wins[i][1]] &&
           board[wins[i][0]] == board[wins[i][2]])
            return board[wins[i][2]];
    }
    return 0;
}
 
int minimax(int board[9], int player) 
{
    //Como está o tabuleiro para o player(no turno dele)?
    int winner = win(board);
    if(winner != 0) 
        return winner*player;
 
    int move = -1;
    int score = -2;//Se perder jogadas melhor n jogar
    int i;
    for(i = 0; i < 9; ++i) 
    {//Para todas as jogadas,
        if(board[i] == 0) 
        {//Se possivel,
            board[i] = player;//Tentar a jogada
            int thisScore = -minimax(board, player*-1);
            if(thisScore > score) 
            {
                score = thisScore;
                move = i;
            }//Escolhe a jogada que é pior para o oponente
            board[i] = 0;//Depois de tentar limpa o tabuleiro
        }
    }
    if(move == -1) 
        return 0;

    return score;
}
 
void computerMove(int board[9]) 
{
    int move = -1;
    int score = -2;
    int i;
    for(i = 0; i < 9; ++i) 
    {
        if(board[i] == 0) 
        {
            board[i] = 1;
            int tempScore = -minimax(board, -1);
            board[i] = 0;
            if(tempScore > score) 
            {
                score = tempScore;
                move = i;
            }
        }
    }
    //Retorna uma pontuação dependendo do minmax na determinada raiz
    board[move] = 1;
}
 
void playerMove(int board[9]) 
{
    int move = 0;
    do 
    {
        printf("\nEscolha uma jogada ([0..8]): ");
        scanf("%d", &move);
        printf("\n");
    } 
    while (move >= 9 || move < 0 && board[move] == 0);
    board[move] = -1;
}
 
int main() 
{
    int board[9] = {0,0,0,0,0,0,0,0,0};
    //Jogada do computador é 1, jogada do player é -1.
    printf("Computador: O, Você: X\nJogar (1)Primeiro ou (2)Segundo? ");
    int player=0;
    scanf("%d",&player);
    printf("\n");
    unsigned turn;
    for(turn = 0; turn < 9 && win(board) == 0; ++turn) 
    {
        if((turn+player) % 2 == 0)
            computerMove(board);
        else 
        {
            draw(board);
            playerMove(board);
        }
    }
    switch(win(board)) 
    {
        case 0:
            printf("Empate.\n");
            break;
        case 1:
            draw(board);
            printf("Você Pedeu.\n");
            break;
        case -1:
            printf("Você Venceu.\n");
            break;
    }
}