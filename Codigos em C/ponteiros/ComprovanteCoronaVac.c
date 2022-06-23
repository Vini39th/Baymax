/*Bibliotecas utilizadas*/
#include <stdio.h>
#include <locale.h>


/*Variáveis Globais*/
int dia, mes, ano, data1, data2;

/*Corpo do Programa*/
	main ()
{	
	setlocale (LC_ALL, "");
	printf ("\nDia: "); /*Dia da primeira dose*/
	scanf ("%i", &dia); /*Valor armazenado na variável 'dia'*/
	printf ("\nMês: "); /*Mês da primeira dose*/
	scanf ("%d", &mes); /*Valor armazenado na variável 'mes'. 
	Obs: Apenas o especificador de formatação %d reconheceu 
	dois dígitos (01,02...). Tirar dúvida com profª Eub*/
	printf ("\nAno: "); /*Ano da primeira dose*/
	scanf ("%i", &ano); /*Valor armazenado na variável 'ano'*/
	printf ("\n____________________________________\n"  ); /*Desenho do Layout*/
	printf ("\n             VACINA JÁ                "  ); /*Corpo do Texto do Layout*/
	printf ("\n____________________________________\n"  ); /*Desenho do Layout*/
	printf ("\n	NOME:	Richard	Starkley	\n"  ); /*Nome do vacinado*/
	printf ("\n	CPF:	11111111122			\n"  ); /*CPF do vacinado*/
	printf ("\n	Vacina:	CoronaVac - Butantan	\n"  ); /*Tipo de Vacina*/
	printf ("\nData da 1ª dose:%i/", dia); /*Data da 1ª dose recebida*/
	printf ("%1i/", mes); /*mês*/
	printf ("%i", ano); /*ano*/
	printf ("\nData da 2ª dose:%i/", dia); /*Data da 2ª dose recebida*/
		if ((mes + 1) > 12) /*Estrutura de decisão para virada de mês*/
			printf("01/");
		else
		printf ("%i/", mes + 1);
		if ((mes + 1) > 12) /*Estrutura de decisão para virada de ano*/
		printf ("%i", ano + 1);
		else
		printf ("%i", ano);
	FILE *file; /*ponteiro para criação de arquivo 'file'*/
	file = fopen("COMPROVANTE_RICHARD_STARKEY.txt", "w"); /*Criação de arq txt*/
	fprintf (file, "\n____________________________________\n"  ); /*Desenho do Layout no arq txt*/
	fprintf (file, "\n             VACINA JÁ          "  ); /*Corpo do Texto do Layout no arq txt*/
	fprintf (file, "\n____________________________________"  ); /*Desenho do Layout no arq txt*/
	fprintf (file, "\n	NOME:	Richard	Starkley	\n"  ); /*Nome do vacinado no arq txt*/
	fprintf (file, "\n	CPF:	11111111122			\n"  ); /*CPF do vacinado no arq txt*/
	fprintf (file, "\n	Vacina:	CoronaVac - Butantan	\n"  ); /*Tipo de Vacina no arq txt*/
	fprintf (file, "\nData da 1ª dose:%i/", dia); /*Data da 1ª dose recebida no arq txt*/
	fprintf (file, "%i/", mes); /*mês no arq txt*/
	fprintf (file, "%i", ano); /*ano no arq txt*/
	fprintf (file, "\nData da 2ª dose:%i/", dia); /*Data da 2ª dose recebida no arq txt*/
		if (mes + 1 > 12) /*Estrutura de decisão para virada de mês no arq txt*/
			fprintf(file, "01/");
		else
		fprintf (file, "%i/", mes + 1);
		if ((mes + 1) > 12) /*Estrutura de decisão para virada de ano no arq txt*/
		fprintf (file, "%i", ano + 1);
		else
		fprintf (file, "%i", ano);
	fclose (file);
	system ("notepad COMPROVANTE_RICHARD_STARKEY.txt");

	getch();
}
