#include <stdio.h>
#include <stdlib.h>

// Definicja struktury węzła listy
struct Node {
    int data;
    struct Node* next;
};

// Funkcja do dodawania elementu na określonym indeksie
void addAtIndex(struct Node** head, int index, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;

    if (index == 0) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    struct Node* temp = *head;
    for (int i = 0; temp != NULL && i < index - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) return;

    new_node->next = temp->next;
    temp->next = new_node;
}

// Funkcja do wyświetlania listy
void displayList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Przykładowe użycie funkcji
int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    
    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));
    
    head->data = 10;
    head->next = second;
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = NULL;
    
    displayList(head);
    addAtIndex(&head, 1, 15);
    displayList(head);
    
    return 0;
}