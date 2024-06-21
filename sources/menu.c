#include <stdio.h>
#include <stdlib.h>
#include "../Headers/vendaBuffet.h"

int main(){
    int opcao = 0, retry = 0,tipoVenda = 0,tipoListaVenda = 0;
    int idVenda = 0;

    do{
    system("cls"); // limpa o terminal
    printf("\n");
    printf("Seja Bem Vindo! O que deseja Realizar?\n");
    printf("\n");
    printf("------------------------------------------\n");
    printf("-- 1 - Cadastro de item\n");
    printf("-- 2 - Editar item\n");
    printf("-- 3 - Listar itens cadastrados\n");
    printf("-- 4 - Excluir Item\n");
    printf("------------------------------------------\n");
    printf("\n");
    printf("------------------------------------------\n");
    printf("-- 5 - Realizar Venda\n");
    printf("-- 6 - Editar Venda\n");
    printf("-- 7 - Listar vendas efetuadas\n");
    printf("-- 8 - Excluir Venda\n");
    
    printf("------------------------------------------\n");
    printf("Digite o numero da funcao desejada\n");
    scanf("%i", &opcao);
    printf("\n");

    switch(opcao){
        case 1:
            // Função para cadastro de item
        break;
        case 2:
            // Função para editar item
        break;
        case 3:
            // Função para listar itens cadastrados
        break;
        case 4:
            // Função para excluir item
        break;
        case 5:
            printf("--- Qual o tipo da venda que deseja realizar?\n");
            printf("--- 1 - Buffet\n");
            printf("--- 2 - Itens\n");
            scanf("%i", &tipoVenda);
            printf("\n");
            if(tipoVenda == 1){
                printf("------------------------------------------\n");
                criarVendaBuffet();
                printf("------------------------------------------\n");
            } else if(tipoVenda == 2){
                printf("------------------------------------------\n");
                criarVendaItem();
                printf("------------------------------------------\n");

            }else{
                printf("Tipo de Venda Invalido!!\n");
            }
            
        break;
        case 6:
            printf("------------------------------------------\n");
            printf("Digite o ID da venda que deseja editar: ");
            scanf("%d", &idVenda);
            editarVendaBuffet(idVenda);
            printf("------------------------------------------\n");
        break;
        case 7:
            printf("--- Qual tipo de venda deseja listar?\n");
            printf("--- 1 - Vendas de Buffet\n");
            printf("--- 2 - Vendas de Itens\n");
            printf("--- 3 - Listar as vendas de Buffet e Itens\n");
            printf("------------------------------------------\n");
            printf("--- 4 - Listar as vendas de buffet excluidas\n");
            printf("--- 5 - Listar as vendas de Itens excluidas\n");
            printf("--- 6 - Listar as vendas de Itens e Buffet excluida\n");
            scanf("%i", &tipoListaVenda);

            switch(tipoListaVenda){
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
        case 8:
            printf("------------------------------------------\n");
            printf("Digite o ID da venda que deseja excluir: ");
            scanf("%d", &idVenda);
            excluirVendaBuffet(idVenda);
            printf("------------------------------------------\n");
        break;
        default:
            printf("Opcao Invalida!!!\n");
        break;
    }
    printf("\n");
    printf("Digite 1 para voltar ao menu ou 0 para sair do programa.\n");
    scanf("%i", &retry);
    }while(retry != 0);

    return 0;
    
}