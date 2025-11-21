/*BIBLIOTECAS*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
 
/*VARIÁVEIS*/
int f;
float p1, p2, t, m;
 
/*CORPO DO PROGRAMA*/
int main ()
{
printf("Digite suas faltas:");
fflush (stdin);
scanf("%i" , &f);
if( f>23)
   printf("\n\n RETIDO POR FALTAS");
else
{
printf("Digite nota de p1:");
fflush(stdin);
scanf("%f" , &p1);
printf("Digite nota de p2:");
fflush(stdin);
scanf("%f" , &p2);
printf("Digite nota de t:");
fflush(stdin);
scanf("%f" , &t);
m = (p1 + p2 + t) / 3;
printf("\n\nMEDIA = %.2f" , m );
}
getch();
return 0;
}

