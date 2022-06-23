/*Bibliotecas utilizadas*/
#include <stdio.h>
#include <conio.h>
#include <math.h>

/*Variáveis globais*/
int base, expoente,potencia;

/*Corpo do Programa*/
	main ()
{	
	printf ("\nInsira o valor da base:"); /*Valor da base*/
	scanf ("%i" , &base); /* Valor inserido armazenado na variável 'base'*/
	printf ("\nInsira o valor do expoente:"); /*Valor do expoente*/
	scanf ("%i" , &expoente); /* Valor inserido armazenado na variável 'expoente'*/
	potencia = pow (base, expoente); /*fórmula do volume da lata de Óleo */
	printf ("\nPotencia(%i^%i):%i", base, expoente, potencia); /*Resultado da Potencia*/
	getch();/* Aguarda até que uma tecla seja pressionada */
	}
