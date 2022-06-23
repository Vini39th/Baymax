/*Bibliotecas utilizadas*/
#include <stdio.h>

/*Variáveis globais*/
float celsius, fahrenheit;

/*Corpo do Programa*/
	main ()
	{
	printf ("\nInsira a temperatura em Celsius:"); /*Valor, em Celsius, da temperatura*/
	scanf ("%f" , &celsius); /*Valor armazenado na variável 'celsius'*/
	fahrenheit = (celsius*1.8) + 32;
	printf ("\nTemperatura em Fahrenheit:%0.2f\n" ,fahrenheit);
	getch();/* Aguarda até que uma tecla seja pressionada */
	}
