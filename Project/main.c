#include "./main.h"
#include <time.h>

int main(){
    char cores[MAX];
    int tam = Tamanho_Matriz();
    int i, j, opcao, espacos, matriz[tam][tam];
    clock_t start, end;
    double time;
    
    Iniciar(tam, matriz);
    
    printf("Digite as iniciais das suas cores: ");
    scanf("%s", cores);
    start = clock();
    printf("Numero de espacos: %d\n",tam);

    Permutacao(cores, espacos,tam, matriz);
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