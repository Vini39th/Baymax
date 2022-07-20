/*Projeto Drive Thru - LG1A1 - Profª Eub*/
/*Projeto Drive Thru - Contador PRODUTOS DAT - LG1A1 - Profª Eub*/
/*Autorxs: Vinicius Gomes (SP3069192) e Maynara Lino Amaral (SP3079619)*/
/*Bibliotecas utilizadas*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/*
	O presente código-fonte foi criado para determinar a
	quantidade de apontamentos referente aos dados armazenados
	em PRODUTOS.DAT
*/

/*Declaração das Structs utilizadas*/
typedef struct
{
	int ItemNum;
	char ItemNome[30];
	float ItemValor;
	char Item[30];
	int NumQtde;
	float Custo;
}Apontamento;

/*Corpo do Programa Principal*/
int main()
{
	FILE * V;
	Apontamento REG;
	int num_apontamentos;
	V = fopen ("PRODUTOS.DAT", "r");
	
	if (V == NULL){ /*Caso o arquivo seja inexistente*/
	    printf("\nErro ao abrir o arquivo DAT!");
	    num_apontamentos = 0;
	}
	else
	{	/* Calcula o tamanho do arquivo */
		/* Comando 'fseek' coloca-se ao fim do arquivo...*/
		if(fseek(V, 0, SEEK_END))
		{
			printf("\nFalha p/ cálculo do arquivo!\n");
			getch();
			num_apontamentos = -1;
		}
		else
		{	/* Comando 'ftell' contabiliza os bytes do arquivo*/
			/* É feita a seguinte Divisão: 
			Total Bytes arquivo/Tamanho cada arquivo */
			/* Disso, obtem-se e nº de apontamentos do arquivo. */
			num_apontamentos = ftell(V) / sizeof (REG);
			num_apontamentos++;/*num_apontamentos = num_apontamentos + 1*/
		}
		/* Finaliza o arquivo */
		fclose (V);
	}
	return (num_apontamentos);	
}
