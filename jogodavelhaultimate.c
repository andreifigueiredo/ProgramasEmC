#include <stdio.h>
#include <stdlib.h> 
char simbolo(int contador) 
{
    switch(contador) 
    {
        case -1:
            return 'X';
        case 0:
            return ' ';
        case 1:
            return 'O';
    }
}

void geraBase() 
{
    printf("\nEscolha uma jogada ([0 a 8]) conforme o tabuleiro base: ");
    printf("JOGO DA VELHA\nTabuleiro Base:\n");
    printf("--------------------------------------------------------------------------------\n");
    printf(" 0 | 1 | 2\n");
    printf("\xBA\xBA\xBA+\xBA\xBA\xBA+\xBA\xBA\xBA\n");
    printf(" 3 | 4 | 5\n");
    printf("\xBA\xBA\xBA+\xBA\xBA\xBA+\xBA\xBA\xBA\n");
    printf(" 6 | 7 | 8\n");
    printf("--------------------------------------------------------------------------------\n");

}
 
void geraTabuleiro(int tabuleiro[9]) 
{
    printf("--------------------------------------------------------------------------------\n");
    printf(" %c | %c | %c\n",simbolo(tabuleiro[0]),simbolo(tabuleiro[1]),simbolo(tabuleiro[2]));
    printf("\xBA\xBA\xBA+\xBA\xBA\xBA+\xBA\xBA\xBA\n");
    printf(" %c | %c | %c\n",simbolo(tabuleiro[3]),simbolo(tabuleiro[4]),simbolo(tabuleiro[5]));
    printf("\xBA\xBA\xBA+\xBA\xBA\xBA+\xBA\xBA\xBA\n");
    printf(" %c | %c | %c\n",simbolo(tabuleiro[6]),simbolo(tabuleiro[7]),simbolo(tabuleiro[8]));
    printf("--------------------------------------------------------------------------------\n");

}
 
int win(const int tabuleiro[9]) 
{
    //Determina se um jogador ganha returns 0 caso contrário.
    int wins[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int contador;
    
    for(contador = 0; contador <= 7; contador++) 
    {
        if((tabuleiro[wins[contador][0]] != 0) && (tabuleiro[wins[contador][0]] == tabuleiro[wins[contador][1]]) &&
                                                    (tabuleiro[wins[contador][0]] == tabuleiro[wins[contador][2]]))
            return tabuleiro[wins[contador][2]];
    }
    return 0;
}
 
int minimax(int tabuleiro[9], int player) 
{
    //Como está o tabuleiro para o player(no turno dele)?
    int winner = win(tabuleiro);
    
    if(winner != 0) 
        return winner*player;
 
    int jogada = -1;
    int score = -10;//Se perder jogadas melhor não jogar
    int contador;
    
    for(contador = 0; contador <= 8; contador++) 
    {//Para todas as jogadas,
        if(tabuleiro[contador] == 0) 
        {//Se possivel,
            tabuleiro[contador] = player;//Tentar a jogada
            
            int thisScore = -minimax(tabuleiro, player*-1);
            
            if(thisScore > score) 
            {
                score = thisScore;
                jogada = contador;
            }//Escolhe a jogada que é pior para o oponente
            tabuleiro[contador] = 0;//Depois de tentar limpa o tabuleiro
        }
    }
    if(jogada == -1) 
        return 0;

    return score;
}
 
void jogadaBoot(int tabuleiro[9]) 
{
    int jogada = -1;
    int score = -10;
    int contador;

    for(contador = 0; contador <= 8; contador++) 
    {
        if(tabuleiro[contador] == 0) 
        {
            tabuleiro[contador] = 1;
            int tempScore = -minimax(tabuleiro, -1);
            tabuleiro[contador] = 0;
            if(tempScore > score) 
                {
                    score = tempScore;
                    jogada = contador;
                }
        }
    }

    //Retorna uma pontuação dependendo do minmax no determinado caminho
    tabuleiro[jogada] = 1;
}
 
void jogadaPlayer(int tabuleiro[9]) 
{
    int jogada = 0;
    
    do 
    {
        printf("\nEscolha uma jogada ([0 a 8])");
        scanf("%d", &jogada);
        printf("\n");
    } 
    while (jogada >= 9 || jogada < 0 && tabuleiro[jogada] == 0);
    
    tabuleiro[jogada] = -1;
}
 
int main() 
{    
    int menu, sair = 0;int vitorias = 0;int derrotas = 0;int empates = 0;
    
    geraBase();

    do
    {
        int tabuleiro[9] = {0,0,0,0,0,0,0,0,0};
        //Jogada do computador é 1, jogada do player é -1.
        printf("Computador: O, Você: X\nJogar (1)Primeiro ou (2)Segundo? ");
        int player = 0;       
    
        scanf("%d",&player);
    
        printf("\n");
    
        int turno;
    
        for(turno = 0; turno <= 8 && win(tabuleiro) == 0; turno++) 
        {
            if((turno + player) % 2 == 0)
                jogadaBoot(tabuleiro);
            else 
            {
                geraTabuleiro(tabuleiro);
                jogadaPlayer(tabuleiro);
            }
        }
    
        switch(win(tabuleiro)) 
        {
            case 0:
                geraTabuleiro(tabuleiro);
                printf("\n###Empate.###\n");
                empates++;
                break;
            case 1:
                geraTabuleiro(tabuleiro);
                printf("\n###Você Pedeu###.\n");
                derrotas++;
                break;
            case -1:
                geraTabuleiro(tabuleiro);
                printf("\n###Você Venceu.###\n");
                vitorias++;
                break;
        }
        printf("Digite o númeiro correspontente com a ação\n");
        printf("1.JOGAR\n2.PONTUAÇÃO E JOGAR\n3.PONTUAÇÃO E SAIR\n");
        printf("Opção:");
        scanf("%d",&menu);

        switch(menu)
        {
            case 1:
                break;
            case 2:
                printf("Vitórias:%d \nDerrotas:%d \nEmpates:%d \n", vitorias, derrotas, empates);
                break;
            case 3:
                printf("Vitórias:%d \nDerrotas:%d \nEmpates:%d \n", vitorias, derrotas, empates);
                exit(0);
                break;
        }
    }
    while(sair == 0);
        
}