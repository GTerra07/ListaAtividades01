#include <stdio.h>
#include <math.h>

struct Ponto {
    float x;
    float y;
};

float calcularDistancia(struct Ponto p1, struct Ponto p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

float calcularInclinacao(struct Ponto p1, struct Ponto p2) {
    return (p2.y - p1.y) / (p2.x - p1.x);
}

int main() {
    struct Ponto ponto1, ponto2;

    printf("Digite as coordenadas do primeiro ponto (x y): ");
    scanf("%f %f", &ponto1.x, &ponto1.y);

    printf("Digite as coordenadas do segundo ponto (x y): ");
    scanf("%f %f", &ponto2.x, &ponto2.y);

    printf("Distancia entre os pontos: %.2f\n", calcularDistancia(ponto1, ponto2));
    printf("Inclinacao da reta que conecta os pontos: %.2f\n", calcularInclinacao(ponto1, ponto2));

    return 0;
}

