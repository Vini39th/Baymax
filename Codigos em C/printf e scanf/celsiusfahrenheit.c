/*Bibliotecas utilizadas*/
#include <stdio.h>

/*Vari�veis globais*/
float celsius, fahrenheit;

/*Corpo do Programa*/
	main ()
	{
	printf ("\nInsira a temperatura em Celsius:"); /*Valor, em Celsius, da temperatura*/
	scanf ("%f" , &celsius); /*Valor armazenado na vari�vel 'celsius'*/
	fahrenheit = (celsius*1.8) + 32;
	printf ("\nTemperatura em Fahrenheit:%0.2f\n" ,fahrenheit);
	getch();/* Aguarda at� que uma tecla seja pressionada */
	}
