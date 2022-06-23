/*Bibliotecas utilizadas*/
#include <stdio.h>

/*Variáveis globais*/
float bruto, liquido, IR, previdencia;

/*Corpo do Programa*/
	main ()
{	
	printf("Insira o salario bruto:"); /*Valor salário bruto*/
	scanf("%f", &bruto); /*Valor inserido armazenado na variável 'bruto'*/
	previdencia = (bruto*0.085); /*Cálculo da Previdência*/
	IR = (bruto - previdencia) * 0.275; /*Cálculo do IR*/
	liquido = bruto - previdencia - IR; /*Cálculo do salário líquido*/
	printf("\nSalario liquido:R$%0.2f", liquido); /*Valor salário líquido*/
	printf("\nPrevidencia:R$%0.2f", previdencia); /*Valor previdência*/
	printf("\nIR:R$%0.2f", IR); /*Valor Imposto de Renda*/
	getch();/* Aguarda até que uma tecla seja pressionada */
}
