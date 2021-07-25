#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
  srand(time(NULL));
  

// variaveis acumuladora de soma.
  int soma1 =0; //jogador 1
  int soma2 =0; //jogador 2

// quem vai ser o primeiro a jogar.
 char primeiroAJogar[10]=" ";
 char segundoAJogar[10]=" ";

//Posição armazenar Posição
 int posicaoPrimeiroAjogar = 0; 
 int posicaoSegundoAjogar = 0; 

 //vidas
 int vidaPrimeiroJogador = 10;
 int vidaSegundoJogador = 10;

 //Pular vez 
 int PularvezP1 = 0;
 int PularvezP2 = 0;

// Variavel usado no scanf pra armazenar os enter.
  char jogada;

 //
 int posicaoPrimeiroAjogarMapa = 0;
 int posicaoSegundoAjogarMapa = 0;

   
 
// Caso dê empate ele repete. Ele so sai desse while quando um for maior que outro.
 while(soma1 == soma2)
 {
   printf("\n  ** Bem vindo ao jogo THE MAZE RUNNER!\n\n" );

   printf(" O objetivo de cada jogador é chegar ao ‘fim’ vivo.\n\n");

   printf("*Para Inicar o jogo, cada jogador lança  dois dados, o jogador que obtiver a maior soma dos valores dos dois dados começa.\n\n");
   printf("            Boa sorte!\n\n");

   printf("Jogador1 digite enter para lançar os dados: ");
   scanf("%c",&jogada);

   int dado1 = 1+ rand() % 6;
   int dado2 = 1+ rand() % 6;

   soma1=dado1+dado2;

   printf("Jogador 1: seus dados foram %i e %i , a soma eh %i.",dado1,dado2,soma1);

  printf("\n________________________________________________________");
  printf("\n");

  printf("Jogador 2: digite enter para lançar os dados: ");
   scanf("%c",&jogada);

   int dado3 = 1+ rand() % 6;
   int dado4 = 1+ rand() % 6;

   soma2=dado3+dado4;

   printf("Jogador 2:  seus dados foram %i e %i , a soma eh %i.",dado3,dado4,soma2);

   printf("\n________________________________________________________");
   printf("\n");

   if(soma2 != soma1)
   {
     break;
   }
     
 }
// condição de quem vai ser o primeiro jogar.

if(soma1>soma2)
{
	// usado a biblioteca STRING, e a função strcpy, para que o vetor receba quem é o primeiro a jogar,
	// já que não pode usar atribução =".
  strcpy(primeiroAJogar, "Jogador1");  
  strcpy(segundoAJogar, "Jogador2");

}else
{
  strcpy(primeiroAJogar, "Jogador2");
  strcpy(segundoAJogar, "Jogador1");
}
// criando o mapa com as casas das cores.
char mapa[29]={'i','w','r','g','w','b','w','y','w','r','g','p','b','w','w','r','g','w','y','w','r','g','w','b','r','y','g','f'};

