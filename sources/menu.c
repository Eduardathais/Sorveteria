#include <stdio.h>
#include <stdlib.h>
#include "../Headers/venda.h"
#include "../Headers/cadastro-clientes.h"
#include "../Headers/produtos.h"

int main() {
    int opcao = 0, retry = 0, tipoVenda = 0, tipoListaVenda = 0;
    int idVenda = 0;

    do {
        system("cls"); // limpa o terminal
        printf("\n");
        printf("Seja Bem Vindo! O que deseja Realizar?\n");
        printf("\n");
        printf("------------------------------------------\n");
        printf("-- 1 - Realizar Venda\n");
        printf("-- 2 - Editar Venda\n");
        printf("-- 3 - Listar vendas efetuadas\n");
        printf("-- 4 - Excluir Venda\n");
        printf("------------------------------------------\n");
        printf("\n");
        printf("------------------------------------------\n");
        printf("-- 5 - Mostrar Carrinho\n");
        printf("-- 6 - Excluir Item do Carrinho\n");
        printf("------------------------------------------\n");
        printf("\n");
        printf("------------------------------------------\n");
        printf("-- 7 - Cadastro de item\n");
        printf("-- 8 - Editar item\n");
        printf("-- 9 - Listar itens cadastrados\n");
        printf("-- 10 - Excluir Item\n");
        printf("------------------------------------------\n");
        printf("\n");
        printf("-- 11 - Cadastro de Cliente\n");
        printf("-- 12 - Editar Cliente\n");
        printf("-- 13 - Listar Clientes cadastrados\n");
        printf("-- 14 - Excluir Cliente\n");
        printf("------------------------------------------\n");
        printf("\n");
        printf("-- 15 - Emitir Relatorio de Clientes\n");
        printf("-- 16 - Emitir Relatorio de Produtos\n");
        printf("-- 17 - Emitir Relatorio de Vendas\n");
        printf("------------------------------------------\n");
        printf("\n");

        printf("------------------------------------------\n");
        printf("Digite o numero da funcao desejada\n");
        scanf("%i", &opcao);
        printf("\n");

        limpar_buffer(); // Limpa o buffer de entrada

        switch (opcao) {
            case 1:
                printf("--- Qual o tipo da venda que deseja realizar?\n");
                printf("--- 1 - Buffet\n");
                printf("--- 2 - Itens\n");
                scanf("%i", &tipoVenda);
                printf("\n");

                limpar_buffer(); // Limpa o buffer de entrada

                if (tipoVenda == 1) {
                    printf("------------------------------------------\n");
                    criarVendaBuffet();
                    printf("------------------------------------------\n");
                } else if (tipoVenda == 2) {
                    printf("------------------------------------------\n");
                    criarVendaItem();
                    printf("------------------------------------------\n");
                } else {
                    printf("Tipo de Venda Invalido!!\n");
                }
                break;

            case 2:
                printf("------------------------------------------\n");
                printf("Digite o ID da venda que deseja editar: ");
                scanf("%d", &idVenda);
                printf("\n");

                limpar_buffer(); // Limpa o buffer de entrada

                editarVendaBuffet(idVenda);
                printf("------------------------------------------\n");
                break;

            case 3:
                printf("--- Qual tipo de venda deseja listar?\n");
                printf("--- 1 - Vendas de Buffet\n");
                printf("--- 2 - Vendas de Itens\n");
                printf("--- 3 - Listar as vendas de Buffet e Itens\n");
                printf("------------------------------------------\n");
                printf("--- 4 - Listar as vendas de buffet excluidas\n");
                printf("--- 5 - Listar as vendas de Itens excluidas\n");
                printf("--- 6 - Listar as vendas de Itens e Buffet excluida\n");
                scanf("%i", &tipoListaVenda);
                printf("\n");

                limpar_buffer(); // Limpa o buffer de entrada

                switch (tipoListaVenda) {
                    case 1:
                        printf("------------------------------------------\n");
                        listarVendasBuffet();
                        printf("------------------------------------------\n");
                        break;
                    case 2:
                        printf("------------------------------------------\n");
                        listarVendasItens();
                        printf("------------------------------------------\n");
                        break;
                    case 3:
                        printf("------------------------------------------\n");
                        printf("---Vendas Buffet\n");
                        listarVendasBuffet();
                        printf("------------------------------------------\n");
                        printf("------------------------------------------\n");
                        printf("---Vendas Itens\n");
                        listarVendasItens();
                        printf("------------------------------------------\n");
                        break;
                    default:
                        printf("Opção Inválida!!!");
                        break;
                }
                break;

            case 4:
                printf("------------------------------------------\n");
                printf("Digite o ID da venda que deseja excluir: ");
                scanf("%d", &idVenda);
                printf("\n");

                limpar_buffer(); // Limpa o buffer de entrada

                excluirVendaBuffet(idVenda);
                printf("------------------------------------------\n");
                break;

            case 5:
                mostrarCarrinho();
                break;

            case 6:
                removerItemDoCarrinho();
                break;

            case 7:
                cadastrarProduto();
                break;

            case 8:
                atualizarProduto();
                break;

            case 9:
                listarProdutos();
                break;

            case 10:
                excluirProduto();
                break;

            case 11:
                novo_cadastro();
                break;

            case 12:
                editar_cadastro();
                break;

            case 13:
                listar_cadastros();
                break;

            case 14:
                excluir_cadastro();
                break;

            case 15:
                gerarRelatorioClientes();
                break;

            case 16:
                gerarRelatorioProdutos();
                break;

            case 17:
                gerarRelatorioVendas();
                break;

            default:
                printf("Opcao Invalida!!!\n");
                break;
        }

        printf("\n");
        printf("Digite 1 para voltar ao menu ou 0 para sair do programa.\n");
        scanf("%i", &retry);
        printf("\n");

        limpar_buffer(); // Limpa o buffer de entrada

    } while (retry != 0);

    return 0;
}