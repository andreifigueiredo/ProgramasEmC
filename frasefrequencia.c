#include <stdio.h>

int frequencia(char word[80], char caracter)
{
	int i, retorno = 0;

	for(i = 0; word[i] != '\0'; i++)
	{
		if(word[i] - 'A' >= 0 || word[i] - 'Z' <= 0)
			word[i] = word[i] - 'A' + 'a';
		if(caracter == frase[i])
			retorno ++;
	}
	return retorno;
}
int main(void)
{
	char letra = 'a' ,frase[80];
	int resposta;
	int i;

	gets (frase);

	while(letra != 'z')
	{
		resposta = frequencia(frase, letra);

		printf("%c %d", letra, resposta);

		letra++;
	}
	return 0;
 
}