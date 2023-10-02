#include <stdio.h>

struct Tipo {
    int valorInt;
    float valorFloat;
    char letra;
};

int main() {
    struct Tipo tipo1;

    tipo1.valorInt = 42;
    tipo1.valorFloat = 3.14;
    tipo1.letra = 'A';

    printf("Valor Inteiro: %d\n", tipo1.valorInt);
    printf("Valor de Ponto Flutuante: %.2f\n", tipo1.valorFloat);
    printf("Letra: %c\n", tipo1.letra);

    return 0;
}

