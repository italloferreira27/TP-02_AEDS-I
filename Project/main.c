#include "./main.h"

int main(){
    char cores[MAX];
    int opcao, espacos;

    printf("1 = Ler arquivo\n2 = Permutar\n");
    while(opcao != 5){
        printf("\nOpcao: ");
        scanf("%d", &opcao);
        switch (opcao){
        case 1:
            Iniciar();
            break;

        case 2:
            printf("Digite as iniciais da suas cores: ");
            scanf("%s", cores);
            printf("Digite o numero de espacos: ");
            scanf("%d", &espacos);

            Permutacao(cores, espacos);
            break;
        case 3:
            
            break;
        default:
            printf("Opcao invalida!");
            break;
        }
    }   

    return 0;
}