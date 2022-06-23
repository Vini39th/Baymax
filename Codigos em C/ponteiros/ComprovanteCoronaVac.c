/*Bibliotecas utilizadas*/
#include <stdio.h>
#include <locale.h>


/*Vari�veis Globais*/
int dia, mes, ano, data1, data2;

/*Corpo do Programa*/
	main ()
{	
	setlocale (LC_ALL, "");
	printf ("\nDia: "); /*Dia da primeira dose*/
	scanf ("%i", &dia); /*Valor armazenado na vari�vel 'dia'*/
	printf ("\nM�s: "); /*M�s da primeira dose*/
	scanf ("%d", &mes); /*Valor armazenado na vari�vel 'mes'. 
	Obs: Apenas o especificador de formata��o %d reconheceu 
	dois d�gitos (01,02...). Tirar d�vida com prof� Eub*/
	printf ("\nAno: "); /*Ano da primeira dose*/
	scanf ("%i", &ano); /*Valor armazenado na vari�vel 'ano'*/
	printf ("\n____________________________________\n"  ); /*Desenho do Layout*/
	printf ("\n             VACINA J�                "  ); /*Corpo do Texto do Layout*/
	printf ("\n____________________________________\n"  ); /*Desenho do Layout*/
	printf ("\n	NOME:	Richard	Starkley	\n"  ); /*Nome do vacinado*/
	printf ("\n	CPF:	11111111122			\n"  ); /*CPF do vacinado*/
	printf ("\n	Vacina:	CoronaVac - Butantan	\n"  ); /*Tipo de Vacina*/
	printf ("\nData da 1� dose:%i/", dia); /*Data da 1� dose recebida*/
	printf ("%1i/", mes); /*m�s*/
	printf ("%i", ano); /*ano*/
	printf ("\nData da 2� dose:%i/", dia); /*Data da 2� dose recebida*/
		if ((mes + 1) > 12) /*Estrutura de decis�o para virada de m�s*/
			printf("01/");
		else
		printf ("%i/", mes + 1);
		if ((mes + 1) > 12) /*Estrutura de decis�o para virada de ano*/
		printf ("%i", ano + 1);
		else
		printf ("%i", ano);
	FILE *file; /*ponteiro para cria��o de arquivo 'file'*/
	file = fopen("COMPROVANTE_RICHARD_STARKEY.txt", "w"); /*Cria��o de arq txt*/
	fprintf (file, "\n____________________________________\n"  ); /*Desenho do Layout no arq txt*/
	fprintf (file, "\n             VACINA J�          "  ); /*Corpo do Texto do Layout no arq txt*/
	fprintf (file, "\n____________________________________"  ); /*Desenho do Layout no arq txt*/
	fprintf (file, "\n	NOME:	Richard	Starkley	\n"  ); /*Nome do vacinado no arq txt*/
	fprintf (file, "\n	CPF:	11111111122			\n"  ); /*CPF do vacinado no arq txt*/
	fprintf (file, "\n	Vacina:	CoronaVac - Butantan	\n"  ); /*Tipo de Vacina no arq txt*/
	fprintf (file, "\nData da 1� dose:%i/", dia); /*Data da 1� dose recebida no arq txt*/
	fprintf (file, "%i/", mes); /*m�s no arq txt*/
	fprintf (file, "%i", ano); /*ano no arq txt*/
	fprintf (file, "\nData da 2� dose:%i/", dia); /*Data da 2� dose recebida no arq txt*/
		if (mes + 1 > 12) /*Estrutura de decis�o para virada de m�s no arq txt*/
			fprintf(file, "01/");
		else
		fprintf (file, "%i/", mes + 1);
		if ((mes + 1) > 12) /*Estrutura de decis�o para virada de ano no arq txt*/
		fprintf (file, "%i", ano + 1);
		else
		fprintf (file, "%i", ano);
	fclose (file);
	system ("notepad COMPROVANTE_RICHARD_STARKEY.txt");

	getch();
}
