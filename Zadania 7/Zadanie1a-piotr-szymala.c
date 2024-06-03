#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// Funkcja do odczytu pierwszej cyfry w stringu
int get_first_digit(const char *str) {
    while (*str) {
        if (isdigit(*str)) {
            return *str - '0';
        }
        str++;
    }
    return -1; // Zwraca -1 jeśli nie znaleziono cyfry
}

// Funkcja do odczytu ostatniej cyfry w stringu
int get_last_digit(const char *str) {
    const char *last_digit = NULL;
    while (*str) {
        if (isdigit(*str)) {
            last_digit = str;
        }
        str++;
    }
    return last_digit ? *last_digit - '0' : -1;
}

int main() {
    char *lines[] = {
        "1abc2",
        "pqr3stu8vwx",
        "a1b2c3d4e5f",
        "portal7magic",
    };

    int num_lines = sizeof(lines) / sizeof(lines[0]);
    int total_sum = 0;

    for (int i = 0; i < num_lines; i++) {
        int first_digit = get_first_digit(lines[i]);
        int last_digit = get_last_digit(lines[i]);

        if (first_digit != -1 && last_digit != -1) {
            int energy_value = first_digit * 10 + last_digit;
            total_sum += energy_value;
        } else {
            printf("Linia %d nie zawiera wystarczającej liczby cyfr.\n", i + 1);
        }
    }

    printf("Suma wszystkich wartości energetycznych: %d\n", total_sum);
    return 0;
}