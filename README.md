<div align="center">

<img src="https://media.giphy.com/media/iIqmM5tTjmpOB9mpbn/giphy.gif" width="200px" alt="Gif animado"/>

# <code><strong> Operações com Conjuntos</strong></code>

<em>Trabalho da disciplina de Linguagem de Programação</em>

<!-- adicionar aqui o uso das linguagens que eu passar-->
[![C Usage](https://img.shields.io/badge/C-100%25-blue?style=for-the-badge&logo=c)]()
[![Status](https://img.shields.io/badge/Status-Concluído-green?style=for-the-badge)]()
[![LinkedIn](https://img.shields.io/badge/LinkedIn-Visite%20meu%20perfil-blue?style=for-the-badge&logo=linkedin)](https://www.linkedin.com/in/rian-carlos-valcanaia-b2b487168/)

</div>


## Índice

- [📌 Objetivos](#-objetivos)
- [📥 Entradas do sistema](#-entradas-do-sistema)
- [🧱 Estruturas de Dados](#-estruturas-de-dados)
- [🧰 Funcionalidades](#-funcionalidades)
- [📊 Exemplo de Execução](#-exemplo-de-execução)
- [📂 Como executar](#-como-executar)
- [👨‍🏫 Envolvidos](#-envolvidos)
- [📅 Curso](#-curso)
- [📄 Código-fonte](#-código-fonte)

## 📌 Objetivos
O objetivo deste projeto é criar um programa em C que permita ao usuário realizar diversas operações fundamentais da teoria dos conjuntos de forma interativa através de um menu no terminal.
* Desenvolver um sistema para criar e gerenciar múltiplos conjuntos de números inteiros.
* Implementar a inserção de elementos em um conjunto específico, evitando duplicatas.
* Permitir a remoção completa de um conjunto existente.
* Implementar as operações de **União** e **Intersecção** entre dois conjuntos, gerando um novo conjunto como resultado.
* Fornecer funcionalidades para visualizar um único conjunto, todos os conjuntos existentes ou buscar um elemento em todos os conjuntos.
* Estruturar o código de forma modular, utilizando arquivos de cabeçalho (`.h`) para uma melhor organização.

O trabalho tinha algumas restrições: 
* Devia ser iniciado todos os conjuntos zerados;
* Não podia aceitar zeros, nem numeros repetidos;
* Devia respeitar a capacidade máxima de criacao de conjuntos e de elementos em cada conjunto, estabelecido no codigo fonte;
* Quando criado um novo conjunto deveria escrever no final de todos os conjuntos;
* Quando apagar um conjunto, mover todos os conjuntos após o removido para "frente".

[⬆ Voltar ao topo](#índice)

## 📥 Entradas do sistema
O sistema interage com o usuário através de um menu numérico e solicita as seguintes entradas:
* **Opção do menu:** Um número inteiro de 1 a 9 para selecionar a funcionalidade desejada.
* **Índice do conjunto:** Um número inteiro para selecionar em qual conjunto a operação será realizada (ex: inserir, remover, unir).
* **Elementos do conjunto:** Números inteiros a serem inseridos em um conjunto. A entrada `0` é usada para finalizar a inserção.
* **Valor para busca:** Um número inteiro a ser buscado em todos os conjuntos existentes.

[⬆ Voltar ao topo](#índice)

## 🧱 Estruturas de Dados
A principal estrutura de dados para armazenar os conjuntos é uma matriz bidimensional de inteiros, declarada globalmente:

`int matriz[maxL][maxC];`

Onde:
*   Cada **linha** da matriz representa um conjunto.
*   Cada **coluna** armazena um elemento desse conjunto.
*   O valor `0` é utilizado como sentinela para indicar o fim dos elementos em um conjunto.
*   `maxL` e `maxC` são constantes que definem o número máximo de conjuntos e o número máximo de elementos por conjunto, respectivamente.

[⬆ Voltar ao topo](#índice)

## 🧰 Funcionalidades

### 🔹 Funções Principais
* `inserirDados()`: Adiciona um ou mais elementos a um conjunto existente, validando se o elemento já existe.
* `removerConjunto()`: Elimina um conjunto inteiro da matriz, deslocando os conjuntos subsequentes.
* `uniao()`: Gera um novo conjunto contendo todos os elementos de dois conjuntos de origem, sem repetições.
* `interseccao()`: Gera um novo conjunto contendo apenas os elementos que são comuns a dois conjuntos de origem.
* `exibicao()`: Mostra na tela os elementos de um único conjunto especificado pelo usuário.
* `exibicao_completa()`: Mostra todos os conjuntos atualmente armazenados na matriz.
* `busca()`: Procura por um valor em todos os conjuntos e informa em quais deles o valor foi encontrado.

### 🔸 Funções Secundárias
* `limpaTela()`, `limpaBuffer()`, `telaInicial()`, `menuInicial()`, `tamanho()`, `mostraMatriz()`, `entradaUsuario()`, `buscaSeq()`, `vetorcpy()`, `vetorset()`, `matrizset()`

[⬆ Voltar ao topo](#índice)

## 📊 Exemplo de Execução
1.  Ao iniciar, o programa exibe uma tela de boas-vindas em arte ASCII e aguarda o usuário.
2.  Um menu principal com 9 opções é apresentado.
3.  O usuário pode criar um novo conjunto vazio (opção 1).
4.  Em seguida, pode inserir elementos nesse conjunto (opção 2).
5.  O usuário pode criar um segundo conjunto e também inserir elementos nele.
6.  Com dois ou mais conjuntos criados, é possível realizar operações como união (opção 4) ou intersecção (opção 5), que criarão um novo conjunto com o resultado.
7.  A qualquer momento, o usuário pode visualizar o estado de um conjunto específico (opção 6) ou de todos eles (opção 7).
8.  O programa continua em execução, permitindo múltiplas operações até que a opção 9 (Sair) seja escolhida.

[⬆ Voltar ao topo](#índice)

## 📂 Como executar
Para compilar e executar o programa, que está dividido em múltiplos arquivos, utilize o seguinte comando no terminal. Ele compilará o `main.c` e criará um executável chamado `app_conjuntos`.
```bash
gcc main.c -o app_conjuntos && ./app_conjuntos
```

[⬆ Voltar ao topo](#índice)

## 👨‍🏫 Envolvidos
* **Professor**: Rui Jorge Tramontin Junior
* **Estudantes**:
  * Matheus Azevedo de Sá
  * [Rian Valcanaia](https://github.com/RianValcanaia)

[⬆ Voltar ao topo](#índice)

## 📅 Curso

* **Universidade**: Universidade do Estado de Santa Catarina (UDESC)
* **Disciplina**: Linguagem de Programação
* **Semestre**: 2º

[⬆ Voltar ao topo](#índice)

## 📄 Código-fonte

🔗 [https://github.com/RianValcanaia/LPG_Gerenciamento_de_Conjuntos](https://github.com/RianValcanaia/LPG_Gerenciamento_de_Conjuntos)

[⬆ Voltar ao topo](#índice)


