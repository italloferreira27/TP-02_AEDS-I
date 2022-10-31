#include "./main.h"

int main(){
    char cores[MAX];
    int tam = Tamanho_Matriz();
    int i, j, opcao, espacos, matriz[tam][tam];

    printf("1 = Ler arquivo\n2 = Permutar\n");
    while(opcao != 5){
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

            Permutacao(cores, espacos);
            break;
        case 3:
            // printf("\n");
            // for(i = 0; i < 10; i++){
            //     for(j = 0; j < 10; j++){
            //         printf("%d  ", matriz[i][j]);
            //     }
            //     printf("\n");
            // }
            // break;
        default:
            printf("Opcao invalida!");
            break;
        }
    }   

    return 0;
}