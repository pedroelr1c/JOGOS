#include "jogo.h"

void menu(){
    int opc;

    printf("(1) JOGAR\n(2) PLACARES\n(3) SAIR\n");
    scanf("%d",&opc);
    getchar();

    switch (opc){
    case 1:
        perguntas_1();
        system("clear");
        break;
    case 2:
        printf("PLACARES INDISPONIVEL!\n");
        scanf("%d",&opc);
        getchar();
        system("clear");
        menu();
    case 3:
        printf("OBRIGADO POR JOGAR!");
        exit(1);
    default:
        system("clear");
        menu();

        break;
    }
}

void perguntas_1(){
    char resp;
    int i=0;
    int j;
    int igual;
    int al[5];
    int limite=3;
    int pontos=0;

    do{
        al[i] = rand() % 5;
        igual=0;
        for(j=0;j<i;j++){
            if(al[j]==al[i]){
                igual=1;
            }
        }
        if(igual==0){
            i++;
        }
    }while(i<limite);

    i=0;
    do{
        
        printf("(%d)\n", al[i]);
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
            
                printf("QUAL A BIBLIOTECA QUE POSSIBILITA A UTILIZAÇÃO DA FUNCÃO:\nSCANF E PRINTF, EM C?\n>> ");
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
            
            case 3:
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

            default:
                printf("SEM PERGUNTAS!\n");
        }
        i++;
    }while(i<limite);
   
}

void Errado(int *pt){
    printf("RESPOSTA ERRADA!\nPONTOS: %d\n", *pt);
    menu();

}