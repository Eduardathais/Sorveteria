
//Ignore apenas para teste // lebrete para modificar quando as outras funcionalidades forem implementadas
//char cpfCliente[12] = "12345678910";

#include <stdio.h>
#include <stdlib.h>

#define maxVendas 5
#define maxTotalVendas 100  // Capacidade máxima para armazenar todas as vendas, inclusive as excluídas

//Aqui começa ._.

typedef struct {
    int id;
    float peso;
    float precoPorKg;
    float valorTotalBuffet;
    int status;  // Campo para indicar se a venda está ativa ou foi removida
} VendaBuffet;

// VENDA DE BUFFET
VendaBuffet vendas[maxTotalVendas];  // Array estático para armazenar as vendas
int quantTotalVendas = 0;              // Contador de vendas totais (ativas e inativas)
int quantVendasAtivas = 0;             // Contador de vendas ativas
int proxId = 1;                        // Próximo ID a ser utilizado

void criarVendaBuffet() {
    int confirmarVenda = 0;

    if (quantVendasAtivas >= maxVendas) {
        printf("Limite de vendas válidas atingido. Exclua uma venda antes de adicionar outra.\n");
        return;
    }

    if (quantTotalVendas >= maxTotalVendas) {
        printf("Limite de armazenamento atingido. Não é possível adicionar mais vendas.\n");
        return;
    }

    vendas[quantTotalVendas].id = proxId++;
    printf("Digite o peso do buffet em kg(Ex: 2.5)\n");
    scanf("%f", &vendas[quantTotalVendas].peso);
    printf("\n");
    printf("Digite o preco por kg(Ex: 10.50)\n");
    scanf("%f", &vendas[quantTotalVendas].precoPorKg);
    printf("\n");

    vendas[quantTotalVendas].valorTotalBuffet = vendas[quantTotalVendas].peso * vendas[quantTotalVendas].precoPorKg;
    vendas[quantTotalVendas].status = 1;  // Marca a venda como ativa

    printf("O valor total ficou %.2f\n", vendas[quantTotalVendas].valorTotalBuffet);
    printf("Deseja realizar a Venda? 1 para sim 0 para nao\n");
    scanf("%i", &confirmarVenda);
    printf("\n");

    if (confirmarVenda == 1) {
        quantTotalVendas++;
        quantVendasAtivas++;
        printf("Venda Realizada!!!!\n");
    } else {
        vendas[quantTotalVendas].status = 0;  // Reverte a ativação se a venda não for confirmada
        printf("Venda não Realizada\n");
    }
}

void listarVendasBuffet() {
    int contagemListadas = 0;
    for (int i = 0; i < quantTotalVendas; i++) {
        if (vendas[i].status) {  // Só lista vendas ativas
            printf("ID: %d, Peso: %.2f, Preco por kg: %.2f, Valor total: %.2f\n", vendas[i].id, vendas[i].peso, vendas[i].precoPorKg, vendas[i].valorTotalBuffet);
            contagemListadas++;
            if (contagemListadas >= maxVendas) {
                break;  // Para depois de listar as 5 primeiras vendas válidas
            }
        }
    }
}

void excluirVendaBuffet(int idVenda) {
    for (int i = 0; i < quantTotalVendas; i++) {
        if (vendas[i].id == idVenda && vendas[i].status == 1) {
            vendas[i].status = 0;  // Marca a venda como inativa
            quantVendasAtivas--;  // Diminui o contador de vendas ativas
            printf("Venda com ID %d excluida.\n", idVenda);
            return;
        }
    }
    printf("Venda com ID %d não encontrada ou já excluída.\n", idVenda);
}

