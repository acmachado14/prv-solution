#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*void troca(int vetor[], int i, int j)
{
    int aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
}
*/

void permuta(int tamVetor, int vetorDeRota[tamVetor])
{
    int aux[tamVetor], i;
    for(i=0;i<tamVetor;i++){
        aux[i]=0;
    }

    i= 0;
    while (i<tamVetor){
        if  (aux[i] < i){
            if (i%2){

                int posicao = aux[i];
                int auxTroca = vetorDeRota[posicao];
                vetorDeRota[posicao] = vetorDeRota[i];
                vetorDeRota[i] = auxTroca;

                for(int j = 0; j < tamVetor;j++){
                    printf("%d", vetorDeRota[i]);
                }
            }else{
                int posicao = 0;
                int auxTroca = vetorDeRota[posicao];
                vetorDeRota[posicao] = vetorDeRota[i];
                vetorDeRota[i] = auxTroca;

                aux[i] += 1;
                i = 0;
            }
        }else{
            aux[i]=0;
            i += 1;
        }
    }
}


int main(){

    clock_t start, end;
    double timeUsed;
    start = clock();

    FILE *fp;
    fp = fopen("testeGermano.txt","r");

    int nCidades, cargaCaminhao;

    fscanf(fp,"%d", &nCidades);

    fscanf(fp,"%d", &cargaCaminhao);

    float matCidades[nCidades][nCidades];
    int demandaCidade[nCidades];
    int verifcarCidade[nCidades];
    int soma = 0, qtdCaminhoes;

    for (int i = 0; i < nCidades; i++){
        fscanf(fp,"%d", &demandaCidade[i]);
        soma = soma + demandaCidade[i];
    }

    qtdCaminhoes = soma/cargaCaminhao;

    for (int i = 0; i < nCidades; i++){
        verifcarCidade[i] = 0;
        for (int j = 0; j < nCidades; j++){
            fscanf(fp,"%f", &matCidades[i][j]);
        }
    }

    puts("---------------------SOLUCAO PRV-------------------------");
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

    puts("\n");
    puts("---------------------TEMPO USADO-------------------------");
    end = clock();
    timeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%f %s", timeUsed, "\n");

    return 0;
}