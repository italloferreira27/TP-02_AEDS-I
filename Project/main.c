#include <time.h>
#include <string.h>
#include "./headers/funcoes.h"

int main(){
    char cores[MAX], nome1[100]; // nome1 diretorio do arquivo
    char nome2[20];
    strcpy(nome1, "./Arquivos-teste/");
    Arquivos();
    printf(Color "Digite o nome do arquivo: " reset);
    scanf("%s", nome2); //Lendo nome do arquivo
    strcat(nome1, nome2);
    //gerar tamanho da matriz adjacente
    int tam = Tamanho_Matriz(nome1);
    int matriz[tam][tam];
    //funções de tempo
    clock_t start, end;
    double time;

    //preenche matriz adjacente
    Iniciar(tam, matriz, nome1);
    
    printf("Digite as iniciais das suas cores: ");
    scanf("%s", cores);
    start = clock();
    printf("Numero de espacos: %d\n",tam);

    Permutacao(cores, tam, matriz); 
    end = clock();
    time = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %f seg\n", time);
    if(time > 60){
        time = time / 60;
        printf("Tempo de execucao: %f min\n", time);
    }
    return 0;
}