// relatorio.c

#include <stdio.h>
#include "vendaBuffet.h" // Inclua o arquivo de header onde estão suas estruturas e variáveis de vendas

void gerarRelatorioVendas() {
    FILE *arquivo;
    arquivo = fopen("relatorio_vendas.txt", "w"); // Abre o arquivo para escrita (sobrescreve se já existir)

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    fprintf(arquivo, "Relatório de Vendas\n\n");

    // Escreve as vendas de buffet
    fprintf(arquivo, "Vendas de Buffet:\n");
    for (int i = 0; i < quantTotalVendas; i++) {
        if (vendas[i].status) {
            fprintf(arquivo, "ID: %d, Peso: %.2f kg, Preço por kg: R$ %.2f, Valor total: R$ %.2f\n",
                    vendas[i].id, vendas[i].peso, vendas[i].precoPorKg, vendas[i].valorTotalBuffet);
        }
    }
    fprintf(arquivo, "\n");

    // Escreve as vendas de itens
    fprintf(arquivo, "Vendas de Itens:\n");
    for (int i = 0; i < quantTotalVendasItens; i++) {
        if (vendasItens[i].status) {
            fprintf(arquivo, "ID: %d, Quantidade de Itens: %d, Valor total: R$ %.2f\n",
                    vendasItens[i].id, vendasItens[i].quantItem, vendasItens[i].valorTotalItem);
        }
    }

    fclose(arquivo); // Fecha o arquivo após terminar de escrever
    printf("Relatório de vendas gerado com sucesso (verifique o arquivo relatorio_vendas.txt).\n");
}
