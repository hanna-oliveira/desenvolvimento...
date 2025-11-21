/*BIBLIOTECAS*/
#include <stdio.h>
#include <locale.h>
#include <conio.h>


  int   condicao_pagamento; 
float preco_etiqueta, valor_pagar;

/*CORPO DO PROGRAMA*/
int main ()
 {
       setlocale(LC_ALL,"");
  
    
       printf("Codigo da condiçao de pagamento               Condiçao de pagamento:\n ");
getch();
       printf("---------------------------------------------------------------------------------------\n");
       printf("          1                         A vista em dinheiro ou cheque, com 10%% de desconto\n");
       printf("          2                         A vista com cartão de crédito, com 5%% de desconto\n");
       printf("          3                         Em 2 vezes, preço normal de etiqueta sem juros\n");
       printf("          4                         Em 3 vezes, preço de etiqueta com acréscimo de 10%%\n");
getch();

    printf("Digite o preço de etiqueta:");
    scanf("%f" , &preco_etiqueta);

    printf("Escolha a condição de pagamento:");
    scanf("%d" , &condicao_pagamento); 

   switch (condicao_pagamento)
   {
   case 1:
   valor_pagar = preco_etiqueta * 0.90; 
   printf("Valor a pagar: R$ %.2f\n", valor_pagar);
   break;

   case 2:
   valor_pagar = preco_etiqueta * 0.95;
   printf("Valor a pagar: R$ %.2f\n", valor_pagar);
   break;

   case 3:
   valor_pagar = preco_etiqueta;
   printf("Valor a pagar: R$ %.2f\n", valor_pagar);
   break;

   case 4:
   valor_pagar = preco_etiqueta * 1.10;
   printf("Valor a pagar R$ %.2f\n" , valor_pagar);
   break;

   default:
   printf("Condição de pagamento inválida. Tente novamente");
   break;

   }
   return 0
   ;
   }
   


