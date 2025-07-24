#ifndef CONJUNTOS_H
#define CONJUNTOS_H
#include "funcoes.h"

//Rian
void inserirDados(int maxL, int maxC, int matriz[maxL][maxC], int *indiceLinhaMatriz){
    int indice, continuar = 1, num;
    printf("INSERIR EM UM CONJUNTO\n\n");
    mostraMatriz(*indiceLinhaMatriz,maxC, matriz);
    if (*indiceLinhaMatriz == 0) {
        printf("\nNennhum conjunto adicionado a Matriz. Aperte enter para voltar.\n");
        limpaBuffer();
        getchar();
    }
    else {
        printf("\nDigite o índice do conjunto que deseja inserir elemento(s):\n");
        entradaUsuario(0, (*indiceLinhaMatriz-1),&indice);
        int elemento = tamanho(matriz[indice],maxC);
        if(elemento < maxC){
            printf("Digite o(s) elemento(s):\n");
            while (continuar && elemento < maxC){
                if (scanf("%d", &num) == 1 && !buscaSeq(matriz[indice], num) && num != 0){
                    matriz[indice][elemento] = num;
                    elemento++;
                }else if (num == 0) continuar = 0;
                else{
                    printf("%d ja esta no conjunto %d. Digite novamente.\n", num, indice);
                }
            }
            printf("Elemento(s) inserido(s) com sucesso. Aperte enter para voltar.\n");
            limpaBuffer();
            getchar();
        }else{
            printf("Conjunto [%d] cheio. Aperte enter para voltar.", indice);
            limpaBuffer();
            getchar();
        }
    }
}

void removerConjunto(int maxL, int maxC, int matriz[maxL][maxC], int *indiceLinhaMatriz) {
    int indice ;
    printf("REMOVER CONJUNTO\n\n");
    mostraMatriz(*indiceLinhaMatriz, maxC, matriz);
    if (*indiceLinhaMatriz == 0) {
        printf("\nNenhum conjunto adicionado a matriz. Pressione Enter para voltar.\n");
        limpaBuffer();
        getchar();
    } else {
        printf("\nDigite o índice do conjunto que deseja eliminar.\n");
        entradaUsuario(0, (*indiceLinhaMatriz - 1), &indice);

        for (int i = indice; i < (*indiceLinhaMatriz - 1); i++) {
            for (int j = 0; j < maxC; j++) {
                matriz[i][j] = matriz[i + 1][j];
            }
        }
        
        vetorset(matriz[(*indiceLinhaMatriz - 1)],0,maxC);
        (*indiceLinhaMatriz)--;
        printf("Conjunto removido com sucesso. Aperte enter para voltar.\n");
        limpaBuffer();
        getchar();
    }
}

void uniao(int maxL, int maxC, int matriz[maxL][maxC], int *indiceLinhaMatriz) {
    int indiceA, indiceB, matrizAuxiliar[maxC*2], i;
    printf("UNIAO\n\n");
    mostraMatriz(*indiceLinhaMatriz, maxC, matriz);
    vetorset(matrizAuxiliar, 0, tamanho(matrizAuxiliar, maxC*2));
   
    if (*indiceLinhaMatriz <= 1) {
        printf("\nNecessário ter 2 conjuntos salvos. Pressione Enter para voltar.\n");
        limpaBuffer();
        getchar();
    } else if (*indiceLinhaMatriz == maxL) {
        printf("Sem espaco na Matriz para alocar o conjunto. Pressione Enter para voltar.\n");
        limpaBuffer();
        getchar();
    } else {
        printf("\nInforme os índices dos dois conjuntos que devem ser unidos.\n");

        printf("\nÍndice do primeiro conjunto: ");
        entradaUsuario(0,*indiceLinhaMatriz-1, &indiceA);

        printf("\nÍndice do segundo conjunto: ");
        entradaUsuario(0,*indiceLinhaMatriz-1, &indiceB);
        
        vetorcpy(matrizAuxiliar, matriz[indiceA], tamanho(matriz[indiceA], maxC));

        int j = tamanho(matrizAuxiliar, maxC*2);

        for (i = 0; matriz[indiceB][i] != 0; i++) {
            if (!buscaSeq(matrizAuxiliar, matriz[indiceB][i])) {
                matrizAuxiliar[j] = matriz[indiceB][i];
                j++;
            }
        }

        if (j <= maxC) {
            vetorcpy(matriz[*indiceLinhaMatriz], matrizAuxiliar, maxC);
            (*indiceLinhaMatriz)++;
            printf("\nEstá feita a intersecção entre os conjuntos %d e %d. Aperte enter para voltar.\n", indiceA, indiceB, *indiceLinhaMatriz);
            limpaBuffer();
            getchar();
        } else {
            printf("Conjunto uniao excede a capacidade de alocacao na memoria disponivel. Aperte enter para voltar.\n");
            limpaBuffer();
            getchar();
        }
    }
}

