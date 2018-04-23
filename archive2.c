#include<stdio.h>

int main(void)
{
	typedef struct _Aluno
	{
		char nome[50];
		float nota1, nota2;
	}Aluno;

	FILE *pa;

	pa = fopen("contador.txt", "r");

	if(pa == NULL)
	{
		printf("Não foi possivel abrir o aquivo");
		return 1;
	}
	while()
	fscanf(pa, "%s %f %f", Aluno.nome, Aluno.&nota1, Aluno.&nota2);


}