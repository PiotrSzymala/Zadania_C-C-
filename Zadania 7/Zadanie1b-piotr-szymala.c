#include <stdio.h>
#include <ctype.h>
#include <string.h>

int word_to_digit(const char *word) {
    if (strcmp(word, "zero") == 0) return 0;
    if (strcmp(word, "one") == 0) return 1;
    if (strcmp(word, "two") == 0) return 2;
    if (strcmp(word, "three") == 0) return 3;
    if (strcmp(word, "four") == 0) return 4;
    if (strcmp(word, "five") == 0) return 5;
    if (strcmp(word, "six") == 0) return 6;
    if (strcmp(word, "seven") == 0) return 7;
    if (strcmp(word, "eight") == 0) return 8;
    if (strcmp(word, "nine") == 0) return 9;
    return -1; // W przypadku niepasujących słów
}

void replace_word_with_digit(char *line, const char *word, char digit_char) {
    char *pos = strstr(line, word);
    while (pos) {
        *pos = digit_char;
        int len = strlen(word);
        memmove(pos + 1, pos + len, strlen(pos + len) + 1);
        pos = strstr(line, word);
    }
}

void preprocess_line(char *line) {
    replace_word_with_digit(line, "zero", '0');
    replace_word_with_digit(line, "one", '1');
    replace_word_with_digit(line, "two", '2');
    replace_word_with_digit(line, "three", '3');
    replace_word_with_digit(line, "four", '4');
    replace_word_with_digit(line, "five", '5');
    replace_word_with_digit(line, "six", '6');
    replace_word_with_digit(line, "seven", '7');
    replace_word_with_digit(line, "eight", '8');
    replace_word_with_digit(line, "nine", '9');
}

int extract_energy_value(const char *line) {
    int first_digit = -1;
    int last_digit = -1;

    // Przeszukaj linijkę, aby znaleźć pierwszą i ostatnią cyfrę
    for (int i = 0; line[i] != '\0'; i++) {
        if (isdigit(line[i])) {
            if (first_digit == -1) {
                first_digit = line[i] - '0';
            }
            last_digit = line[i] - '0';
        }
    }

    if (first_digit != -1 && last_digit != -1) {
        return first_digit * 10 + last_digit;
    } else {
        return 0; // Jeśli nie znaleziono żadnych cyfr
    }
}

int main() {
    const char *raw_lines[] = {
        "threerznlrhtkjp23mtflmbrzq395three",
        "9sevenvlttm",
        "3twochzbv",
        "mdxdlh5six5nqfld9bqzxdqxfour",
        "422268",
        "vdctljvnj2jpgdfnbpfjv1",
        "tshl7foureightvzvzdcgt",
        "1fourrj",
        "6mfbqtzbprqfive",
        "4sevens34",
        "fourfourpsckl47xdbncvndrthree",
        "7ltsp1seventhreesix",
        "8sixnmm85",
        "11three",
        "fourvninelccgtkjzhhdqjmnxjbbkdsnine6two",
        "three8seven",
        "oneonefour7193eight",
        "8jmqfhmzf7",
        "5nine8",
        "eight1qlfzvdtseven1threefour",
        "5slbnsevenmz"
    };
    int num_lines = sizeof(raw_lines) / sizeof(raw_lines[0]);
    char lines[num_lines][100];
    int total_energy = 0;

    // Skopiuj linie do modyfikowalnej tablicy
    for (int i = 0; i < num_lines; i++) {
        strcpy(lines[i], raw_lines[i]);
    }

    // Przetwarzanie każdej linii, zamieniając słowa na cyfry
    for (int i = 0; i < num_lines; i++) {
        preprocess_line(lines[i]);
    }

    // Oblicz sumę wartości energetycznych
    for (int i = 0; i < num_lines; i++) {
        total_energy += extract_energy_value(lines[i]);
    }

    printf("Suma wartości energetycznych: %d\n", total_energy);
    return 0;
}