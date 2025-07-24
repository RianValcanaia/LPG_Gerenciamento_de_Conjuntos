#ifndef FUNCOES_H
#define FUNCOES_H

void limpaTela (){
    #ifdef _WIN32
        system("cls");   // Comando para Windows
    #else
        system("clear"); // Comando para Linux
    #endif
}

void limpaBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
  
void telaInicial(){
    limpaTela();
    printf("\n");
    printf("   _____ ____  _   _      _ _    _ _   _ _______ ____   _____ \n");
    printf("  / ____/ __ \\| \\ | |    | | |  | | \\ | |__   __/ __ \\ / ____|\n");
    printf(" | |   | |  | |  \\| |    | | |  | |  \\| |  | | | |  | | (___  \n");
    printf(" | |   | |  | | . ` |_   | | |  | | . ` |  | | | |  | |\\___ \\ \n");
    printf(" | |___| |__| | |\\  | |__| | |__| | |\\  |  | | | |__| |____) |\n");
    printf("  \\_____\\____/|_| \\_|\\____/ \\____/|_| \\_|  |_|  \\____/|_____/ \n");
    printf("                                                              \n");
    printf("                                                              \n");
    printf("Aperte enter para continuar.\n");
    getchar();
}

void menuInicial(){
    printf("MENU:\n\n");    
    printf("1- Criar um novo conjunto vazio.\n");
    printf("2- Inserir dados em um conjunto.\n");
    printf("3- Remover um conjunto.\n");
    printf("4- Fazer a uniao entre dois conjuntos.\n");
    printf("5- Fazer a intersecao entre dois conjuntos.\n");
    printf("6- Mostrar um conjunto.\n");
    printf("7- Mostrar todos os conjuntos.\n");
    printf("8- Busca por um valor.\n");
    printf("9- Sair do programa.\n");
    printf("\nDigite uma opcao: ");
}

int tamanho(int vetor[], int totalColunas){
    int contador = 0;
    for (int i = 0; vetor[i] != 0 && i < totalColunas; i++) contador++;
    return contador;
}

void mostraMatriz(int qtLinhas, int qtColunas, int matriz[qtLinhas][qtColunas]){
    for (int i = 0; i < qtLinhas; i++){
        printf("Conjunto %i: ", i);
        int eh_vazio = 1;
        int tam = tamanho(matriz[i], qtColunas);
        
        for (int j = 0; matriz[i][j]!=0 && j < tam; j++){
            eh_vazio = 0;
            (j==0)? printf("{%d,", matriz[i][j]) : (j==tam-1)? printf("%d}", matriz[i][j]) : printf("%d,", matriz[i][j]);
        }
        if (eh_vazio) printf("Vazio.\n");
        else printf("\n");
    }
}

int entradaUsuario (int inicioIntervalo, int fimIntervalo,int *entradaNum) {
    while (1) {
        if (scanf("%i", entradaNum) == 1 && *entradaNum >= inicioIntervalo && *entradaNum <= fimIntervalo) {
            break;
        } else {
            if (inicioIntervalo == fimIntervalo) {
                printf("Opcao invalida. Unica opcao disponível é %i.\n", fimIntervalo);
                limpaBuffer();
            }
            else {
                printf("Opcao invalida. Digite um numero de %i a %i.\n", inicioIntervalo, fimIntervalo);
                limpaBuffer();
            }
        }
    }
    return *entradaNum;
}

int buscaSeq(int vetor[], int num){
    for (int i = 0; vetor[i]!= 0; i++){
        if (vetor[i]==num) return 1;
    }
    return 0;
}

void vetorcpy(int destino[], int origem[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        destino[i] = origem[i];
    }
}

void vetorset(int vetor[], int valor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = valor;
    }
}

void matrizset(int linhas, int colunas, int matriz[linhas][colunas], int valor) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = valor;
        }
    }
}

#endif