void editarVendaBuffet(int idVenda) {
    int opcao = 0, reEdit = 0, confirmaEdit = 0;
    char cpfCliente[12] = "12345678910"; // LEMBRAR DE RETIRAR SAPORRA

    for (int i = 0; i < quantTotalVendas; i++) {
        if (vendas[i].id == idVenda && vendas[i].status == 1) {
            do {
                printf("O que deseja editar?\n");
                printf("--- 1 - CPF cliente:  %s\n", cpfCliente);
                printf("--- 2 - Peso:  %.2f\n", vendas[i].peso);
                printf("--- 3 - Valor por quilo:  %.2f\n", vendas[i].precoPorKg);

                printf("Digite o numero da opcao que deseja editar: ");
                scanf("%d", &opcao);

                switch (opcao) {
                    case 1:
                        printf("Digite o novo CPF do cliente\n");
                        scanf("%s", cpfCliente);
                        printf("Confirma a edicao? 1 para sim, 0 para nao\n");
                        scanf("%i", &confirmaEdit);
                        if (confirmaEdit == 1) {
                            printf("Edicao concluida!\n");
                        } else {
                            printf("Edicao nao concluida!\n");
                        }
                        break;
                    case 2:
                        printf("Digite o novo peso em kg\n");
                        scanf("%f", &vendas[i].peso);
                        printf("Confirma a edicao? 1 para sim, 0 para nao\n");
                        scanf("%i", &confirmaEdit);
                        if (confirmaEdit == 1) {
                            printf("Edicao concluida!\n");
                            vendas[i].valorTotalBuffet = vendas[i].peso * vendas[i].precoPorKg;
                            printf("------------------------------------------\n");
                            printf("Com o peso sendo: %.2f e o preco por kg sendo: %.2f, o valor total ficou: %.2f\n", vendas[i].peso, vendas[i].precoPorKg, vendas[i].valorTotalBuffet);
                            printf("------------------------------------------\n");
                        } else {
                            printf("Edicao nao concluida!\n");
                        }
                        break;
                    case 3:
                        printf("Digite o novo valor por kg: ");
                        scanf("%f", &vendas[i].precoPorKg);
                        printf("Confirma a edicao? 1 para sim, 0 para nao\n");
                        scanf("%i", &confirmaEdit);
                        if (confirmaEdit == 1) {
                            printf("Edicao concluida!\n");
                            vendas[i].valorTotalBuffet = vendas[i].peso * vendas[i].precoPorKg;
                            printf("------------------------------------------\n");
                            printf("Com o peso sendo: %.2f e o preco por kg sendo: %.2f, o valor total ficou: %.2f\n", vendas[i].peso, vendas[i].precoPorKg, vendas[i].valorTotalBuffet);
                            printf("------------------------------------------\n");
                        } else {
                            printf("Edicao nao concluida!\n");
                        }
                        break;
                    default:
                        printf("Opcao invalida.\n");
                        return;
                }

                printf("Digite 1 para editar outro valor e 0 para voltar ao Menu Principal\n");
                scanf("%i", &reEdit);
                printf("------------------------------------------\n");
            } while (reEdit != 0);
            return;
        }
    }

    printf("Venda com ID %d nao encontrada ou ja excluida.\n", idVenda);
}

// VENDA DE ITENS !!!!NAO FINALIZADA!!!!!!!

typedef struct {
    int id;
    float precoUnitario;
} Item;

Item item = {222, 10}; //define valor fixo id = 222 e precoUnitario = 10

typedef struct {
    int id;
    int quantItem;
    float valorTotalItem; // quant item * preco unit
    int status;  // Campo para indicar se a venda está ativa ou foi removida
} VendaItem;

#define maxVendaItens 5

VendaItem vendasItens[maxTotalVendas]; // Array estático para armazenar as vendas de itens
int quantTotalVendasItens = 0;         // Contador de vendas totais de itens (ativas e inativas)
int quantVendasAtivasItens = 0;        // Contador de vendas ativas de itens
int proxIdItem = 1;


void criarVendaItem() {

    if (quantVendasAtivasItens >= maxVendaItens) {
        printf("Limite de vendas de itens validas atingido. Exclua uma venda antes de adicionar outra.\n");
        return;
    }

    if (quantTotalVendasItens >= maxTotalVendas) {
        printf("Limite de armazenamento de vendas de itens atingido. Nao e possivel adicionar mais vendas.\n");
        return;
    }

    VendaItem novaVendaItem;
    novaVendaItem.id = proxIdItem++;
    novaVendaItem.status = 1; // Marca a venda de itens como ativa
    novaVendaItem.valorTotalItem = 0; // Inicializa o valor total da venda como zero

    printf("Criando nova venda de itens...\n");

    int adicionarMaisItens;
    do {
        int idItem;
        int quantidadeItem;

        printf("Digite o ID do item\n");
        scanf("%d", &idItem);
        printf("O preco unitario do item eh: %.2f\n", item.precoUnitario);
        printf("Digite a quantidade do item\n");
        scanf("%d", &quantidadeItem);

        // Atualiza o valor total da venda de itens
        novaVendaItem.valorTotalItem += quantidadeItem * item.precoUnitario;

        // Adiciona o item a venda de itens
        printf("Item adicionado a venda de itens.\n");
        printf("Valor total ficou: %.2f\n", novaVendaItem.valorTotalItem);
        printf("Deseja adicionar mais itens a venda? (1 para sim, 0 para finalizar a venda): ");
        scanf("%d", &adicionarMaisItens);
    } while (adicionarMaisItens == 1);

    // Adiciona a nova venda de itens a lista de vendas
    vendasItens[quantTotalVendasItens] = novaVendaItem;
    quantTotalVendasItens++;
    quantVendasAtivasItens++;

    printf("Venda de itens realizada!\n");
}

