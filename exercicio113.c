# include <stdio.h>
# include <stdlib.h>
/*
typedef struct 
{
	
	char nome[81];
	float n1, n2;

}ALUNO;*/

int main(void)
{
	char *nome_arquivo = "arquivo113.txt";
	FILE *pa;
	int quantidade;
	char nome[81];
	float n1, n2;
	pa = fopen(nome_arquivo, "w+");

	printf("Quais são os dados do aluno \n");
	printf("Nome");
	scanf("%s", nome);
	printf("Nota1");
	scanf("%f", &n1);
	printf("Nota2");
	scanf("%f", &n2);
	

	fwrite(nome, sizeof(char[80]), 1, pa);
	fwrite(&n1, sizeof(float), 1, pa);
	fwrite(&n2, sizeof(float), 1, pa);

	fclose(pa);

	pa = fopen(nome_arquivo, "r");

	fread(nome, sizeof(char[80]), 1, pa);
	fread(&n1, sizeof(float), 1, pa);
	fread(&n2, sizeof(float), 1, pa);
	
	printf("Os dados do aluno são: \n");
	printf("Nome: %s\n", nome);
	printf("Nota1: %f\n", n1);
	printf("Nota2: %f\n", n2);


	fclose(pa);

	return 0;
}