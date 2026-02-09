#include <stdio.h>
#include <stdlib.h>

// Definicja struktury stosu
struct Stack {
    int data;
    struct Stack* next;
};

// Inicjalizacja pustego stosu
struct Stack* top = NULL;

// Dodawanie elementu na wierzcholek stosu
void push(int value) {
    struct Stack* newNode = (struct Stack*)malloc(sizeof(struct Stack));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Usuwanie elementu ze szczytu stosu
void pop() {
    if (top == NULL) {
        printf("Stos jest pusty.\n");
        return;
    }
    struct Stack* temp = top;
    top = top->next;
    free(temp);
}

// Odczytanie elementu ze szczytu stosu
int getTop() {
    if (top == NULL) {
        printf("Stos jest pusty.\n");
        return -1; // Wartosc oznaczajaca blad
    }
    return top->data;
}

// Sprawdzenie, czy stos jest pusty
int isEmpty() {
    return (top == NULL);
}

// Wyczyszczenie stosu
void clear() {
    while (top != NULL) {
        pop();
    }
}

// Wyswietlenie zawartosci stosu
void displayStack() {
    struct Stack* current = top;
    printf("Zawartosc stosu:\n");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);

    printf("Top: %d\n", getTop());
    displayStack();

    pop();
    printf("Top po usunieciu: %d\n", getTop());
    displayStack();

    clear();
    printf("Czy stos jest pusty? %s\n", isEmpty() ? "Tak" : "Nie");

    return 0;
}
