#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CLIENTES 5

// Estrutura para armazenar os dados de um cliente
struct cadastro {
    char nome[100];
    char CPF[20];
    char endereco[200];
    char telefone[20];
    int id;
} cliente[MAX_CLIENTES];

int num_clientes = 0; // Contador para o número de clientes cadastrados
int ids_usados[MAX_CLIENTES] = {0}; // Array para armazenar os IDs já usados

// Função para limpar o buffer do stdin
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// Função para verificar se um ID já foi usado
int id_ja_usado(int id) {
    for (int i = 0; i < num_clientes; i++) {
        if (ids_usados[i] == id) {
            return 1;
        }
    }
    return 0;
}

// Função para gerar um ID aleatório único
int gerar_id_aleatorio() {
    int id;
    do {
        id = rand() % 100 + 1; // Gera um ID entre 1 e 100
    } while (id_ja_usado(id));
    return id;
}

// Função para cadastrar um novo cliente
void novo_cadastro() {
    // Verifica se ainda há espaço para novos cadastros
    if (num_clientes < MAX_CLIENTES) {
        // Solicita e armazena o nome do cliente
        printf("\nNome do cliente:\n");
        fgets(cliente[num_clientes].nome, sizeof(cliente[num_clientes].nome), stdin);
        cliente[num_clientes].nome[strcspn(cliente[num_clientes].nome, "\n")] = '\0';
        limpar_buffer(); // Limpa o buffer de entrada

        // Solicita e armazena o CPF do cliente
        printf("Digite o CPF:\n");
        fgets(cliente[num_clientes].CPF, sizeof(cliente[num_clientes].CPF), stdin);
        cliente[num_clientes].CPF[strcspn(cliente[num_clientes].CPF, "\n")] = '\0';
        limpar_buffer(); // Limpa o buffer de entrada

        // Solicita e armazena o endereço do cliente
        printf("Endereco:\n");
        fgets(cliente[num_clientes].endereco, sizeof(cliente[num_clientes].endereco), stdin);
        cliente[num_clientes].endereco[strcspn(cliente[num_clientes].endereco, "\n")] = '\0';
        limpar_buffer(); // Limpa o buffer de entrada

        // Solicita e armazena o telefone do cliente
        printf("Numero de telefone com DDD:\n");
        fgets(cliente[num_clientes].telefone, sizeof(cliente[num_clientes].telefone), stdin);
        cliente[num_clientes].telefone[strcspn(cliente[num_clientes].telefone, "\n")] = '\0';
        limpar_buffer(); // Limpa o buffer de entrada

        // Gera um ID aleatório único para o cliente
        cliente[num_clientes].id = gerar_id_aleatorio();
        ids_usados[num_clientes] = cliente[num_clientes].id;

        num_clientes++;
        printf("Cliente cadastrado com sucesso! ID: %d\n", cliente[num_clientes-1].id);
    } else {
        printf("Cadastro completo. Nao eh possivel cadastrar mais clientes\n");
    }
}

// Função para listar todos os clientes cadastrados
void listar_cadastros() {
    printf("Lista de clientes cadastrados:\n");
    // Percorre a lista de clientes e imprime os dados de cada um
    for (int j = 0; j < num_clientes; j++) {
        if (strlen(cliente[j].nome) > 0) {
            printf("\nID: %d\nNome: %s\nCPF: %s\nEndereco: %s\nTelefone: %s\n",
                   cliente[j].id, cliente[j].nome, cliente[j].CPF, cliente[j].endereco, cliente[j].telefone);
        }
    }
}

