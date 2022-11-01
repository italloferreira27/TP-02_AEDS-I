#include "./main.h"
//#include <time.h>

int main(){
    char cores[MAX];
    int tam = Tamanho_Matriz();
    int i, j, opcao, espacos, matriz[tam][tam];
    


    Iniciar(tam, matriz);
    
    printf("Digite as iniciais da suas cores: ");
    scanf("%s", cores);
    printf("numero de espacos: %d\n",tam);

    Permutacao(cores, espacos,tam, matriz);
    opcao = 2;  

    return 0;
}