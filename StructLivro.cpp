#include <stdio.h>
#include <string.h>

struct Livro {
    char titulo[100];
    char autor[50];
    int anoPublicacao;
};

void adicionarLivro(struct Livro biblioteca[], int *numLivros) {
    if (*numLivros < 100) {
        printf("Digite o titulo do livro: ");
        scanf(" %[^\n]s", biblioteca[*numLivros].titulo);

        printf("Digite o autor do livro: ");
        scanf(" %[^\n]s", biblioteca[*numLivros].autor);

        printf("Digite o ano de publicacao do livro: ");
        scanf("%d", &biblioteca[*numLivros].anoPublicacao);

        (*numLivros)++;
        printf("Livro adicionado com sucesso.\n");
    } else {
        printf("A biblioteca esta cheia. Nao e possivel adicionar mais livros.\n");
    }
}

void listarLivros(struct Livro biblioteca[], int numLivros) {
    printf("Lista de Livros:\n");
    for (int i = 0; i < numLivros; i++) {
        printf("Titulo: %s\n", biblioteca[i].titulo);
        printf("Autor: %s\n", biblioteca[i].autor);
        printf("Ano de Publicacao: %d\n", biblioteca[i].anoPublicacao);
        printf("\n");
    }
}

int buscarLivroPorAutor(struct Livro biblioteca[], int numLivros, char autorBuscado[50]) {
    for (int i = 0; i < numLivros; i++) {
        if (strcmp(biblioteca[i].autor, autorBuscado) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    struct Livro biblioteca[100];
    int numLivros = 0;

    int escolha;
    char autorBuscado[50];
    int indiceEncontrado;

    while (1) {
        printf("\nEscolha uma opcao:\n");
        printf("1 - Adicionar Livro\n");
        printf("2 - Listar Livros\n");
        printf("3 - Buscar Livro por Autor\n");
        printf("4 - Sair\n");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                adicionarLivro(biblioteca, &numLivros);
                break;
            case 2:
                listarLivros(biblioteca, numLivros);
                break;
            case 3:
                printf("Digite o autor do livro a ser buscado: ");
                scanf(" %[^\n]s", autorBuscado);
                indiceEncontrado = buscarLivroPorAutor(biblioteca, numLivros, autorBuscado);
                if (indiceEncontrado != -1) {
                    printf("Livro encontrado:\n");
                    printf("Titulo: %s\n", biblioteca[indiceEncontrado].titulo);
                    printf("Autor: %s\n", biblioteca[indiceEncontrado].autor);
                    printf("Ano de Publicacao: %d\n", biblioteca[indiceEncontrado].anoPublicacao);
                } else {
                    printf("Livro nao encontrado.\n");
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

