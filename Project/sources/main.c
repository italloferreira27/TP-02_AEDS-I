#include <time.h>
#include "../headers/funcoes.h"

int main(){
    char cores[MAX];
    int tam;
    int i, j, opcao, espacos, matriz[tam][tam];
    //funções de tempo
    clock_t start, end;
    double time;

    //gerar tamanho da matriz adjacente
    tam = Tamanho_Matriz();
    //preenche matriz adjacente
    Iniciar(tam, matriz);
    
    printf("Digite as iniciais das suas cores: ");
    scanf("%s", cores);
    start = clock();
    printf("Numero de espacos: %d\n",tam);

    Permutacao(cores, espacos, tam, matriz);
    opcao = 2;  
    end = clock();
    time = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %f seg\n", time);
    if(time > 60){
        time = time / 60;
        printf("Tempo de execucao: %f min\n", time);
    }
    return 0;
}