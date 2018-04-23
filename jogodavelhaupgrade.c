#include <stdio.h>

int inteligenciaArtificial(char tabuleiro[][], int turno)
{
  int posicao, pontuacao, bestpontucao = 0;
  int i, j;

  if(turno == 0)
  {
    posicao = 5;
    return posicao;
  }

  for(i = 0; i < 3; i++)
  {
    for(j = 0; 3; j++)
    {
      pontuacao = 0;
      if((tabuleiro[0][0] == o && tabuleiro[0][1] == o && tabuleiro[0][2] == o)||
           (tabuleiro[1][0] == o && tabuleiro[1][1] == o && tabuleiro[1][2] == o)||
           (tabuleiro[2][0] == o && tabuleiro[2][1] == o && tabuleiro[2][2] == o)||
           (tabuleiro[0][0] == o && tabuleiro[1][0] == o && tabuleiro[2][0] == o)||
           (tabuleiro[0][1] == o && tabuleiro[1][1] == o && tabuleiro[2][1] == o)||
           (tabuleiro[0][2] == o && tabuleiro[1][2] == o && tabuleiro[2][2] == o)||
           (tabuleiro[0][0] == o && tabuleiro[1][1] == o && tabuleiro[2][2] == o)||
           (tabuleiro[0][2] == o && tabuleiro[1][1] == o && tabuleiro[2][0] == o))
        {
          pontuacao += 10;
        }
        if((tabuleiro[0][0] == x && tabuleiro[0][1] == x && tabuleiro[0][2] == x)||
           (tabuleiro[1][0] == x && tabuleiro[1][1] == x && tabuleiro[1][2] == x)||
           (tabuleiro[2][0] == x && tabuleiro[2][1] == x && tabuleiro[2][2] == x)||
           (tabuleiro[0][0] == x && tabuleiro[1][0] == x && tabuleiro[2][0] == x)||
           (tabuleiro[0][1] == x && tabuleiro[1][1] == x && tabuleiro[2][1] == x)||
           (tabuleiro[0][2] == x && tabuleiro[1][2] == x && tabuleiro[2][2] == x)||
           (tabuleiro[0][0] == x && tabuleiro[1][1] == x && tabuleiro[2][2] == x)||
           (tabuleiro[0][2] == x && tabuleiro[1][1] == x && tabuleiro[2][0] == x))
        {
          pontuacao += -10;
        }
         if(turno == 9)
          pontuacao += 0;      

    }
  }

  if(pontuacao >  bestpontuacao)
    bestpontuacao = pontuacao;
  
}

int main(void)
{
    char tabuleiro[3][3];
    char o = 'O', x = 'X';
    int turno = 0, j , i;


    for(i = 0;i < 3;i++)
        for(j = 0;j < 3;j++)
            tabuleiro[i][j]=' ';

    while(turno <= 9)
    {
        printf("  JOGO DA VELHA \n");
        for(i = 0;i < 3;i++)
        {
            printf("\t\t     %c \xBA %c \xBA %c\n",tabuleiro[i][0],tabuleiro[i][1],tabuleiro[i][2]);
            if(i < 3 - 1)
            {
                printf("\t\t    ÍÍÍ\xCEÍÍÍ\xCEÍÍÍ\n");
            }
    }

        printf("\n\n\n\n\n\n\n\n\n\n\n\nINSIRA AS COORDENADAS, ");
        if(turno % 2)
        {
          printf("PLAYER\nLINHA: ");
        
            scanf("%d",&i);
            printf("COLUNA: ");
            scanf("%d",&j);
        }

        else 
          {
            printf("BOOT\n");
            
            if(inteligenciaArtificial(tabuleiro, turno) == 5)
            {
              i = 2;
              j = 2;
            }

            if(inteligenciaArtificial(tabuleiro, turno) == 1)
            {
              i = 1;
              j = 1;
            }
            if(inteligenciaArtificial(tabuleiro, turno) == 2)
            {
              i = 1;
              j = 2;
            }
            if(inteligenciaArtificial(tabuleiro, turno) == 3)
            {
              i = 1;
              j = 3;
            }
            if(inteligenciaArtificial(tabuleiro, turno) == 4)
            {
              i = 2;
              j = 1;
            }
            if(inteligenciaArtificial(tabuleiro, turno) == 6)
            {
              i = 2;
              j = 3;
            }
            if(inteligenciaArtificial(tabuleiro, turno) == 7)
            {
              i = 3;
              j = 1;
            }
            if(inteligenciaArtificial(tabuleiro, turno) == 8)
            {
              i = 3;
              j = 2;
            }
            if(inteligenciaArtificial(tabuleiro, turno) == 9)
            {
              i = 3;
              j = 3;
            }
          }

        if(tabuleiro[i-1][j-1] ==' ')
        {
            if(turno % 2)
              tabuleiro[i-1][j-1] = x;
            else 
              tabuleiro[i-1][j-1] = o;
            turno++;
        }


        if((tabuleiro[0][0] == o && tabuleiro[0][1] == o && tabuleiro[0][2] == o)||
           (tabuleiro[1][0] == o && tabuleiro[1][1] == o && tabuleiro[1][2] == o)||
           (tabuleiro[2][0] == o && tabuleiro[2][1] == o && tabuleiro[2][2] == o)||
           (tabuleiro[0][0] == o && tabuleiro[1][0] == o && tabuleiro[2][0] == o)||
           (tabuleiro[0][1] == o && tabuleiro[1][1] == o && tabuleiro[2][1] == o)||
           (tabuleiro[0][2] == o && tabuleiro[1][2] == o && tabuleiro[2][2] == o)||
           (tabuleiro[0][0] == o && tabuleiro[1][1] == o && tabuleiro[2][2] == o)||
           (tabuleiro[0][2] == o && tabuleiro[1][1] == o && tabuleiro[2][0] == o))
        {
            printf("\n\a\t\tBOOT, VOCE VENCEU!!!\n");
            break;
        }

        if((tabuleiro[0][0] == x && tabuleiro[0][1] == x && tabuleiro[0][2] == x)||
           (tabuleiro[1][0] == x && tabuleiro[1][1] == x && tabuleiro[1][2] == x)||
           (tabuleiro[2][0] == x && tabuleiro[2][1] == x && tabuleiro[2][2] == x)||
           (tabuleiro[0][0] == x && tabuleiro[1][0] == x && tabuleiro[2][0] == x)||
           (tabuleiro[0][1] == x && tabuleiro[1][1] == x && tabuleiro[2][1] == x)||
           (tabuleiro[0][2] == x && tabuleiro[1][2] == x && tabuleiro[2][2] == x)||
           (tabuleiro[0][0] == x && tabuleiro[1][1] == x && tabuleiro[2][2] == x)||
           (tabuleiro[0][2] == x && tabuleiro[1][1] == x && tabuleiro[2][0] == x))
        {
            printf("\n\n\n\n\a\t\tPLAYER, VOCE VENCEU!!!\n");
            break;
        }

        if(turno == 9)
        {
            printf("PARTIDA EMPATADA\n");
            break;
        }

    }
    return(0);
}