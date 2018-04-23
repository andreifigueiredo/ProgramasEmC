#include <stdio.h>

int frequencia(char *word, char letra)
{
    int retorno = 0, j;
    
    for(j = 0; j < 24; j++)
    {
        if(word[j] - 'A' >= 0 && word[j] - 'Z' <= 0)
            word[j] = word[j] - 'A' + 'a';
        
        if(letra == word[j])
            retorno++;
    }
	return retorno;
}
int main(void)
{
    char frase[80];
    char i = 'a';
    int resposta = 0;
    
    puts("Escreva uma frase\n");
    gets(frase);
    
    while(i <= 'z')
    {
        resposta = frequencia(frase, i);
        
        if(resposta != 0)
            printf("%c %d\n", i, resposta);
    
        i++;
    }
    
	return 0;
 
}