// Função para editar os dados de um cliente
void editar_cadastro() {
    int editar_id;
    int editar_index = -1;

    listar_cadastros();
    printf("Digite o ID do cliente que deseja editar:\n");
    scanf("%d", &editar_id);
    limpar_buffer();

    // Procura o cliente pelo ID fornecido
    for (int j = 0; j < num_clientes; j++) {
        if (cliente[j].id == editar_id) {
            editar_index = j;
            break;
        }
    }

    if (editar_index == -1) {
        printf("Cliente nao encontrado.\n");
        return;
    }

    printf("Editando cliente com ID %d:\n", editar_id);

    // Permite a edição dos dados do cliente, mantendo os dados atuais se o usuário pressionar Enter
    printf("Nome atual: %s\n", cliente[editar_index].nome);
    printf("Digite o novo nome (ou pressione Enter para manter):\n");
    char novo_nome[100];
    fgets(novo_nome, sizeof(novo_nome), stdin);
    if (strcmp(novo_nome, "\n") != 0) {
        novo_nome[strcspn(novo_nome, "\n")] = '\0';
        strcpy(cliente[editar_index].nome, novo_nome);
    }

    printf("CPF atual: %s\n", cliente[editar_index].CPF);
    printf("Digite o novo CPF (ou pressione Enter para manter):\n");
    char novo_CPF[20];
    fgets(novo_CPF, sizeof(novo_CPF), stdin);
    if (strcmp(novo_CPF, "\n") != 0) {
        novo_CPF[strcspn(novo_CPF, "\n")] = '\0';
        strcpy(cliente[editar_index].CPF, novo_CPF);
    }

    printf("Endereco atual: %s\n", cliente[editar_index].endereco);
    printf("Digite o novo endereco (ou pressione Enter para manter):\n");
    char novo_endereco[200];
    fgets(novo_endereco, sizeof(novo_endereco), stdin);
    if (strcmp(novo_endereco, "\n") != 0) {
        novo_endereco[strcspn(novo_endereco, "\n")] = '\0';
        strcpy(cliente[editar_index].endereco, novo_endereco);
    }

    printf("Numero de telefone atual: %s\n", cliente[editar_index].telefone);
    printf("Digite o novo numero de telefone (ou pressione Enter para manter):\n");
    char novo_telefone[20];
    fgets(novo_telefone, sizeof(novo_telefone), stdin);
    if (strcmp(novo_telefone, "\n") != 0) {
        novo_telefone[strcspn(novo_telefone, "\n")] = '\0';
        strcpy(cliente[editar_index].telefone, novo_telefone);
    }

    printf("Cliente com ID %d atualizado.\n", editar_id);
}

// Função para excluir um cliente
void excluir_cadastro() {
    int excluir_id;
    int excluir = -1;

    listar_cadastros();
    printf("Digite o ID do cliente que deseja excluir:\n");
    scanf("%d", &excluir_id);
    limpar_buffer();

    // Procura o cliente pelo ID fornecido
    for (int j = 0; j < num_clientes; j++) {
        if (cliente[j].id == excluir_id) {
            excluir = j;
            break;
        }
    }

    if (excluir == -1) {
        printf("Cliente nao encontrado.\n");
        return;
    }

    // Remove o cliente deslocando os elementos seguintes para a esquerda
    for (int j = excluir; j < num_clientes - 1; j++) {
        cliente[j] = cliente[j + 1];
        ids_usados[j] = ids_usados[j + 1];
    }
    num_clientes--;

    printf("Cliente com ID %d excluido\n", excluir_id);
}

// Função para gerar relatório dos clientes
void gerarRelatorioClientes() {
    FILE *arquivo;
    arquivo = fopen("relatorio_clientes.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }

    fprintf(arquivo, "Relatorio de Clientes:\n\n");

    for (int i = 0; i < num_clientes; i++) {
        fprintf(arquivo, "ID: %d\n", cliente[i].id);
        fprintf(arquivo, "Nome: %s\n", cliente[i].nome);
        fprintf(arquivo, "CPF: %s\n", cliente[i].CPF);
        fprintf(arquivo, "Endereco: %s\n", cliente[i].endereco);
        fprintf(arquivo, "Telefone: %s\n\n", cliente[i].telefone);
    }

    fclose(arquivo);
    printf("Relatorio gerado com sucesso no arquivo 'relatorio_clientes.txt'.\n");
}