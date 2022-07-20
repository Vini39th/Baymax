/*IFSP-SP - TADS - LG1A1 - Prof� Eub - Projeto Drive Thru*/
/*Autorxs: Vinicius Gomes (SP3069192)*/

/*Bibliotecas utilizadas*/
#include <locale.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#define   MAX  4

/*Declara��o das Structs utilizadas*/
typedef struct
{
	int ItemNum;
	char ItemNome[30];
	float ItemValor;
	char Item [30];
	int NumQtde;
	float Custo;
}Apontamento;

typedef struct
{}Pgto;

typedef struct
{
	int ItemCart;
	char Cart_Num[17];
}Tarjeta;

/*Declara��o das Vari�veis Globais utilizadas*/

int Ped_Num;
int * Ped_Pointer;
int Pag_Option;
float * i; /*C�lculo Completo do Pedido*/
float Contador;

/*Declara��o dos Prot�tipos utilizados*/
void menucadastrar();
void menuprodutos();
void menupedido();
void menuprincipal ();
void menupagamento();
void menufila();
void tipopgto(int* Ped_Pointer);
void inventarioprodutos();
void delivery();

/*Corpo do Menu Principal*/
main()
{
	setlocale(LC_ALL, "");
	/*Declara��o das Vari�veis Locais utilizadas*/
	int  escolha;
	
		do	
		{
			system("color 0F");
			menuprincipal();
			printf("\t1. Inserir Itens\n");
			printf("\t2. Itens Dispon�veis\n");
			printf("\t3. Realizar Pedido\n");
			printf("\t4. Efetuar Pagamento\n");
			printf("\t5. Registro de Entrega\n");
			printf("\t6. Fila de Pedidos\n");
			printf("\t7. Finalizar Programa\n");
			printf("\n\tSelecione um n�mero (1 a 7): ");
			scanf("%d", &escolha);
			
			switch(escolha)
			{
				case 1:
				system("cls");
				menucadastrar();
				break;
				
				case 2:
				system("cls");
				inventarioprodutos();
				break;
				
				case 3:
				system("cls");
				menupedido();
				break;
				
				case 4:
				system("cls");
				tipopgto(Ped_Pointer);
				break;
				
				case 5:
				system("cls");
				delivery();
				break;
				
				case 6:
				system("cls");
				menufila();
				break;
				
				case 7:
				system("cls");
				printf("\n\n\n\t Grato pela Prefer�ncia\n\n\t Uma Divis�o do Seu Valdesnei\n");
				printf("\n      \n   PRESSIONE QUALQUER TECLA P/ ENCERRAR"  );
				getch();
				break;
			}
		} 
		while	(escolha != 7);
}

/*In�cio da Declara��o das Fun��es*/
void menuprincipal()
{
	system("cls");
	printf("\n__________________________________________\n");
    printf("       Mickey & Donald Restaurantes         \n");
	printf("__________________________________________  \n");
	printf("       Uma Divis�o do Seu Valdesnei         \n");
	printf("__________________________________________  \n\n");
}

void menuprodutos()
{
	system("cls");
	printf("__________________________________________  \n\n");
	printf("		ITENS		\n");
	printf("__________________________________________  \n\n");
}

void menupagamento()
{
	system("cls");
	printf("__________________________________________  \n\n");
	printf("             TIPO DE PAGAMENTO\n");
	printf("__________________________________________  \n\n");
}

/*Requisito de M�dulo de Vendas (�Fa�a seu pedido�)*/
/*Descri��o do Funcionamento do Menu de Cadastro*/
void menucadastrar()
{
	FILE * arq1;
	Apontamento REG;
	
	/*Funcionamento do Comando Append - dados adicionados ao fim do arquivo*/
	arq1 = fopen("PRODUTOS.DAT", "a");
		if(arq1 == NULL)
		{
			printf("\nErro ao abrir o arquivo DAT!");
		} 
		else
		{
			menuprodutos();
			
			/*Funcionamento da Contagem de Itens*/
			REG.ItemNum = system("MD_Contador_PRODUTOSDAT");
			printf ("\nN� do Item: %i", REG.ItemNum);
			
			fflush(stdin);
			printf("\nNomeie o Item: ");
			gets(REG.ItemNome);
			
			fflush(stdin);
			printf("\nInsira o valor desejado do Item R$ ");
			scanf("%f", &REG.ItemValor);
			
			fwrite(&REG, sizeof(REG), 1, arq1);
		}
		fclose(arq1);
}

