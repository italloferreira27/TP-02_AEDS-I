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