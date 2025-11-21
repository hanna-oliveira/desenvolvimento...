/*Descobrir bandeira do cartão através dos digitos do cartão usando if-else*/

/*BIBLIOTECAS*/
 #include <stdio.h>

/*CORPO DO PROGRAMA */
int main ()
{   
    char primeiro_digito;
    char segundo_digito;

    printf("\nTESTANDO CARTÕES DE CRÉDITO\n\n");
    printf("Digite o primeiro digito do cartão:");
    scanf("%c" , &primeiro_digito);
    getchar();

    printf("Digite o segundo digito do cartão:");
    scanf ("%c" , &segundo_digito);
    
    if(primeiro_digito == '4' )
    {
    printf("Cartão de crédito Visa\n");
    } 
   else if ((primeiro_digito == '5' && (segundo_digito >= '1' && segundo_digito <= '5')) || primeiro_digito == '2')
    {
    printf("Cartão de crédito Mastercard\n");
    }
    else if (primeiro_digito == '3' && (segundo_digito == '4' || segundo_digito == '7'))
    {
        printf("Cartão de crédito American Express\n");
    } 
    else if (primeiro_digito == '6' )
    {
        printf("Cartão de crédito Discover\n");
    } 
    else
    {
      printf("CARTÃO DE CRÉDITO NÃO IDENTIFICADO\n");
    }

    return 0;
}  