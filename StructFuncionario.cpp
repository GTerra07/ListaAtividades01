#include <stdio.h>
#include <time.h>

struct Funcionario {
    char nome[50];
    char cargo[50];
    float salario;
    time_t dataAdmissao; // Data de admissão em segundos desde 01/01/1970
};

void darAumento(struct Funcionario *funcionario, float percentual) {
    funcionario->salario *= (1.0 + percentual / 100.0);
    printf("Aumento de %.2f%% aplicado com sucesso.\n", percentual);
}

int calcularTempoEmpresa(struct Funcionario funcionario) {
    time_t agora;
    time(&agora);
    int tempoEmSegundos = difftime(agora, funcionario.dataAdmissao);
    int tempoEmAnos = tempoEmSegundos / (365 * 24 * 60 * 60);
    return tempoEmAnos;
}

int main() {
    struct Funcionario funcionario1;

    printf("Digite o nome do funcionario: ");
    scanf(" %[^\n]s", funcionario1.nome);

    printf("Digite o cargo do funcionario: ");
    scanf(" %[^\n]s", funcionario1.cargo);

    printf("Digite o salario do funcionario: ");
    scanf("%f", &funcionario1.salario);

    funcionario1.dataAdmissao = time(NULL); // Define a data de admissão como a data atual

    printf("\nFuncionario cadastrado com sucesso.\n");

    int escolha;
    float percentual;

    while (1) {
        printf("\nEscolha uma opcao:\n");
        printf("1 - Dar Aumento\n");
        printf("2 - Calcular Tempo na Empresa\n");
        printf("3 - Sair\n");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o percentual de aumento: ");
                scanf("%f", &percentual);
                darAumento(&funcionario1, percentual);
                break;
            case 2:
                printf("Tempo na empresa: %d anos\n", calcularTempoEmpresa(funcionario1));
                break;
            case 3:
                return 0;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }

    return 0;
}

