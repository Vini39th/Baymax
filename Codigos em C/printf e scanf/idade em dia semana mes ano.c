/*Bibliotecas utilizadas*/
#include <stdio.h>

/*Variáveis globais*/
int anonascimento, idade, idademeses, idadedias, idadesemanas;

/*Corpo do Programa*/
	main ()
{	
	printf("Insira o ano de nascimento:"); /*Valor ano nascimento*/
	scanf("%i", &anonascimento); /*Valor inserido armazenado na variável 'anonascimento'*/
	idade = 2022 - anonascimento; /*Cálculo da idade em anos*/
	idademeses = idade * 12;
	idadedias = idade * 365;
	idadesemanas = idade * 52;
	printf("\nIdade:%i", idade); /*Total Idade Anos*/
	printf(" anos"); /*Em anos*/
	printf("\nIdade:%i", idademeses, "meses"); /*Total Idade Meses*/
	printf(" meses"); /*Em meses*/
	printf("\nIdade:%i", idadedias, "dias"); /*Total Idade Dias*/
	printf(" dias"); /*Em dias*/
	printf("\nIdade:%i", idadesemanas, "semanas"); /*Total Idade Semanas*/
	printf(" semanas"); /*Em semanas*/
	getch();/* Aguarda até que uma tecla seja pressionada */
}
/*Obs: Ano atual considerado: 2021*/