/*Funcionamento do Invent�rio de Itens*/
void inventarioprodutos()
{
	FILE * arq2;
	Apontamento REG;
	
	/*Funcionamento do Comando Read - leitura*/
	arq2 = fopen("PRODUTOS.DAT", "r");
	menuprodutos();
	printf("__________________________________________  ");	
	printf ("\n N�Item		NomeItem	ValorItem	\n");
	printf("__________________________________________  ");
	
	if(arq2 == NULL)
	{
		printf("\nErro ao abrir o arquivo DAT!\n");
	}
	else 
	{
			/*Exibi��o para Alinhamento de Itens Cadastrados*/
			while(fread(&REG, sizeof(Apontamento), 1, arq2) == 1) 
			{
				printf ("\n%5d		%-17s R$%5.2f", REG.ItemNum, REG.ItemNome, REG.ItemValor);
				printf("\n__________________________________________  ");
			}
				printf ("\n   PRESSIONE QUALQUER TECLA P/ CONTINUAR");
	}
	fclose(arq2);
	getch();	
}

/*Execu��o do menu para solicita��o de pedidos*/
void menupedido()
{
	FILE * arq3;
	Apontamento REG;
	char Item [30];
	
	do
	{
	 	/*Funcionamento do Comando Read Binary - leitura de arquivo bin�rio*/
	 	arq3 = fopen("PRODUTOS.DAT", "rb");
	 	if (arq3 == NULL) 
		{
	 		printf("\nErro ao abrir o arquivo DAT!");
		}
		else
		{
		 	menuprodutos();
		 	inventarioprodutos();
		 	fflush(stdin);
		 	printf ("\n\n Insira o N� do pedido: "		);
		 	scanf("%d", &Ped_Num);
		 	Ped_Pointer = &Ped_Num;
		 	fflush(stdin);
		 	printf("__________________________________________\n");
		 	printf ("\n Insira o Nome do Item: "		);
		 	gets(Item);
			while(fread(&REG, sizeof(Apontamento), 1, arq3) == 1)
			{
				if(strcmp(Item, REG.ItemNome) == 0)
				{
					fflush(stdin);
					printf("\n__________________________________________  ");
					printf ("\n Digite a quantidade desejada: "		);
					scanf("%d", &REG.NumQtde);
					REG.Custo = (REG.NumQtde * REG.ItemValor);
					Contador += REG.Custo;
					printf("\n__________________________________________  ");
					printf("\n	N� do Item:	%d       ", REG.ItemNum);
					printf("\n__________________________________________  ");
					printf("\n	Nome do Item:	%s         ", REG.ItemNome);
					printf("\n__________________________________________  ");
					printf("\n	Pre�o Unit�rio:	R$ %.2f    ", REG.ItemValor);
					printf("\n__________________________________________  ");
					printf("\n	Qtde:		%d          ", REG.NumQtde);
					printf("\n__________________________________________  ");
					printf("\n	Valor do Item:	R$ %.2f            ", REG.Custo);
					printf("\n__________________________________________  ");
				}
			}
				printf("\n	Seguir inserindo Itens? (s/n)  ");
	 	}
	} 
	while (getche() == 's');
	fclose(arq3);
	printf("\n__________________________________________  ");
	printf("\n	Total de Compra:   R$ %.2f                    ", Contador);
	printf("\n__________________________________________  ");
	printf("\n      \n   PRESSIONE QUALQUER TECLA P/ CONTINUAR"  );
	getch();
}

