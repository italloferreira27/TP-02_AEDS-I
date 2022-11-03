#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 250



int compara(char *str,int tam, int matriz[tam][tam]){
    int i,j,cont=0,cont_false=0;
    //printf("%s\n",str);
    for(i=0;i<tam;i++){
        for(j=i+1;j<tam;j++){
            if(matriz[i][j] == 1){
                if(str[i]==str[j]){
                    cont++;
                    break;
                }
            }
        }
    }
    //printf("%d\n",cont);
    if(cont == 0){
        printf("Aranjo valido: %s\n",str);
    }else{
        cont_false++;
    }

    return cont_false;
}

int Permutacao(char *cores, int tam, int Matriz[tam][tam]){
    int i, j, k, n, *num,cont=0 ;
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
    num = (int *) calloc( (tam + 1), sizeof(int)) ;
    if ( num == NULL ) {
        perror("calloc") ;
        return -1;
    }

    /* Termina quando a última posição do vetor
     * for 1. */
    while ( num[tam] == 0 ) {
        for ( i = 0; i < n; i++ ) {
            /* processo de mapeamento. */
            for ( j = 0, k = tam-1; j < tam; j++ ) {
                str[k] = cores[num[j]] ;
                k-- ;
            }
            /* Mostra o resultado. */
            str[tam] = 0 ;
            //printf("%s\n", str) ; //Escrever toda as permutações 
            cont += compara(str,tam,Matriz);
            //printf("--------------%s\n",str);

            /* incrementa o algarismo menos significativo. */
            num[0]++ ;
        }

        /* Muda de "casa" e lança os vai uns. */ 
        for ( i = 0; i < tam; i++ ) {
            if ( num[i] == n ) {
                num[i] = 0 ;
                num[i+1]++ ;
            }
        }
    }
    printf("Numero de aranjos invalidos: %d\n",cont);
    return 0;
}

void Iniciar(int tamanho_Mat, int Matriz[tamanho_Mat][tamanho_Mat]){
    int i, j, k = 0, n ,cont = 0;
    int vetor[100], espacos;
    char linha[100], cores[MAX];
    char *Numero; //strtok
    int tamanho; //strtok

    for(i = 0; i < tamanho_Mat; i++){
        for(j = 0; j < tamanho_Mat; j++){
            Matriz[i][j] = 0;
        }
    }

    //..........Manipulação de arquivo..........
    FILE *file;
    file = fopen("./Arquivos-teste/entrada_I.txt", "r");                

    printf("Entradas:\n");
    while(fgets(linha, 100, file) != NULL){
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

            vetor[cont] = atoi(Numero); //converter de caractere para inteiro
            printf("%d ", vetor[cont]);
            Numero = strtok(NULL, " "); 
            cont++;
        }
        printf("\n");
        cont--;

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
        printf("\nMatriz:\n");
        for(i = 0; i < tamanho_Mat; i++){
            for(j = 0; j < tamanho_Mat; j++){
                printf("%d  ", Matriz[i][j]);
            }
            printf("\n");
        }printf("\n");
        //......................................

        //return Matriz;
}

int Tamanho_Matriz(){
    int tamanho_Mat, i, j;
    char linha_conta[100];

    FILE *file2;
    file2 = fopen("./Arquivos-teste/entrada_I.txt", "r");

    while(fgets(linha_conta, 100, file2) != NULL){
        tamanho_Mat++;
    }

    fclose(file2);
    return tamanho_Mat;
}