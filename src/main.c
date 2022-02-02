#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
/*
    clock_t start, end;
    double timeUsed;
    start = clock();
    end = clock();
    timeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%fl %s", timeUsed, "\n");
*/

    int nCidades, cargaCaminhao;

    // Cidades
    scanf("%d", &nCidades);

    // Caminhoes
    scanf("%d", &cargaCaminhao);

    int tamanhoCidades = nCidades +1;
    float matCidades[tamanhoCidades][tamanhoCidades];
    float demandaCidade[nCidades];
    int verifcarCidade[nCidades];
    float soma = 0, qtdCaminhoes;

    // Demanda por cidade
    for (int i = 0; i < nCidades; i++){
        scanf ("%f", &demandaCidade[i]);
        soma = soma + demandaCidade[i];
    }

    qtdCaminhoes = soma/cargaCaminhao;

    for (int i = 0; i < tamanhoCidades; i++){
        for (int j = 0; j < tamanhoCidades; j++){
            matCidades[i][j] = 0;
        }
    }

    // Distancias
    for (int i = 1; i < nCidades + 1; i++){
        for (int j = 1; j < nCidades + 1; j++){
            printf("%s %d %s %d %s", "Distancia da cidade:",i, "com a cidade:",j, "\n");
            scanf ("%f", &matCidades[i][j]);
        }
    }



    return 0;
}