// Um for infinito, a condição de parada é um dos IF.
for(;;)
{ // atribuindo as condições de jogo ao PRIMEIRO JOGADOR.

  if(PularvezP1 == 1)
  {
    PularvezP1=0;
  }
  else if(PularvezP1==0)
  {
    char pergunta;
    printf("%s Digite enter para lançar o dado:",primeiroAJogar);
    scanf("%c",&jogada);

    int dadoJogada = 1 +rand() %6;
    posicaoPrimeiroAjogar += dadoJogada;
    

    //Se o dado dê maior que 27 que acbaba as peças, recebe a posição 27.
    if(posicaoPrimeiroAjogar>27)
    { 
      posicaoPrimeiroAjogar = 27;

      if(posicaoPrimeiroAjogar==27)
      {
        printf("Parabéns %s, voce tirou %i no dado e venceu, chegou ao final do mapa!", primeiroAJogar, dadoJogada);
        break;
      }
    }
    posicaoPrimeiroAjogarMapa = mapa[posicaoPrimeiroAjogar];
    printf("O %s tirou o numero %i no dado, e está na posição %i ", primeiroAJogar,dadoJogada,posicaoPrimeiroAjogar);

    if(posicaoPrimeiroAjogarMapa == 'w')
    {
      printf("O jogador parou na casa branca, zona neutra, nada acontecerá.");
    }
    else if(posicaoPrimeiroAjogarMapa == 'r')
    {
      vidaPrimeiroJogador = vidaPrimeiroJogador -3;
      printf("Você parou na casa vermelha, perdeu 3 de hp,seu novo hp é de %i.",vidaPrimeiroJogador);

      if(vidaPrimeiroJogador <= 0)
      {
        printf("Jogador 1, sua vida acabou. VocÊ não conseguiu sair vivo do labirinto!");
        break;
      }
    }
    else if(posicaoPrimeiroAjogarMapa == 'g')
    {
      if(vidaPrimeiroJogador==10)
      {
        printf("Você parou na casa verde,aqui você recupera 1 de HP, porém seu HP está no máximo.");
      }    
      else
      {
        vidaPrimeiroJogador += 1;
        printf("VocÊ parou na casa verde, recuperou 1 de HP, seu novo HP é %i",vidaPrimeiroJogador);
      }
    }
    else if(posicaoPrimeiroAjogarMapa == 'y')
    {
      PularvezP1 = 1;
      printf("Você caiu na casa amarela, sua próxima vez será pulada.");
    }
    else if(posicaoPrimeiroAjogarMapa == 'b')
    {
      PularvezP2 = 1;
      printf("Você parou na casa azul, jogue mais uma vez.");
    }
    else if(posicaoPrimeiroAjogarMapa == 'p')
    {
      posicaoPrimeiroAjogar = 0;
      posicaoPrimeiroAjogarMapa = mapa[0];
      printf("Você parou na casa preta,retornou a posição inicial do jogo.");
    }
  }
  printf("______________________________________");
  printf("\n");
  
  //Condiçoes para o segundo Jogador
  	
  if(PularvezP2 == 1)
  {
    PularvezP2=0;
  }
  else if(PularvezP2==0)
  {
    char pergunta2;
    printf("%s Digite enter para lançar o dado:",segundoAJogar);
    scanf("%c",&jogada);

    int dadoJogada = 1 +rand() %6;
    posicaoSegundoAjogar += dadoJogada;

    //Se o dado dê maior que 27 que acbaba as peças, recebe 27.
    if(posicaoSegundoAjogar>27)
    { 
      posicaoSegundoAjogar = 27;

      if(posicaoSegundoAjogar==27)
      {
        printf("Parabéns %s, voce tirou %i no dado e venceu, chegou ao final do mapa!\n", segundoAJogar, dadoJogada);
        break;
      }
    }
    posicaoSegundoAjogarMapa = mapa[posicaoSegundoAjogar];
    printf("O %s tirou o numero %i no dado, e está na posição %i \n", segundoAJogar,dadoJogada,posicaoSegundoAjogar);

    if(posicaoSegundoAjogarMapa == 'w')
    {
      printf("O jogador parou na casa branca, zona neutra, nada acontecerá.\n");
    }
    else if(posicaoSegundoAjogarMapa == 'r')
    {
      vidaSegundoJogador = vidaSegundoJogador -3;
      printf("Você paraou na casa vermelha, perdeu 3 de hp,seu novo hp é de %i.\n",vidaSegundoJogador);

      if(vidaSegundoJogador <= 0)
      {
        printf("Jogador 2, sua vida acabou. VocÊ não conseguiu sair vivo do labirinto!");
        break;
      }
    }
    else if(posicaoSegundoAjogarMapa == 'g')
    {
      if(vidaSegundoJogador == 10)
      {
        printf("Você parou na casa verde,aqui você recupera 1 de HP, porém seu HP está no máximo.\n");
      }
      else
      {
        vidaSegundoJogador += 1;
        printf("VocÊ parou na casa verde, recuperou 1 de HP, seu novo HP é %i.\n",vidaSegundoJogador);
      }
    }
    else if(posicaoSegundoAjogarMapa == 'y')
    {
      PularvezP2 = 1;
      printf("Você caiu na casa amarela, sua próxima vez será pulada.\n");
    }
    else if(posicaoSegundoAjogarMapa == 'b')
    {
      PularvezP1 = 1;
      printf("Você parou na casa azul, jogue mais uma vez.\n");
    }
    else if(posicaoSegundoAjogarMapa == 'p')
    {
      posicaoSegundoAjogar = 0;
      posicaoSegundoAjogarMapa = mapa[0];
      printf("Você parou na casa preta,retornou a posição inicial do jogo.\n");
    }
  }
  printf("_____________________________________________");
  printf("\n");

}
  return 0;
}