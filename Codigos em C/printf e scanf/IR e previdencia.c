/*Bibliotecas utilizadas*/
#include <stdio.h>

/*Vari�veis globais*/
float bruto, liquido, IR, previdencia;

/*Corpo do Programa*/
	main ()
{	
	printf("Insira o salario bruto:"); /*Valor sal�rio bruto*/
	scanf("%f", &bruto); /*Valor inserido armazenado na vari�vel 'bruto'*/
	previdencia = (bruto*0.085); /*C�lculo da Previd�ncia*/
	IR = (bruto - previdencia) * 0.275; /*C�lculo do IR*/
	liquido = bruto - previdencia - IR; /*C�lculo do sal�rio l�quido*/
	printf("\nSalario liquido:R$%0.2f", liquido); /*Valor sal�rio l�quido*/
	printf("\nPrevidencia:R$%0.2f", previdencia); /*Valor previd�ncia*/
	printf("\nIR:R$%0.2f", IR); /*Valor Imposto de Renda*/
	getch();/* Aguarda at� que uma tecla seja pressionada */
}
