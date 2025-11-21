/*Descobrir bandeira do cartão através dos digitos do cartão usando switch*/
/*BIBLIOTECAS */
#include <stdio.h>

/*CORPO DO PROGRAMA*/

 int main ()
 {
   char primeiro_digito;
   char segundo_digito;
    
    printf("\nTESTANDO CARTÕES DE CRÉDITO\n\n");
    printf("Digite o primeiro digito do cartão: ");
    scanf(" %c", &primeiro_digito);
    
    printf("Digite o segundo digito do cartão: ");
    scanf(" %c", &segundo_digito);
 
    switch (primeiro_digito)
     {
         case '4': 
            printf("Cartão Visa\n");
            break;
 
         case '5':
            switch (segundo_digito) 
            {
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                    printf("Cartão Mastercard\n");
                    break;
                default:
                    printf("CARTÃO DE CRÉDITO NÃO ENCONTRADO\n");
                    break;
            }
            break;
 
         case '3':
            switch (segundo_digito)
            {
                case '4':
                case '7':
                    printf("Cartão American Express\n");
                    break;
                default:
                    printf("CARTÃO DE CRÉDITO NÃO ENCONTRADO\n");
                    break;
            }
            break;
 
         case '6':
            printf("Cartão Discover\n");
            break;
 
         default:
         printf("CARTÃO DE CRÉDITO NÃO ENCONTRADO\n");
         break;
    }
 
    return 0;
}

