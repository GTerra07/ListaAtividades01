#include <stdio.h>

struct Produto {
    char nome[100];
    float preco;
    int quantidadeEstoque;
};

void comprarProduto(struct Produto *produto, int quantidade) {
    if (quantidade <= produto->quantidadeEstoque) {
        produto->quantidadeEstoque -= quantidade;
        printf("Compra realizada com sucesso.\n");
    } else {
        printf("Quantidade em estoque insuficiente.\n");
    }
}

float calcularTotalCompra(struct Produto produto, int quantidade) {
    return produto.preco * quantidade;
}

int main() {
    struct Produto produto1;
    produto1.preco = 10.0; // Preço do produto
    produto1.quantidadeEstoque = 50; // Quantidade inicial em estoque

    printf("Digite o nome do produto: ");
    scanf(" %[^\n]s", produto1.nome);

    printf("\nProduto cadastrado com sucesso.\n");

    int escolha;
    int quantidade;

    while (1) {
        printf("\nEscolha uma opcao:\n");
        printf("1 - Comprar Produto\n");
        printf("2 - Sair\n");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite a quantidade desejada: ");
                scanf("%d", &quantidade);
                comprarProduto(&produto1, quantidade);
                break;
            case 2:
                return 0;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }

    return 0;
}