//MATHEUS
void interseccao(int maxL, int maxC, int matriz[maxL][maxC], int *indiceLinhaMatriz){
    printf("INTERSECÇÃO\n\n");
    
    if (*indiceLinhaMatriz <= 1) {
        printf("\nNecessário ter 2 conjuntos salvos. Pressione Enter para voltar.\n");
        limpaBuffer();
        getchar();
    } else if (*indiceLinhaMatriz == maxL) {
        printf("Sem espaco na Matriz para alocar o conjunto intersecção. Pressione Enter para voltar.\n");
        limpaBuffer();
        getchar();
    } else {
        mostraMatriz(*indiceLinhaMatriz,maxC, matriz);
        
        printf("\nInforme os índices dos dois conjuntos que devem ser interseccionados.\n");

        int a;
        printf("\nÍndice do primeiro conjunto: ");
        entradaUsuario(0,*indiceLinhaMatriz-1, &a);

        int b;
        printf("\nÍndice do primeiro conjunto: ");
        entradaUsuario(0,*indiceLinhaMatriz-1, &b);

        limpaBuffer();

        int i = 0;
        int k = 0;
        while(matriz[a][i] != 0 && i < maxC) {
            int j = 0;
            while(matriz[b][j] != 0 && j < maxC) {
                if (matriz[a][i] == matriz[b][j]) {
                    matriz[*indiceLinhaMatriz][k] = matriz[a][i];
                    k++;
                }
                j++;
            }        
            i++;
        }
        printf("\nEstá feita a intersecção entre os conjuntos %d e %d. Aperte enter para voltar.\n", a, b, *indiceLinhaMatriz);
        (*indiceLinhaMatriz)++;
        limpaBuffer();
        getchar();
    }
}

void exibicao(int maxL, int maxC, int matriz[maxL][maxC], int *indiceLinhaMatriz){
    limpaTela();
    printf("\nEXIBIÇÃO DE CONJUNTO\n");

    if (*indiceLinhaMatriz == 0) {
        printf("\nNenhum conjunto adicionado. Pressione Enter para voltar.\n");
        limpaBuffer();
        getchar();
    } else {
        printf("\nInforme os índices de um conjunto para que ele seja exibido na tela.\n");

        int a;
        printf("\nÍndice do conjunto: ");
        entradaUsuario(0,*indiceLinhaMatriz-1, &a);

        printf("\nConjunto %d: ", a);

        int i = 0;
        int esta_vazio = 1;
        int tam = tamanho(matriz[a], maxC);
        while(matriz[a][i] != 0 && i < maxC) {
            esta_vazio = 0;   
            (i==0)? printf("{%d,", matriz[a][i]) : (i==tam-1)? printf("%d}", matriz[a][i]) : printf("%d,", matriz[a][i]);             
            i++;
        }
        if (esta_vazio) printf("vazio.");
        else printf("\n"); 
        printf("\n\nAperte enter para voltar.\n");
        limpaBuffer();
        getchar(); 
    } 
}

void exibicao_completa(int maxL, int maxC, int matriz[maxL][maxC], int *indiceLinhaMatriz){
    limpaTela();
    printf("EXIBIÇÃO DE TODOS OS CONJUNTOS\n");
    if(*indiceLinhaMatriz == 0) {
        printf("\nNenhum conjunto adicionado. Aperte enter para voltar.\n");
        limpaBuffer();
        getchar();
    }else{
        printf("\n");
        mostraMatriz(*indiceLinhaMatriz, maxC, matriz);
        printf("\nAperte enter para voltar.");
        limpaBuffer();
        getchar();
    }

}

void busca(int maxL, int maxC, int matriz[maxL][maxC], int *indiceLinhaMatriz){
    limpaTela();
    printf("BUSCA\n");

    if(*indiceLinhaMatriz == 0) {
        printf("\nNenhum conjunto adicionado. Aperte enter para voltar.\n");
        limpaBuffer();
        getchar();
    }else{
        printf("\nInforme o elemento que deve ser buscado.\n");

        int a;
        scanf(" %d", &a);
        limpaBuffer();

        int k = 0;
        int encontrado = 0;
        printf("\nConjuntos que contêm %d:\n", a);
        while (k < *indiceLinhaMatriz) {
            int i = 0;
            while(matriz[k][i] != 0 && i < maxC) {
                if (matriz[k][i] == a) {
                    encontrado = 1;
                    printf("%d ", k);
                } 
                i++;
            }
            k++;  
        } 
        if (encontrado) printf("\n");
        else printf("Nenhum.\n"); 
        printf("\nAperte enter para voltar.\n");
        getchar();
    }
}

#endif
