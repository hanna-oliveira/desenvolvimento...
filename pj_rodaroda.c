/*bibliotecas utilizadas*/
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <math.h>
#include <windows.h> /*para a função sleep()*/
#include <time.h> /*função time() no momento do sorteio*/

/*dados pré-definidos*/
typedef struct { /*estrutura do PALAVRAS.DAT*/
    char pista [16+1]; /*pista para a palavra*/
    int qtd_palavras; /*quantidade de palavras*/
    char palavras [3][16+1]; /*palavras associadas a pista*/
} registro; /*registro das palavras*/

typedef struct { /*estrutura do PREMIOS.DAT*/
    float  premio; /*valor do premio*/
} reg_premios; /*registro dos premios*/

/*variáveis globais*/
registro   reg; /*registro  de palavras*/
FILE      *arq;  
char       opc; 
int        i; /*variável da captura de dados*/

/*construção das funções*/
void premiosdefault (void){ /*função para criar o arquivo de prêmios*/
    reg_premios  premios[12] = {/*vetor de 12 elementos*/
    {100.00},
    {900.00},
    {600.00},
    {1000.00},
    {0.00},
    {400.00},
    {200.00},
    {800.00},
    {0.01},
    {300.00},
    {500.00},
    {700.00}
};
/*cria um arquivo chamado PREMIOS.DAT*/
arq = fopen ("PREMIOS.DAT" , "w+b"); /*cria arquivo binário para leitura e escrita*/
if (arq == NULL)
{
    printf("\nERRO ao criar PREMIOS.DAT\n");
    getch();
    exit(0);
}
/*grava os registros dos prêmios*/
fwrite (&premios , sizeof (premios), 1, arq);
if ( ferror(arq))
{
    printf("\nERRO ao gravar em PREMIOS.DAT\n");
    getch();
    exit(0);
}
/*fecha o arquivo*/
fclose(arq);
printf("\nPREMIOS.DAT criado com sucesso!");
getch();
}

void mostrapremios (void) {
    reg_premios premio;
    arq = fopen ("PREMIOS.DAT" , "r+b"); /*abre o arq binário para leitura*/
    if(arq == NULL) {
        printf("\nERROR ao abrir PREMIOS.DAT\n");
        getch();
        exit(0);
    }
/*exibição dos prêmios*/
system ("cls");
printf("\n-----------PRÊMIOS----------------\n");

/*para ler os prêmios*/
while (fread (&premio, sizeof (premio), 1, arq)){
if (ferror (arq)){
    printf("\nERRO ao ler PREMIOS.DAT\n");
    getch();
    exit(0);
}
    printf("\n\tR$%10.2f\n" , premio.premio);
  }

fclose(arq); /*fecha arquivo*/
printf("\n-------------------------------\n");
getch();
}
void limpareg (void) /*para limpar o registro de palavras*/
{  
   strcpy(reg.pista , ""); /*limpa a pista*/
   reg.qtd_palavras = 0; /*zera o valor da quantidade de palavras*/
   strcpy (reg.palavras[0], "");/*limpa o primeiro elemento do vetor, copiando string vazia para ele*/
   strcpy (reg.palavras[1], "");
   strcpy (reg.palavras[2], "");
}
 void capturadados (void)
 {    
     printf("\nDigite a pista:"); /*captura dados do registro das palavras*/
     fflush(stdin); gets(reg.pista);

     printf("\nDigite a quantidade de palavras (1 a 3):");
     fflush(stdin); scanf("%i", &reg.qtd_palavras );

for (i=0; i<reg.qtd_palavras; i++ )
{
    printf("\nDigite a palavra:");
    fflush(stdin); gets(reg.palavras[i]);
    }
 }
void gravadados (void)
{ system ("cls");
  do
  {  capturadados(); /*captura dados do registro da palavras*/
     arq = fopen ("PALAVRAS.DAT" , "w+b"); /*sobrescreve o arquivo*/
     if (arq == NULL){
        printf("ERRO ao abrir PALAVRAS.DAT");
        getch();
        exit(0);
        }
     fwrite (&reg , sizeof(reg) , 1 , arq); /*grava o registro no arquivo*/
     if (ferror(arq)){
     printf("ERROR ao gravar em PALAVRAS.DAT");
     getch();
     exit(0);    
     }
     fclose (arq);

     /*para gravar outro registro*/
     printf("\nGravar outro registro? [n/N= não]:");
     fflush(stdin); 
     opc= getche();
   }
while (opc!= 'n' && 'N');
}