void listarVendasItens() {
    int contagemListadas = 0;
    for (int i = 0; i < quantTotalVendasItens; i++) {
        if (vendasItens[i].status) {  // Só lista vendas ativas
            printf("ID: %d, Quantidade de Itens: %d, Valor total: %.2f\n", vendasItens[i].id, vendasItens[i].quantItem, vendasItens[i].valorTotalItem);
            contagemListadas++;
            if (contagemListadas >= maxVendaItens) {
                break;  // Para depois de listar as 5 primeiras vendas válidas
            }
        }
    }
}

void excluirVendaItem(int idVenda) {
    for (int i = 0; i < quantTotalVendasItens; i++) {
        if (vendasItens[i].id == idVenda && vendasItens[i].status == 1) {
            vendasItens[i].status = 0;  // Marca a venda como inativa
            quantVendasAtivasItens--;  // Diminui o contador de vendas ativas
            printf("Venda com ID %d excluida.\n", idVenda);
            return;
        }
    }
    printf("Venda com ID %d nao encontrada ou ja excluida.\n", idVenda);
}

void editarVendaItem(int idVenda) {
    int opcao = 0, reEdit = 0, confirmaEdit = 0;

    for (int i = 0; i < quantTotalVendasItens; i++) {
        if (vendasItens[i].id == idVenda && vendasItens[i].status == 1) {
            do {
                printf("O que deseja editar?\n");
                printf("--- 1 - Quantidade de Itens: %d\n", vendasItens[i].quantItem);
                printf("--- 2 - Preco unitario do item: %.2f\n", item.precoUnitario);

                printf("Digite o numero da opcao que deseja editar: ");
                scanf("%d", &opcao);

                switch (opcao) {
                    case 1:
                        printf("Digite a nova quantidade de itens\n");
                        scanf("%d", &vendasItens[i].quantItem);
                        printf("Confirma a edicao? 1 para sim, 0 para nao\n");
                        scanf("%i", &confirmaEdit);
                        if (confirmaEdit == 1) {
                            vendasItens[i].valorTotalItem = vendasItens[i].quantItem * item.precoUnitario;
                            printf("Edicao concluida!\n");
                            printf("Com a quantidade sendo: %d e o preco unitario sendo: %.2f, o valor total ficou: %.2f\n", vendasItens[i].quantItem, item.precoUnitario, vendasItens[i].valorTotalItem);
                        } else {
                            printf("Edicao nao concluida!\n");
                        }
                        break;
                    case 2:
                        printf("Digite o novo preco unitario do item\n");
                        scanf("%f", &item.precoUnitario);
                        printf("Confirma a edicao? 1 para sim, 0 para nao\n");
                        scanf("%i", &confirmaEdit);
                        if (confirmaEdit == 1) {
                            vendasItens[i].valorTotalItem = vendasItens[i].quantItem * item.precoUnitario;
                            printf("Edicao concluida!\n");
                            printf("Com a quantidade sendo: %d e o preco unitario sendo: %.2f, o valor total ficou: %.2f\n", vendasItens[i].quantItem, item.precoUnitario, vendasItens[i].valorTotalItem);
                        } else {
                            printf("Edicao nao concluida!\n");
                        }
                        break;
                    default:
                        printf("Opcao invalida.\n");
                        return;
                }

                printf("Digite 1 para editar outro valor e 0 para voltar ao Menu Principal\n");
                scanf("%i", &reEdit);
                printf("------------------------------------------\n");
            } while (reEdit != 0);
            return;
        }
    }

    printf("Venda com ID %d nao encontrada ou ja excluida.\n", idVenda);
}