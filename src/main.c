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

    FILE *fp;
    fp = fopen("test.txt","r");

    int nCidades, cargaCaminhao;

    puts("Cid");
    fscanf(fp,"%d", &nCidades);

    puts("CargaCaminhao");
    fscanf(fp,"%d", &cargaCaminhao);

    float matCidades[nCidades][nCidades];
    int demandaCidade[nCidades];
    int verifcarCidade[nCidades];
    int soma = 0, qtdCaminhoes;

    puts("Demanda Cidade");
    for (int i = 0; i < nCidades; i++){
        fscanf(fp,"%d", &demandaCidade[i]);
        soma = soma + demandaCidade[i];
    }

    qtdCaminhoes = soma/cargaCaminhao;

    puts("Cidades Distancias");
    for (int i = 0; i < nCidades; i++){
        verifcarCidade[i] = 0;
        for (int j = 0; j < nCidades; j++){
            fscanf(fp,"%f", &matCidades[i][j]);
        }
    }

    for (int qtd = 0; qtd < qtdCaminhoes; qtd++){
        int stop = 0, atual = 0, maisProxima, cargaAtual = cargaCaminhao;
        float menor;
        printf("%d", 0);
        while (stop == 0){
            int  aux = 0;
            for (int j = 1; j < nCidades; j++){
                if (j != atual){
                    if (verifcarCidade[j] == 0){ //1 - ja preenchida, 0 - ninguem foi la
                        if(aux == 0){
                            menor = matCidades[atual][j];
                            maisProxima = j;
                            aux = 1;
                        }
                        if (matCidades[atual][j] < menor){
                            menor = matCidades[atual][j];
                            maisProxima = j;
                        }
                    }
                }
            }

            if (cargaAtual >= demandaCidade[maisProxima]){
                verifcarCidade[maisProxima] = 1;
                cargaAtual = cargaAtual - demandaCidade[maisProxima];
                atual = maisProxima;
                printf("%d", maisProxima);
            }else{
                stop = 1;
            }
        }
    }
    printf("%d", 0);
    return 0;
}