#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 100
#define MAX_NOME 50

// Função para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Struct para armazenar os dados do produto
typedef struct {
    int id;
    char nome[MAX_NOME];
    float preco;
} Produto;

// Array para armazenar os produtos
Produto produtos[MAX_PRODUTOS];
int numProdutos = 0;

// Função para cadastrar um novo produto
void cadastrarProduto() {
    if (numProdutos >= MAX_PRODUTOS) {
        printf("Limite maximo de produtos atingido.\n");
        return;
    }

    Produto novoProduto;
    printf("Digite o nome do Produto: ");
    if (fgets(novoProduto.nome, MAX_NOME, stdin) == NULL) {
        printf("Erro na leitura do nome do produto.\n");
        return;
    }
    novoProduto.nome[strcspn(novoProduto.nome, "\n")] = '\0'; // Remover o caractere de nova linha
    limparBuffer(); // Limpar o buffer de entrada

    printf("Digite o valor do Produto: ");
    if (scanf("%f", &novoProduto.preco) != 1) {
        printf("Entrada invalida para o valor do produto.\n");
        limparBuffer(); // Limpar o buffer de entrada
        return;
    }

    novoProduto.id = numProdutos + 1;
    produtos[numProdutos] = novoProduto;
    numProdutos++;

    printf("Produto cadastrado com sucesso!\n");
}

// Função para listar os produtos
void listarProdutos() {
    if (numProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("Produtos cadastrados:\n");
    int i;
    for (i = 0; i < numProdutos; i++) {
        printf("ID: %d, Nome: %s, Preco: %.2f\n", produtos[i].id, produtos[i].nome, produtos[i].preco);
    }
}

// Função para atualizar um produto
void atualizarProduto() {
    int id;
    printf("Digite o ID do produto que deseja atualizar: ");
    if (scanf("%d", &id) != 1) {
        printf("Entrada invalida para o ID do produto.\n");
        limparBuffer(); // Limpar o buffer de entrada
        return;
    }

    if (id < 1 || id > numProdutos) {
        printf("Produto nao encontrado.\n");
        return;
    }

    int index = id - 1;
    Produto *produtoAtualizar = &produtos[index];

    printf("Digite o novo nome do produto (deixe em branco para manter o atual): ");
    char novoNome[MAX_NOME];
    if (fgets(novoNome, MAX_NOME, stdin) != NULL) {
        novoNome[strcspn(novoNome, "\n")] = '\0'; // Remover o caractere de nova linha
        if (strlen(novoNome) > 0) {
            strcpy(produtoAtualizar->nome, novoNome);
        }
    }
    limparBuffer(); // Limpar o buffer de entrada

    printf("Digite o novo preco do produto (deixe em branco para manter o atual): ");
    float novoPreco;
    if (scanf("%f", &novoPreco) == 1) {
        produtoAtualizar->preco = novoPreco;
    }
    limparBuffer(); // Limpar o buffer de entrada

    printf("Produto atualizado com sucesso!\n");
}

// Função para excluir um produto
void excluirProduto() {
    int id;
    printf("Digite o ID do produto que deseja excluir: ");
    if (scanf("%d", &id) != 1) {
        printf("Entrada invalida para o ID do produto.\n");
        limparBuffer(); // Limpar o buffer de entrada
        return;
    }

    if (id < 1 || id > numProdutos) {
        printf("Produto nao encontrado.\n");
        return;
    }

    int index = id - 1;
    int i;
    for (i = index; i < numProdutos - 1; i++) {
        produtos[i] = produtos[i + 1];
    }
    produtos[numProdutos - 1] = (Produto){0}; // Zerar o último elemento
    numProdutos--;

    printf("Produto excluido com sucesso!\n");
}

// Função para gerar relatório dos produtos em um arquivo txt
void gerarRelatorioProdutos() {
    FILE *arquivo;
    arquivo = fopen("relatorio_produtos.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }

    fprintf(arquivo, "Relatorio de Produtos:\n\n");

    for (int i = 0; i < numProdutos; i++) {
        fprintf(arquivo, "ID: %d\n", produtos[i].id);
        fprintf(arquivo, "Nome: %s\n", produtos[i].nome);
        fprintf(arquivo, "Preco: %.2f\n\n", produtos[i].preco);
    }

    fclose(arquivo);
    printf("Relatorio gerado com sucesso no arquivo 'relatorio_produtos.txt'.\n");
}