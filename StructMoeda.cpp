#include <stdio.h>

struct Moeda {
    float dolares;
    float euros;
};

float converterDolaresParaEuros(float dolares, float taxa) {
    return dolares * taxa;
}

float converterEurosParaDolares(float euros, float taxa) {
    return euros / taxa;
}

int main() {
    struct Moeda moeda1;
    float taxaCambio = 0.85; // Taxa de c�mbio (1 d�lar = 0.85 euros)

    printf("Digite a quantidade de d�lares: ");
    scanf("%f", &moeda1.dolares);

    printf("Digite a quantidade de euros: ");
    scanf("%f", &moeda1.euros);

    float conversaoDolaresParaEuros = converterDolaresParaEuros(moeda1.dolares, taxaCambio);
    float conversaoEurosParaDolares = converterEurosParaDolares(moeda1.euros, taxaCambio);

    printf("Conversao de D�lares para Euros: %.2f euros\n", conversaoDolaresParaEuros);
    printf("Conversao de Euros para D�lares: %.2f d�lares\n", conversaoEurosParaDolares);

    return 0;
}

