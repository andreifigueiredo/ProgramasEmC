#include<stdio.h>

int main(void)
{
	char nome[20];
	float nota1, nota2, media;

	FILE *pa;

	pa = fopen("media.txt", "w");
	if(pa == NULL)
	{
		printf("Arquivo não pode ser aberto.");	
		return 1;
	}

	puts("Entre com o nome do aluno: ");
	gets(nome);

	puts("Entre com a primeira nota: ");
	scanf("%f", &nota1);

	puts("Entre com a segunda nota: ");
	scanf("%f", &nota2);

	fprintf(pa, "%s %f %f", nome, nota1, nota2);
	rewind(pa);

	fscanf(pa, "%s %f %f", nome, &nota1, &nota2);
	media = (nota1 + nota2) / 2;

	printf("%s tirou %f", nome, media);

	fclose(pa);
	return 0;
}