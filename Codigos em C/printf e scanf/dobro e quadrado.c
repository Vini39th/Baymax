/*Bibliotecas utilizadas*/
#include <stdio.h>

/*Vari�veis globais*/
int numero, dobro, quadrado;

/*Corpo do Programa*/
int	main ()
	{
	printf ("\nInsira o numero:"); /*Valor do n�mero*/
	scanf ("%i" , &numero); /*Valor armazenado na vari�vel 'numero'*/
	dobro = numero*2;
	quadrado = numero*numero;
	printf ("\nDobro de %i: %i\n", numero, dobro);
	printf ("\nQuadrado de %i: :%i\n", numero, quadrado);
	getch();/* Aguarda at� que uma tecla seja pressionada */
	}

