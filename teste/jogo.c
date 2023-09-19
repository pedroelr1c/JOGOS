#include "jogo.h"

#define limite 2

char resp;
int i=0;
int j;

void menu(){
    int opc;

    printf("(1) JOGAR\n(2) PLACARES\n(3) SAIR\n");
    scanf("%d",&opc);
    getchar();
    system("clear");
    switch (opc){
    case 1:
        perguntas_1();
        system("clear");
        break;
    case 2:
        system("clear");
        printf("PLACARES INDISPONIVEL!\n");
        scanf("%d",&opc);
        getchar();
        system("clear");
        menu();
    case 3:
        printf("OBRIGADO POR JOGAR!\n");
        exit(1);
    default:
        system("clear");
        menu();
        break;
    }
}

void RandomizarNumeros(int* al){
    int igual;
    
    // Gerando numeros aleatorios que vai ser usado para escolher as perguntas.
    do{
        al[i] = rand() % 4; // A posição do vetor vai receber um número aleatorio entre 0 e 4.
        igual=0; // variavel para comparar se o numero já foi escolhido. 
        for(j=0;j<i;j++){
            if(al[j]==al[i]){// compara o elemento atual do vetor com o antigo.
                igual=1; // define que são iguais.
            }
        }
        if(igual==0){ // se nao for igual repete a geração de numeros.
            i++;
        }
    }while(i<limite);


}

void perguntas_1(){
    
   int igual;
    int *al=(int*)malloc(sizeof(int));
    int pontos=0;

    RandomizarNumeros(al);

    
    
    do{

       i=0;

        printf("(%d)\n", al[i]); // testando escolha de numeros.
        switch(al[i]){
            case 0:
            
                printf("EM QUE ANO FOI CRIADO A LINGUAGEM C?\n\n");
                printf("A - 1972\nB - 1980\nC - 2000\nD - 1970\n>> ");
                scanf("%c", &resp);
                getchar();
                if((resp=='a') || (resp=='A')){
                    printf("RESPOSTA CORRETA!\n");
                    pontos+=50;
                }else{
                    Errado(&pontos);
                }
                break;
            
            case 1:
            
                printf("QUAL A BIBLIOTECA QUE POSSIBILITA A UTILIZAÇÃO DA FUNCÃO:\nSCANF E PRINTF, EM C?\n");
                printf("A - string.h\nB - stdlib.h\nC - stdio.h\nD - time.h\n>> ");
                scanf("%c", &resp);
                getchar();
                if((resp == 'c') || (resp == 'C')){
                    printf("RESPOTA CORRETA!\n");
                    pontos+=50;
                }else{
                    Errado(&pontos);
                }
                break;
            
            case 2:
                printf("QUAL O SIGNIFICADO DA EXPREÇÃO || EM C?\n");
                printf("A - Igual\nB - Diferente\nC - E\nD - Ou\n>> ");
                scanf("%c", &resp);
                getchar();
                if((resp == 'd') || (resp == 'D')){
                    printf("RESPOSTA CORRETA!\n");
                    pontos+=50;
                }else{
                    Errado(&pontos);
                }
                break;

            case 3:
                printf("NA FUNÇAO SCANF, QUAL A ULTILIDADE DO & EM C?\n");
                printf("A - Armazenar dados em uma variável\nB - Obter o enderço de uma vAriável\nC - Indicar o endereço de uma vAriável\nD - Ler o conteudo da variável\n>> ");
                scanf("%c",&resp);
                getchar();
                if((resp == 'b') || (resp == 'B')){
                    printf("RESPOSTA CORRETA!\n");
                    pontos+=50;
                }else{
                    Errado(&pontos);
                }
                break;

            case 4:
                printf("EM UM COMPUTADOR DE 64-BIT, QUAL O TAMANHO EM BYTS DE UMA VARIAVEL\nDO TIPO LONG, EM C?\n");
                printf("A - 4 Byts\nB - 8 Byts\nC - 3 Byts\nD - 1 Byts\n>> ");
                scanf("%c",&resp);
                getchar();
                if((resp == 'b') || (resp == 'B')){
                    printf("RESPOSTA CORRETA!\n");
                    pontos+=50;
                }else{
                    Errado(&pontos);
                }
                break;

            default:
                printf("SEM PERGUNTAS!\n");
                menu();
                break;
        }
        i++;
    }while(i<limite);
   

free(al);

RandomizarNumeros(al);

i=0;

    do{  

        switch(al[i]){
                case 0:
                    printf("PARA QUE SERVE A FUNÇAÕ FREE EM C?\n");
                    printf("A - Limpa o número de byts solicitado anteriormente de um determinado bloco de memória\nB - Abir um arquivo em um bloco de momória do computador\nC - Apontar para um edereço de uma variável\nD - Libera à memória alocada em um vetor\n>> ");
                    scanf("%c",&resp);
                    getchar();  
                    if((resp == 'a') || (resp == 'A')){
                            printf("RESPOSTA CORRETA!\n");
                            pontos+=50;
                            printf("%d\n", pontos); 
                        }else{
                            Errado(&pontos);
                        }
                    break;

                case 1:
                    printf("SEM PERGUNTAS AINDA\n");
                    scanf("%c",&resp);
                    break;

                case 2:
                    printf("SEM PERGUNTAS AINDA\n");
                    scanf("%c",&resp);
                    break;

                case 3:
                    printf("SEM PERGUNTAS AINDA\n");
                    scanf("%c",&resp);
                    break;

                case 4:
                    printf("SEM PERGUNTAS AINDA\n");
                    scanf("%c",&resp);
                    break;
            }
        i++;    
    }while(i<limite);
   
}

void Errado(int *pt){
    printf("RESPOSTA ERRADA!\nPONTOS: %d\n", *pt);
    menu();

}