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