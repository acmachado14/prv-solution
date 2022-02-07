void permuta(int tamVetor, int vetorDeRota[tamVetor])
{
//0 1 2 0 3 0 4 5 0
//tamVetor = nCidades  + qtdCaminhoes + 1
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

int vetorDeRota[nCidades+qtdCaminhoes+1], i;
for (i=0;i<nCidades+qtdCaminhoes+1;i++){
	if (i<=nCidades){
		vetorDeRota[i]=i;
	}else{
		vetorDeRota[i]=0;
	}
}

//-----------------------------------Codigo antigo-----------------------------------

/*for (int qtd = 0; qtd < qtdCaminhoes; qtd++){
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
    printf("%d", 0);*/