void consultadados (void) 
{ system("cls");
  arq = fopen ("PALAVRAS.DAT" , "r+b"); /*para ler o arquivo*/
  if (arq ==NULL){
  printf("ERRO ao abrir PALAVRAS.DAT");
  getch();
  exit(0);
  }
while (fread (&reg , sizeof(reg) , 1 , arq)){/*lê cada registro*/
    if (ferror(arq))
    {
        printf("\nERRO ao ler PALAVRAS.DAT");
        getch();
        exit(0);
    }
        printf("\n%-18s %i %-18s %-18s %-18s",
                  reg.pista, reg.qtd_palavras,
            reg.palavras[0],
            reg.palavras[1], reg.palavras[2]);             
    }
    fclose(arq);
    getch();
 }

void rodaRoda() /*função principal do jogo*/
{
    srand(time(NULL)); /*inicia a geração da sequência de números aleatórios*/

    limpareg();

    arq = fopen("PALAVRAS.DAT", "r+b"); /*para abrir o arquivo*/
    if (arq == NULL) {
        printf("ERRO ao abrir PALAVRAS.DAT");
        getch();
        exit(0);
    }

    /*para contar quantos registros o arquivo possui*/
    fseek(arq, 0, SEEK_END); /*move o ponteiro para o final do arquivo*/
    int totalRegistros = ftell(arq) / sizeof(registro); /*obtém o tamanho total do arquivo em bytes*/
    fseek(arq, 0, SEEK_SET);

    /*para sortear um registro dentro dos limites*/
    int sorteio = rand() % totalRegistros;
    fseek(arq, sorteio * sizeof(registro), SEEK_SET);
    fread(&reg, sizeof(registro), 1, arq);
    fclose(arq);

    /*para exibir a pista e a palavra escondida*/
    system("cls");
    printf("\nA palavra está associada a: %s\n", reg.pista); /*Exibe a pista*/

    /*Variáveis para controle do jogo*/
    char palavraAtual[16+1]; /*Palavra atual sendo jogada*/
    strcpy(palavraAtual, reg.palavras[0]); /*Usa a primeira palavra do registro*/
    int tamanhoPalavra = strlen(palavraAtual);
    char palavraEscondida[16+1]; /*Palavra escondida com traços*/
    for (i = 0; i < tamanhoPalavra; i++) {
        palavraEscondida[i] = '-'; /*Usa traços para esconder a palavra*/
    }
    palavraEscondida[tamanhoPalavra] = '\0';

    /*Exibe a palavra escondida com traços*/
    printf("\n\t%s\n", palavraEscondida); /*Exibe a palavra escondida*/

    /*para inicializar os jogadores*/
    float jogadores[3] = {0.0, 0.0, 0.0}; /*saldos respectivos*/
    int jogadorAtual = 0; /*para jogador 1 começar a partida*/

    /*loop do jogo*/
    while (1) {
        /*Exibe os jogadores e seus saldos*/
        printf("\nJogador 1\tJogador 2\tJogador 3");
        printf("\n========\t=========\t=========");
        printf("\nR$ %.2f \tR$ %.2f   \tR$ %.2f", jogadores[0], jogadores[1], jogadores[2]);
        
        /*sorteio de um prêmio*/
        arq = fopen("PREMIOS.DAT", "r+b");
        if (arq == NULL) {
            printf("ERRO AO ABRIR PREMIOS.DAT");
            getch();
            exit(0);
        }
        fseek(arq, 0, SEEK_END); /*move o ponteiro pro final do arq*/
        int totalPremios = ftell(arq) / sizeof(reg_premios); /*obtém o tamanho do arq*/
        
        int sorteioPremio = rand() % totalPremios;
        fseek(arq, sorteioPremio * sizeof(reg_premios), SEEK_SET);
        reg_premios premio;
        fread(&premio, sizeof(reg_premios), 1, arq);
        fclose(arq);
        
        printf("\n\nRode a roda!");
        getche();
        printf("\n\nUma letra valendo: R$%.2f\n", premio.premio);
        

        /*funcionalidade passa a vez / perde tudo*/
        if (fabs(premio.premio - 0.00) < 0.0001) { /*fabs para comparar os valores*/
            printf("\nPASSA A VEZ!\n");
            Sleep(2000);
            jogadorAtual = (jogadorAtual + 1) % 3; /*passa a vez próx jogador*/
            continue;
        } else if(fabs(premio.premio - 0.01)<0.0001) {
            printf("\nPERDE TUDO!\n");
            Sleep(2000);
            jogadores[jogadorAtual] = 0.00; /*zera saldo do jogador atual*/
            jogadorAtual = (jogadorAtual + 1) % 3; /*passa a vez*/
            continue;
        }

        /*para solicitar uma letra ao jogador*/
        char letra;
        printf("\nJogador %d, digite uma letra: ", jogadorAtual + 1);
        fflush(stdin);
        letra = getche();

        /*para verificar se a letra está na palavra*/
        int acertos = 0;
        for (i = 0; i < tamanhoPalavra; i++) {
            if (palavraAtual[i] == letra) {
                palavraEscondida[i] = letra;
                acertos++;
            }
        }

        /*Exibe a palavra escondida atualizada*/
        system("cls");
        printf("\n %s\n", palavraEscondida);  // Mostra a palavra escondida após a tentativa
        
        /*atualização do saldo*/
        if (acertos > 0) {
            jogadores[jogadorAtual] += premio.premio * acertos;
            printf("\nLetra correta! Saldo atual: R$%.2f\n", jogadores[jogadorAtual]);
            Sleep(2000);
        } else {
            printf("\nLetra incorreta! Passa a vez.\n");
            jogadorAtual = (jogadorAtual + 1) % 3; /*vez do próx*/
            Sleep(2000);
        }

        /*Verifica se a palavra foi completada*/
        if (strcmp(palavraAtual, palavraEscondida) == 0) {
            printf("\nParabéns! A palavra foi completada.\n");
            printf("\nJogador %d venceu a rodada com R$%.2f!\n", jogadorAtual + 1, jogadores[jogadorAtual]);
            Sleep(2000);
            break;
        }

        /*Contagem regressiva para adivinhar a palavra quando faltam 3 letras ou menos*/
        int letrasFaltantes = 0;
        for (i = 0; i < tamanhoPalavra; i++) {
            if (palavraEscondida[i] == '-') {
                letrasFaltantes++;
            }
        }
        if (letrasFaltantes <= 3) {
            printf("\nFaltam %d letras. Você tem 5 segundos para adivinhar a palavra...\n", letrasFaltantes);
            for (i = 5; i > 0; i--) {
                printf("%d...", i);
                Sleep(1000); /*Aguarda 1 segundo*/
            }

            char tentativa[16 + 1];
            printf("\nDigite a palavra: ");
            fflush(stdin);
            gets(tentativa);

            if (strcmp(tentativa, palavraAtual) == 0) {
                printf("\nParabéns! Você acertou a palavra.\n");
                jogadores[jogadorAtual] += premio.premio * letrasFaltantes;
                printf("\nJogador %d venceu com R$%.2f!\n", jogadorAtual + 1, jogadores[jogadorAtual]);
                Sleep(2000);
                break;
            } else {
                printf("\nPalavra incorreta. Passa a vez!\n");
                Sleep(2000);
                jogadorAtual = (jogadorAtual + 1) % 3; /*passa a vez*/
            }
        }
    }
}
/*corpo do programa*/
int main ()  { 
    setlocale(LC_ALL, "");

    do { /*menu de opções*/
    system("cls");
    printf
    ("\n===========================================");
    printf("\n      MENU DE OPÇÕES");
    printf
    ("\n===========================================");
    printf("\n       1.Gravar dados");      
    printf("\n       2.Consultar dados"); 
    printf("\n       3.Cadastro default de premios"); 
    printf("\n       4.Mostrar premios"); 
    printf("\n       5.Jogar");
    printf("\n       S.Sair");  
    printf("\n======================================="); 
           printf("\n            Sua opção:");
           fflush(stdin); 
           opc=getche();

           switch (opc)
           {
               case '1': gravadados(); 
            break;   
               case '2': consultadados();
            break;   
               case '3': premiosdefault();
            break;   
               case '4': mostrapremios();
            break;  
               case '5': rodaRoda(); 
            break; 
               case 'S':
               case 's': exit(0);
            break;   
               default:
               {
                   printf("ERRO!!!!!!!!");
                   getch();
               }
           }
    }
    while ( opc != 'S' && opc != 's');
       
    return 0;
} 