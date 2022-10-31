#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 250


int Permutacao(char* cores, int espacos){
    int i, j, k, n, *num;
    char str[MAX];


    /* Aqui elimina-se caracteres repetidos na entrada.
     * Esse procedimento não faz parte do algoritmo, e
     * só é feito por questões práticas.
     */
    n = strlen(cores) ;
    j = 0;
    str[0] = 0 ;
    for ( i = 0; i < n; i++ ) {
        if ( strchr(str, cores[i]) == NULL ) {
            str[j] = cores[i] ;
            j++ ;
            str[j] = 0 ;
        }
    }
    strcpy(cores, str) ;
    n = strlen(cores) ;

    /* Cria o nosso número. Ele é um vetor de
     * r+1 posições, sendo que a última é 
     * reservada para indicar quando todos os
     * números de tamanho r foram gerados. */
    num = (int *) calloc( (espacos + 1), sizeof(int)) ;
    if ( num == NULL ) {
        perror("calloc") ;
        return -1;
    }

    /* Termina quando a última posição do vetor
     * for 1. */
    while ( num[espacos] == 0 ) {
        for ( i = 0; i < n; i++ ) {
            /* processo de mapeamento. */
            for ( j = 0, k = espacos-1; j < espacos; j++ ) {
                str[k] = cores[num[j]] ;
                k-- ;
            }
            /* Mostra o resultado. */
            str[espacos] = 0 ;
            printf("%s\n", str) ;

            /* incrementa o algarismo menos significativo. */
            num[0]++ ;
        }

        /* Muda de "casa" e lança os vai uns. */ 
        for ( i = 0; i < espacos; i++ ) {
            if ( num[i] == n ) {
                num[i] = 0 ;
                num[i+1]++ ;
            }
        }
    }

    return 0;
}

void Iniciar(int tamanho_Mat, int Matriz[tamanho_Mat][tamanho_Mat]){
    int i, j, k = 0, n ,cont = 0;
    int vetor[50], espacos;
    char linha[50], cores[MAX];
    char *Numero; //strtok
    int tamanho; //strtok

    //..........Manipulação de arquivo..........
    FILE *file;
    file = fopen("entrada_I.txt", "r");                

    while(fgets(linha, 50, file) != NULL){
        Numero = strtok(linha, " ");

        while(Numero){

            tamanho = strlen(Numero);
            char Aux_Numero[tamanho];

            if(Numero[tamanho - 1] == '\n'){
                for(i = 0; i < tamanho; i++){
                    if(i != (tamanho - 1)){
                        Aux_Numero[i] = Numero[i]; 
                    }
                }
                strcpy(Numero, Aux_Numero);
            }
            
            vetor[cont] = *Numero - '0'; //converter de caractere para inteiro
            printf("%d ", vetor[cont]);
            Numero = strtok(NULL, " "); 
            cont++;
        }
        printf("cont = %d \n", cont);

        //Colocando as adjacencias na matriz 
        for(i = 0; i < tamanho_Mat; i++){
            for(j = 0; j < tamanho_Mat; j++){
                if(i == j) Matriz[i][j] = -1;
                if(cont != 0){
                    Matriz[vetor[0]][vetor[cont]] = 1;
                    Matriz[vetor[cont]][vetor[0]] = 1;
                    cont--;
                }
            }
        }
    }
    fclose(file);

        //...........Imprimindo Matriz..........
        printf("\n");
        for(i = 0; i < tamanho_Mat; i++){
            for(j = 0; j < tamanho_Mat; j++){
                printf("%d  ", Matriz[i][j]);
            }
            printf("\n");
        }
        //......................................

        //return Matriz;
}

int Tamanho_Matriz(){
    int tamanho_Mat, i, j;
    char linha_conta[50];

    FILE *file2;
    file2 = fopen("entrada_I.txt", "r");

    while(fgets(linha_conta, 50, file2) != NULL){
        tamanho_Mat++;
    }

    int Matriz[tamanho_Mat][tamanho_Mat];

    for(i = 0; i < tamanho_Mat; i++){
        for(j = 0; j < tamanho_Mat; j++){
            Matriz[i][j] = 0;
        }
    }
    //printf("%d \n\n", tamanho_Mat);

    fclose(file2);
    return tamanho_Mat;
    }