/*Requisito de M�dulo de Cobran�a (�Pague�)*/
/*Descri��o do Funcionamento de Menu para Efetuar Pagamento de Itens*/
void tipopgto(int * Ped_Pointer)
{
	/*Cria��o do Pointer a ser utilizado*/
	FILE * arq4a;
	Apontamento REG;
	Pgto PGTO1;
	
	/*Funcionamento do Comando Append Binary - dados adicionados ao fim do arquivo bin�rio*/
	arq4a = fopen("PAGAMENTO.DAT", "ab");
	
	if(arq4a == NULL)
	{
		printf("\nErro ao abrir o arquivo DAT!");
	} 
	else
	{
		do
		{
			menupagamento();
			printf("\n__________________________________________  ");
			printf ("\n\n\tPedido N�: %3d \n\tTipo de Pagamento: ", Ped_Num);
			printf("\n__________________________________________  ");
			printf("\n\n\t1. Dinheiro\n");
			printf("\t2. Cart�o de Cr�dito/D�bito\n");
			printf("\t3. Cheque\n");
			printf("\t4. Retornar ao Menu Principal\n");
			printf("\n__________________________________________  ");
			fflush(stdin);
			printf("\n\tInsira o Tipo Solicitado: ");
			scanf("%d", &Pag_Option);
			
			switch(Pag_Option)
			{
				case 1:
				system("cls");
				menupagamento();
				printf("\n__________________________________________  ");
				printf("\n      PAGAMENTO EFETUADO COM SUCESSO            "  );
				printf("\n__________________________________________  ");
				printf("\nPedido N�\tTipo Pgto	Valor"    );
				printf("\n__________________________________________  ");
				printf("\n%6d\t\tDINHEIRO\tR$%.2f", Ped_Num, Contador);
				printf("\n      \n   PRESSIONE QUALQUER TECLA P/ CONTINUAR"  );
				break;
				
				case 2:
				system("cls");
				FILE * arq4b;
				int i, tamanho;
				Tarjeta NUM;
				NUM.ItemCart = 2;
				arq4b = fopen("CARTOES.DAT", "ab");
				if(arq4b == NULL)
				{
					printf("\nErro ao abrir o arquivo DAT!");
				}
				else
				{
					menupagamento();
					printf("\n__________________________________________  ");
					printf("\n__________________________________________  ");
					printf("\nPedido N�\tTipo Pgto	Valor"    );
					printf("\n__________________________________________  ");
					printf("\n%6d\t\tCART�O DE\tR$%.2f", Ped_Num, Contador);
					printf(" \n\t      CR�DITO/D�BITO");
					do
					{
						fflush(stdin);
						printf("\n__________________________________________  ");
						printf("\n\n Insira o n� do cart�o: "     );
						gets(NUM.Cart_Num);
						tamanho = strlen(NUM.Cart_Num);
						if (tamanho == 16)
						{
							printf("\n__________________________________________  ");
							printf("\n\n Cart�o Aceito! "      );
							for (i=0; i<tamanho; i++)
							{
								if ( i>3 && i<12 )
								NUM.Cart_Num[i] = '*';
							}
								printf("\n Cart�o Registrado: %s", NUM.Cart_Num);
								printf("\n__________________________________________  ");
								printf("\n\n      PAGAMENTO EFETUADO COM SUCESSO            "  );
								printf("\n      \n   PRESSIONE QUALQUER TECLA P/ CONTINUAR"  );
						}
						else
						{
							printf("\n N� de Cart�o Inv�lido! Repita a Opera��o \n");
						}
							fwrite(&NUM, sizeof(Tarjeta), 1, arq4b);
					}
					while(tamanho != 16);
					fclose(arq4b);	
				}
				break;
				
				case 3:
				system("cls");
				menupagamento();
				printf("\n__________________________________________  ");
				printf("\n      PAGAMENTO EFETUADO COM SUCESSO            "  );
				printf("\n__________________________________________  ");
				printf("\nPedido N�\tTipo Pgto	Valor"    );
				printf("\n__________________________________________  ");
				printf("\n%6d\t\tCHEQUE\t\tR$%.2f", Ped_Num, Contador);
				printf("\n      \n   PRESSIONE QUALQUER TECLA P/ CONTINUAR"  );
				break;
				
				default:
				system("cls");
				printf("\n\n\n\t   N�MERO INDISPON�VEL!\n");
				printf("\n      \n   PRESSIONE QUALQUER TECLA P/ RETORNAR"  );
				break;		
			}
			fwrite(&REG, sizeof(Apontamento), 1, arq4a);
		}
		while (getch() == '4');
		fclose(arq4a);
	}
}

