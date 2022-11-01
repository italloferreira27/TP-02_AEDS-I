#include "./main.h"

int main(){
    char cores[MAX];
    int tam = Tamanho_Matriz();
    int i, j, opcao, espacos, matriz[tam][tam];

    printf("1 = Ler arquivo\n2 = Permutar\n");
    while(opcao != 2){
        printf("\nOpcao: ");
        scanf("%d", &opcao);
        switch (opcao){
        case 1:
            Iniciar(tam, matriz);
            break;

        case 2:
            printf("Digite as iniciais da suas cores: ");
            scanf("%s", cores);
            printf("Digite o numero de espacos: ");
            scanf("%d", &espacos);

            Permutacao(cores, espacos,tam, matriz);
            opcao = 2;
            break;
        default:
            printf("Opcao invalida!");
            break;
        }
    }   

    return 0;
}