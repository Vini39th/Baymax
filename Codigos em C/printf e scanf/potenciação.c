/*Bibliotecas utilizadas*/
#include <stdio.h>
#include <conio.h>
#include <math.h>

/*Vari�veis globais*/
int base, expoente,potencia;

/*Corpo do Programa*/
	main ()
{	
	printf ("\nInsira o valor da base:"); /*Valor da base*/
	scanf ("%i" , &base); /* Valor inserido armazenado na vari�vel 'base'*/
	printf ("\nInsira o valor do expoente:"); /*Valor do expoente*/
	scanf ("%i" , &expoente); /* Valor inserido armazenado na vari�vel 'expoente'*/
	potencia = pow (base, expoente); /*f�rmula do volume da lata de �leo */
	printf ("\nPotencia(%i^%i):%i", base, expoente, potencia); /*Resultado da Potencia*/
	getch();/* Aguarda at� que uma tecla seja pressionada */
	}
