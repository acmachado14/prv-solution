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
    fp = fopen("test.txt","r");

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
    int tamVetor = nCidades  + qtdCaminhoes + 1;
    int vetorDeRota[tamVetor];
    int melhorOpcao[tamVetor], melhorValor;

    for (int i=0;i<tamVetor;i++){
        if (i<=nCidades){
            vetorDeRota[i]=i;
        }else{
            vetorDeRota[i]=0;
        }
        melhorOpcao[i] = vetorDeRota[i];
    }



    int aux[tamVetor], i;
    for(i=0;i<tamVetor;i++){
        aux[i]=0;
    }
    i= 0;

    int disTotal;

    while (i<tamVetor){
        if  (aux[i] < i){
            if (i%2){
                int posicao = aux[i];
                int auxTroca = vetorDeRota[posicao];
                vetorDeRota[posicao] = vetorDeRota[i];
                vetorDeRota[i] = auxTroca;
            }else{
                int posicao = 0;
                int auxTroca = vetorDeRota[posicao];
                vetorDeRota[posicao] = vetorDeRota[i];
                vetorDeRota[i] = auxTroca;
            }

            disTotal = 0;
            for(int k = 0; k < tamVetor-1; k++){
                int p1 = vetorDeRota[k], p2 = vetorDeRota[k+1];
                disTotal += matCidades[p1][p2];
            }
            /*
            puts("\n");
            printf("%d", disTotal);*/
            if (melhorValor < disTotal){
                melhorValor = disTotal;
                for(int k = 0; k < tamVetor; k++){
                    melhorOpcao[k] = vetorDeRota[k];
                }
            }
            aux[i] += 1;
            i = 0;

        }else{
            aux[i]=0;
            i += 1;
        }
    }

    for (int i = 0; i < tamVetor; i++){
        printf("%d", melhorOpcao[i]);
    }

    puts("\n");
    puts("---------------------TEMPO USADO-------------------------");
    end = clock();
    timeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%f %s", timeUsed, "\n");

    return 0;
}