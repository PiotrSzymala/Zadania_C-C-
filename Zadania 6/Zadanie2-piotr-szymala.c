#include <stdio.h>

int main() {
    int array[10];
    int *ptr;

    // Inicjalizacja tablicy wartościami od 0 do 9
    for(int i = 0; i < 10; i++) {
        array[i] = i;
    }

    // Wskaźnik wskazuje na pierwszy element tablicy
    ptr = array;

    // Wyświetlanie elementów tablicy za pomocą arytmetyki wskaźników
    for(int i = 0; i < 10; i++) {
        printf("Element %d: %d\n", i, *(ptr + i));
    }

    return 0;
}