#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktura przechowująca informacje o jednym zestawie kostek
typedef struct {
    int red;
    int green;
    int blue;
} DiceSet;

// Funkcja sprawdzająca, czy gra jest możliwa z zadanymi limitami
int isGamePossible(DiceSet *sets, int numSets, int maxRed, int maxGreen, int maxBlue) {
    for (int i = 0; i < numSets; i++) {
        if (sets[i].red > maxRed || sets[i].green > maxGreen || sets[i].blue > maxBlue) {
            return 0;
        }
    }
    return 1;
}

int main() {
    // Limity kostek
    int maxRed = 12;
    int maxGreen = 13;
    int maxBlue = 14;
    
    // Przykładowe dane wejściowe
    // Każda gra jest tablicą struktur DiceSet, reprezentującą każdy rzut
    DiceSet games[10][6] = {
        {{1, 1, 1}, {8, 1, 7}, {10, 0, 6}, {4, 2, 9}, {0, 1, 3}, {4, 1, 10}}, // Gra 1
        {{9, 7, 3}, {5, 15, 2}, {10, 13, 3}}, // Gra 2
        {{3, 4, 1}, {6, 3, 2}, {6, 1, 16}}, // Gra 3
        {{19, 2, 2}, {11, 16, 3}, {20, 16, 18}, {18, 16, 12}, {16, 8, 16}}, // Gra 4
        {{1, 8, 12}, {6, 10, 13}, {1, 6, 3}, {2, 7, 14}}, // Gra 5
        {{1, 0, 0}, {0, 0, 1}, {0, 2, 1}, {1, 0, 3}, {1, 2, 2}, {1, 1, 7}}, // Gra 6
        {{2, 1, 5}, {1, 5, 1}, {3, 0, 7}, {1, 4, 8}}, // Gra 7
        {{0, 6, 4}, {0, 10, 7}, {0, 0, 5}, {1, 0, 7}, {1, 11, 0}}, // Gra 8
        {{0, 2, 2}, {8, 6, 5}, {8, 11, 6}, {8, 3, 4}, {10, 2, 5}}, // Gra 9
        {{2, 8, 2}, {2, 3, 10}, {2, 1, 12}, {2, 9, 0}, {2, 3, 5}}  // Gra 10
    };
    int numSets[10] = {6, 3, 3, 5, 4, 6, 4, 5, 5, 5}; // Liczba rzutów w każdej grze
    
    // Sprawdzenie każdej gry
    int possibleGamesSum = 0;
    for (int i = 0; i < 10; i++) {
        if (isGamePossible(games[i], numSets[i], maxRed, maxGreen, maxBlue)) {
            possibleGamesSum += (i + 1);
            printf("Gra %d jest możliwa.\n", i + 1);
        } else {
            printf("Gra %d nie jest możliwa.\n", i + 1);
        }
    }
    
    printf("Suma identyfikatorów możliwych gier: %d\n", possibleGamesSum);
    
    return 0;
}