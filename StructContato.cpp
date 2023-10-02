#include <stdio.h>
#include <string.h>

struct Contato {
    char nome[50];
    char telefone[15];
};

void adicionarContato(struct Contato agenda[], int *numContatos) {
    if (*numContatos < 100) {
        printf("Digite o nome do contato: ");
        scanf("%s", agenda[*numContatos].nome);

        printf("Digite o telefone do contato: ");
        scanf("%s", agenda[*numContatos].telefone);

        (*numContatos)++;
        printf("Contato adicionado com sucesso.\n");
    } else {
        printf("A agenda está cheia. Não é possível adicionar mais contatos.\n");
    }
}

void listarContatos(struct Contato agenda[], int numContatos) {
    printf("Lista de Contatos:\n");
    for (int i = 0; i < numContatos; i++) {
        printf("Nome: %s\n", agenda[i].nome);
        printf("Telefone: %s\n", agenda[i].telefone);
        printf("\n");
    }
}

int buscarContato(struct Contato agenda[], int numContatos, char nomeBuscado[50]) {
    for (int i = 0; i < numContatos; i++) {
        if (strcmp(agenda[i].nome, nomeBuscado) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    struct Contato agenda[100];
    int numContatos = 0;

    int escolha;
    char nomeBuscado[50];
    int indiceEncontrado;

    while (1) {
        printf("\nEscolha uma opcao:\n");
        printf("1 - Adicionar Contato\n");
        printf("2 - Listar Contatos\n");
        printf("3 - Buscar Contato\n");
        printf("4 - Sair\n");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                adicionarContato(agenda, &numContatos);
                break;
            case 2:
                listarContatos(agenda, numContatos);
                break;
            case 3:
                printf("Digite o nome do contato a ser buscado: ");
                scanf("%s", nomeBuscado);
                indiceEncontrado = buscarContato(agenda, numContatos, nomeBuscado);
                if (indiceEncontrado != -1) {
                    printf("Contato encontrado:\n");
                    printf("Nome: %s\n", agenda[indiceEncontrado].nome);
                    printf("Telefone: %s\n", agenda[indiceEncontrado].telefone);
                } else {
                    printf("Contato nao encontrado.\n");
                }
                break;
            case 4:
                return 0;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }

    return 0;
}

