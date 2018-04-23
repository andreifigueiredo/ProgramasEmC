#include <stdio.h>

int main(void)
{
	char tabuleiro[3][3];
    char o = 'O', x = 'X';
    int turno = 0, j , i, l,linha;


    for(i = 0;i < 3;i++)
        for(j = 0;j < 3;j++)
            tabuleiro[i][j]=' ';

    while(turno <= 9)
    {
    	for(l = 0; l <= 9; l++)
    	{
    	    printf("  JOGO DA VELHA \n");
        	for(linha = 0;linha < 3;linha++)
        	{
      	      printf("\t\t     %c \xBA %c \xBA %c\n",tabuleiro[linha][0],tabuleiro[linha][1],tabuleiro[linha][2]);
      	      if(linha < 3 - 1)
        	    {
                	printf("\t\t    ÍÍÍ\xCEÍÍÍ\xCEÍÍÍ\n");
            	}
    		}
    	
    		for(i = 1; i <= 3; i++)
    		{
    			for(j = 1; j <= 3; j++)
    			{
    			printf("--------------------------------------------------------------------------------  \nJOGO DA VELHA \n");
    			for(linha = 0;linha < 3;linha++)
        		{
      	      		printf("\t\t     %c \xBA %c \xBA %c\n",tabuleiro[linha][0],tabuleiro[linha][1],tabuleiro[linha][2]);
      	      		if(linha < 3 - 1)
        	    	{
                		printf("\t\t    ÍÍÍ\xCEÍÍÍ\xCEÍÍÍ\n");
            		}
    			}

        			if(tabuleiro[i-1][j-1] == ' ')
        			{
            			if(turno % 2)
            			{
              				tabuleiro[i-1][j-1] = x;
            			}
            		
            			else
            			{ 
            			  tabuleiro[i-1][j-1] = o;
            			  
            			}
            			turno++;
            		}
            		else
            			printf("Essa coordenanda já está preenchida!!!\n");

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
    		}
		}
        	turno++;
	}
}
	