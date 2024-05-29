#include <stdio.h>

// Definicje funkcji
int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int subtract(int a, int b) {
    return a - b;
}

int main() {
    int choice, a, b;
    int (*operation)(int, int);

    // Pytanie użytkownika o wybór operacji
    printf("Wybierz operację:\n");
    printf("1. Dodawanie\n");
    printf("2. Mnożenie\n");
    printf("3. Odejmowanie\n");
    printf("Twój wybór: ");
    scanf("%d", &choice);

    // Pytanie użytkownika o dwie liczby
    printf("Podaj dwie liczby: ");
    scanf("%d %d", &a, &b);

    // Ustawienie wskaźnika do odpowiedniej funkcji
    switch (choice) {
        case 1:
            operation = add;
            break;
        case 2:
            operation = multiply;
            break;
        case 3:
            operation = subtract;
            break;
        default:
            printf("Nieprawidłowy wybór\n");
            return 1;
    }

    // Wywołanie wybranej funkcji za pomocą wskaźnika do funkcji
    printf("Wynik: %d\n", operation(a, b));

    return 0;
}