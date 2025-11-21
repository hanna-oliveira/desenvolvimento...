/*Programa para classificar produtos através de seu código de classificação*/
/*BIBLIOTECA A SER INCLUIDA*/
#include <stdio.h>
#include <conio.h>
#include <locale.h>
/*CORPO DO PROGRAMA*/
int main()
{

int codigo;

setlocale(LC_ALL,"");

  printf("-------------------\t -----------------------------\n");
  printf("Código\t\t                  Classificação\n");
  printf("-------------------\t -----------------------------\n");
  getch();
  printf("  1                         Alimento não-perecível\n");
  printf("  2, 3 ou 4                 Alimento perecível\n");
  printf("  5 ou 6                    Vestuário\n");
  printf("  7                         Higiene pessoal\n");
  printf("  8, 9 ou 10                Utensílios domésticos\n");
  getch();

  printf("Digite o código do produto:");
  scanf("%d" , &codigo);

switch (codigo)
{
case 1:
 printf("Alimento não perecível\n");
    break;

case 2:
case 3:
case 4:
 printf("Alimento perecível\n");
   break;

case 5:
case 6:
 printf("Vestuário\n");
  break;

case 7:
 printf("Higiene pessoal");
  break;

case 8:
case 9:
case 10:
 printf("Utensílios domésticos");
  break; 

default:
 printf("Classificação desconhecida");
    break;

    return 0;
}
}

