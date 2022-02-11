#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
    clock_t start, end;
    double timeUsed;
    start = clock();
    FILE *fp;
    fp = fopen("../testes_adaptados/teste8-6.txt","r");

    int nCidades, cargaCaminhao;

    fscanf(fp,"%d", &nCidades);
    fscanf(fp,"%d", &cargaCaminhao);

    int matCidades[nCidades][nCidades], demandaCidade[nCidades], soma = 0, qtdCaminhoes;

    for (int i = 0; i < nCidades; i++){
        fscanf(fp,"%d", &demandaCidade[i]);
        soma = soma + demandaCidade[i];
    }
    qtdCaminhoes = soma/cargaCaminhao;

    for (int i = 0; i < nCidades; i++){
        for (int j = 0; j < nCidades; j++){
            fscanf(fp,"%f", &matCidades[i][j]);
        }
    }

    puts("---------------------SOLUCAO PRV-------------------------");
    int tamVetor = nCidades  + qtdCaminhoes -2;//retiramos o 0 da solucao
    int vetorDeRota[tamVetor], melhorOpcao[tamVetor], melhorValor;
    int verificador = 0, pDemanda = 1, disTotal, aux[tamVetor], i;

    for (int i=0;i<tamVetor;i++){ //preenchendo o vetor de rotas para as permutacoes
        if (i<nCidades-1){
            vetorDeRota[i]=i+1;

        }else{
            vetorDeRota[i]=0;
        }
    }
    for(i=0;i<tamVetor;i++){
        aux[i]=0;
    }
    i= 0;
    while (i<tamVetor){//Inicio da permutacao de HEAP
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
            aux[i] += 1;
            i = 0;

        }else{
            aux[i]=0;
            i += 1;
        }//Final da permutacao de HEAP


        disTotal = 0;
        int possivel = 0, possivel2 = 1, cargaAtual = cargaCaminhao;
        for(int k = 0; k < tamVetor-1; k++){//validar as solucoes antes de compara-las
            int p1 = vetorDeRota[k], p2 = vetorDeRota[k+1];
            if (p1 != p2){ //barrar entrada de 0 Consecutivos
                if (vetorDeRota[k] == 0){ //se chegou no 0 é pq saiu mais um caminhao cheio do deposito
                    cargaAtual = cargaCaminhao;
                }
                if (demandaCidade[p2] <= cargaAtual){//verificar se a demanda dos nós é maior que a do caminhao
                    cargaAtual -= demandaCidade[p2];
                }else{
                    possivel = 1; //se nao for, possivel = 1
                }

                //calcular a distancia no inicio e no final, visto que retiramos os 0 do codigo pra ganhar tempo
                if (k == 0){
                    disTotal += matCidades[0][p2];
                }else if (k == tamVetor-2){
                    disTotal += matCidades[p1][0];
                }else{//soma da distancia total
                    disTotal += matCidades[p1][p2];
                    possivel2 = 0;
                }
            }
        }
        if (possivel == 0 && possivel2 == 0){ //se tudo estiver Ok
            if (verificador == 0){ // verificar se vai ser a primeira vez do for rodando
                melhorValor = disTotal;
                for(int k = 0; k < tamVetor; k++){
                    melhorOpcao[k] = vetorDeRota[k];
                }
                verificador = 1;
            }else{
                if (disTotal < melhorValor){ //comparando distancias
                    melhorValor = disTotal;
                    for(int k = 0; k < tamVetor; k++){
                        melhorOpcao[k] = vetorDeRota[k];
                    }
                }
            }
        }
    }

    printf("%d", 0);
    for (int i = 0; i < tamVetor; i++){
        printf("%d", melhorOpcao[i]);
    }
    printf("%d", 0);

    puts("\n");
    puts("---------------------TEMPO USADO-------------------------");
    end = clock();
    timeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%f %s", timeUsed, "\n");

    return 0;
}