/*Requisito de M�dulo de Espera (�Fila�)*/
/*Descri��o do Funcionamento de Menu para gerenciamento de fila*/
void menufila()
{
	/*Declara��o das Vari�veis Locais*/
	int fila[MAX];
	int ini, fim;
	int ped, i, j, limite;
	char opc;
	
	/*In�cio das Atividades do Restaurante com Fila Vazia (ini=fim)*/
	setlocale (LC_ALL, "");
	ini = fim = 0;
    ped;
    
	do
	{
		system("cls");
		printf("__________________________________________  \n\n");
		printf("		FILA		\n");
		printf("__________________________________________  \n\n");
		printf ("\n    1. Adicionar Pedido ");
		printf ("\n    2. Visualizar Fila ");
		printf ("\n    3. Atender Fila   ");
		printf ("\n    4. Retornar ao Menu Principal");
		printf ("\n    Selecione: "); fflush (stdin); opc=getche(); getch();

        switch (opc)
		{
			case '1':
			printf ("\n    Pedido N�: "); fflush (stdin); scanf ("%i", &ped);
	    	printf ("\n    Inserir na Fila? (s/n) ");
	    	fflush (stdin); opc = getche(); getch();
	    	if (opc == 's' || opc == 'S')
	    	{
	    		/*Insere � fila caso n�o esteja lotada*/
	    		if ( fim==MAX )
	    		{
	    			printf ("\n    Fila lotada!!!!!");
	    			printf ("\n    PRESSIONE QUALQUER TECLA P/ CONTINUAR");
	    			getch();
				}
				else
					{
	    				fila[fim] = ped;
	    				fim++;
	    			}
			}
			ped++;
			break;
			
			case '2': 	
			// Exibi��o da Fila
			printf ("\n\n\n    Pedidos na fila:\n");
			for (i=ini; i<fim; i++)
			printf ("    [%i]", fila[i]);
			printf ("\n    PRESSIONE QUALQUER TECLA P/ CONTINUAR");
			getch();
			break;
			
			case '3':
			// Atende algu�m da fila DESDE QUE A FILA N�O ESTEJA VAZIA
			if ( ini==fim )
			{   
			   printf ("\n    Fila vazia!");
			   printf ("\n    PRESSIONE QUALQUER TECLA P/ CONTINUAR");
			   getch();
			   ini = fim = 0;
			}
			else
			{
				printf ("\n    Pedido atendido:[%i]", fila[ini]);
				printf ("\n    PRESSIONE QUALQUER TECLA P/ CONTINUAR");
				
				ini++; /* Avan�o o ini para preparar para o pr�ximo atendimento */
				limite = fim;
				/*Condi��o para que a fila mova-se para o In�cio*/
				for (j=1; j<limite; j++)
				{
				   fila[j-1]=fila[j];
				}
				ini=0;
				fim--;
			}
			getch();
			break;
		}	
	}
	while (opc!='4');	
}

/*Requisito de M�dulo de Entrega (�Leve�)*/
/*Execu��o do Registro de Entrega dos Itens e dados de pagamento*/
void delivery()
{
	/*Cria��o do Pointer a ser utilizado*/
	FILE * arq5;
	Apontamento REG;
	int pague;
	
	/*Funcionamento do Comando Read Binary - leitura de arquivo bin�rio*/
    arq5 = fopen("PAGAMENTO.DAT", "rb");
	if(arq5 == NULL)
	{
		printf("\nErro ao abrir o arquivo DAT!");
	}
	else
	{
		if(Pag_Option == 1)
		{
		    system("cls");
		    system("color 0A");
		    printf("\n\n\n\n\tPEDIDO [%d] PAGO COM \n\t     DINHEIRO\n", Ped_Num);
		    getch();
		}
		if(Pag_Option == 2)
		{
		    system("cls");
		    system("color 0D");
		    printf("\n\n\n\n\tPEDIDO [%d] PAGO COM \n\t     CART�O\n", Ped_Num);
		    getch();
		}
		if(Pag_Option == 3)
		{
		    system("cls");
		    system("color 09");
		    printf("\n\n\n\n\tPEDIDO [%d] PAGO COM \n\t      CHEQUE\n", Ped_Num);
			getch();
		}
	}
	fclose(arq5);
}
/*Fim da Declara��o das Fun��es*/
