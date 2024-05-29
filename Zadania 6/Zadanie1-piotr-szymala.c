#include <stdio.h>

// Definicja unii
union Data {
    int i;
    float f;
    char c;
};

int main() {
    union Data data;

    // Przechowywanie wartości typu int
    data.i = 42;
    printf("Wartość int: %d\n", data.i);

    // Przechowywanie wartości typu float
    data.f = 3.14;
    printf("Wartość float: %f\n", data.f);

    // Przechowywanie wartości typu char
    data.c = 'A';
    printf("Wartość char: %c\n", data.c);

    return 0;
}