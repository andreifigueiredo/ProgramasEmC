#include <stdio.h>

int pool(int numero, int expoente)
{
	int retorno = 1;
	int i;

	for(i = 0; i < expoente; i++)
	{
		retorno = retorno * numero;
	}
	return retorno;
}
int sqrt(int numero)
{
	int retorno;
	int i;

	for(i = 0; i < numero/2; i++)
	{
		if(i * i == numero)
		{
			retorno = i;
			break;
		}

	}

	return retorno;
}
int main (void)
{
	int primeiro_termo, segundo_termo, resultado;
	int operation;

	printf("Insira o tipo de operação que deseja fazer:\n");
	printf("Insira\n(1) para adição\n(2) para subtração\n(3) para multiplicação\n(4) para divisão\n(5) para exponenciação\n(6) para raiz quadrada\n");
	scanf("%d", &operation);

	printf("Insira o primeiro operador:\n");
	scanf("%d", &primeiro_termo);

	printf("Insira o segundo operador:\n");
	scanf("%d", &segundo_termo);

	if (operation == 1)
	{
		resultado = primeiro_termo + segundo_termo;
	}

	else if (operation == 2)
	{
		resultado = primeiro_termo - segundo_termo; 
	}

	else if (operation == 3)
	{
		resultado = primeiro_termo * segundo_termo;
	}

	else if (operation == 4)
	{
		resultado = primeiro_termo / segundo_termo;
	}

	else if (operation == 5)
	{
		resultado = pool(primeiro_termo, segundo_termo); 
	}

	else if (operation == 6)
	{
		resultado = sqrt(primeiro_termo);
	}

	printf("O resultado é: %d\n", resultado);

	return 0;
}