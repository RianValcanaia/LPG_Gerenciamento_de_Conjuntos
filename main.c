#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conjuntos.h"
#include "funcoes.h"

const int maxL = 4, maxC = 4;

int main(){

    int opcao, continuar = 1, indiceLinhaMatriz = 0;
    int matriz[maxL][maxC];
    matrizset(maxL,maxC,matriz, 0); //inicia a matriz zerada.   
   
    telaInicial();
    limpaTela();
    
    while (continuar){
        limpaTela();
        menuInicial();
        entradaUsuario(1,9,&opcao);
        switch(opcao){
            case 1:
            limpaTela();
            indiceLinhaMatriz++;
            printf("Conjunto criado com sucesso. Aperte enter para voltar.\n");
            limpaBuffer();
            getchar();
            break;
            case 2: 
            limpaTela();
            inserirDados(maxL,maxC,matriz, &indiceLinhaMatriz);
            break;
            case 3:
            limpaTela();
            removerConjunto(maxL,maxC,matriz,&indiceLinhaMatriz);
            break;
            case 4:
            limpaTela();
            uniao(maxL,maxC,matriz,&indiceLinhaMatriz);
            break;
            case 5:
            limpaTela();
            interseccao(maxL,maxC,matriz,&indiceLinhaMatriz);
            break;
            case 6:
            limpaTela();
            exibicao(maxL,maxC,matriz, &indiceLinhaMatriz);
            break;
            case 7:
            limpaTela();
            exibicao_completa(maxL,maxC,matriz, &indiceLinhaMatriz);
            break;
            case 8:
            limpaTela();
            busca(maxL,maxC,matriz, &indiceLinhaMatriz);
            break;
            case 9:
            limpaTela();
            continuar = 0;
            break;
        }
    }
return 0;
}
