#include <stdio.h>

struct Estudante {
    char nome[50];
    int matricula;
    float notas[3];
};

float calcularMedia(struct Estudante aluno) {
    return (aluno.notas[0] + aluno.notas[1] + aluno.notas[2]) / 3.0;
}

int estaAprovado(struct Estudante aluno) {
    float media = calcularMedia(aluno);
    return (media >= 7.0) ? 1 : 0;
}

int main() {
    struct Estudante estudante1;

    printf("Digite o nome do estudante: ");
    scanf("%s", estudante1.nome);

    printf("Digite a matricula do estudante: ");
    scanf("%d", &estudante1.matricula);

    printf("Digite as notas do estudante (3 notas separadas por espaco): ");
    scanf("%f %f %f", &estudante1.notas[0], &estudante1.notas[1], &estudante1.notas[2]);

    printf("\nDados do estudante:\n");
    printf("Nome: %s\n", estudante1.nome);
    printf("Matricula: %d\n", estudante1.matricula);
    printf("Notas: %.2f, %.2f, %.2f\n", estudante1.notas[0], estudante1.notas[1], estudante1.notas[2]);
    printf("Media: %.2f\n", calcularMedia(estudante1));

    if (estaAprovado(estudante1)) {
        printf("Status: Aprovado\n");
    } else {
        printf("Status: Reprovado\n");
    }

    return 0;
}

