#include <stdio.h>

struct ContaBancaria {
    char nomeTitular[50];
    int numeroConta;
    float saldo;
};

void depositar(struct ContaBancaria *conta, float valor) {
    conta->saldo += valor;
    printf("Deposito de %.2f realizado com sucesso.\n", valor);
}

int sacar(struct ContaBancaria *conta, float valor) {
    if (valor <= conta->saldo) {
        conta->saldo -= valor;
        printf("Saque de %.2f realizado com sucesso.\n", valor);
        return 1; // Saque bem-sucedido
    } else {
        printf("Saldo insuficiente para realizar o saque.\n");
        return 0; // Saldo insuficiente
    }
}

float verificarSaldo(struct ContaBancaria conta) {
    return conta.saldo;
}

int main() {
    struct ContaBancaria conta1;
    conta1.saldo = 1000.0; // Saldo inicial

    printf("Digite o nome do titular da conta: ");
    scanf("%s", conta1.nomeTitular);

    printf("Digite o numero da conta: ");
    scanf("%d", &conta1.numeroConta);

    printf("\nConta criada com sucesso.\n");

    int escolha;
    float valor;

    while (1) {
        printf("\nEscolha uma opcao:\n");
        printf("1 - Depositar\n");
        printf("2 - Sacar\n");
        printf("3 - Verificar Saldo\n");
        printf("4 - Sair\n");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o valor a ser depositado: ");
                scanf("%f", &valor);
                depositar(&conta1, valor);
                break;
            case 2:
                printf("Digite o valor a ser sacado: ");
                scanf("%f", &valor);
                if (sacar(&conta1, valor)) {
                    printf("Saldo restante: %.2f\n", verificarSaldo(conta1));
                }
                break;
            case 3:
                printf("Saldo: %.2f\n", verificarSaldo(conta1));
                break;
            case 4:
                return 0;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }

    return 0;
}

