/*Bibliotecas utilizadas*/
#include <stdio.h>

/*Variáveis globais*/
int numero, dobro, quadrado;

/*Corpo do Programa*/
int	main ()
	{
	printf ("\nInsira o numero:"); /*Valor do número*/
	scanf ("%i" , &numero); /*Valor armazenado na variável 'numero'*/
	dobro = numero*2;
	quadrado = numero*numero;
	printf ("\nDobro de %i: %i\n", numero, dobro);
	printf ("\nQuadrado de %i: :%i\n", numero, quadrado);
	getch();/* Aguarda até que uma tecla seja pressionada */
	}

