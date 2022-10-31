#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    int adj, n, i, j, cont = 0;
    int l[100], c1[100], c2[100];
    int matriz[100][100];

    // FILE *file;
    // file = fopen("entrada_I.txt", "r");

    // while(fgets(linha, 50, file) != NULL){
    //     //Numero[i] = strdup(linha);
    //     Numero = strtok(linha, " ");
    //     if(Numero[sizeof(Numero) - 1] == '\n'){
    //         Numero1[i] = nada;
    //     }
    //     Numero1[i] = Numero;
    //     i++;

    //     /*if(Numero[i] == '\n'){
    //         strcmp(Numero[i], nada);
    //     }
    //     i++;*/

    // }

    printf("Digite o tamnho da matriz: ");
    scanf("%d", &n);

    printf("Digite quantas adjacencias: ");
    scanf("%d", &adj);

    for(i = 0; i < adj; i++){
        scanf("%d %d %d", &l[i], &c1[i], &c2[i]);
    }

    // for(i = 0; i < adj; i++){
    //     printf("%d %d %d", l[i], c1[i], c2[i]);
    //     printf("\n");
    // }

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(i == j) matriz[i][j] = -1;
            if(i == l[cont] && j == c1[cont]){
                matriz[i][j] = 1;
                matriz[j][i] = 1;
                cont++;
            }
        }
    }

    cont = 0;

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(i == j) matriz[i][j] = -1;
            if(i == l[cont] && j == c2[cont]){
                matriz[i][j] = 1;
                matriz[j][i] = 1;
                cont++;
            }
        }
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d  ", matriz[i][j]);
        }
        printf("\n");
    }

    //fclose(file);
    return 0;
}

/* Permutação do 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Tamanho máximo da string de entrada. */
#define MAX 250

int main() {
    /* Nosso número na base n. Ele é um vetor
     * de n+1 posições representando um número
     * na base n.
     */
    int *num ;
    /* input é a string de entrada, e str
     * receberá cada permutação.
     */ 
    char input[MAX], str[MAX] ;
    int n, r, i, j, k ;

    printf("Entre com o conjunto inicial: ") ;
    scanf("%s", input) ;

    printf("Entre com o r: ") ;
    scanf("%d", &r) ;


    /*Criando Matriz*/
    for(i = 0; i < r; i++){
        for(j = 0; j < r; j++){
            if(i == j) matriz[i][j] = -1;
            if(){
                matriz[i][j] = 1;
                matriz[j][i] = 1;
            }
        }
    }
    /**/

    /* Aqui elimina-se caracteres repetidos na entrada.
     * Esse procedimento não faz parte do algoritmo, e
     * só é feito por questões práticas.
     */
    n = strlen(input) ;
    j = 0;
    str[0] = 0 ;
    for ( i = 0; i < n; i++ ) {
        if ( strchr(str, input[i]) == NULL ) {
            str[j] = input[i] ;
            j++ ;
            str[j] = 0 ;
        }
    }
    strcpy(input, str) ;
    n = strlen(input) ;

    /* Cria o nosso número. Ele é um vetor de
     * r+1 posições, sendo que a última é 
     * reservada para indicar quando todos os
     * números de tamanho r foram gerados. */
    num = (int *) calloc( (r+1), sizeof(int)) ;
    if ( num == NULL ) {
        perror("calloc") ;
        return -1;
    }

    /* Termina quando a última posição do vetor
     * for 1. */
    while ( num[r] == 0 ) {
        for ( i = 0; i < n; i++ ) {
            /* processo de mapeamento. */
            for ( j = 0, k = r-1; j < r; j++ ) {
                str[k] = input[num[j]] ;
                k-- ;
            }
            /* Mostra o resultado. */
            str[r] = 0 ;
            printf("%s\n", str) ;

            /* incrementa o algarismo menos significativo. */
            num[0]++ ;
        }

        /* Muda de "casa" e lança os vai uns. */ 
        for ( i = 0; i < r; i++ ) {
            if ( num[i] == n ) {
                num[i] = 0 ;
                num[i+1]++ ;
            }
        }
    }

    return 0 ;
}
*/
