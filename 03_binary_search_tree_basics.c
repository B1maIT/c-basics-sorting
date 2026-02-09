#include <stdio.h>
#include <stdlib.h>

// Definicja struktury dla wezla drzewa BST
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Funkcja do tworzenia nowego wezla
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Funkcja do dodawania wezla
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Funkcja do wyszukiwania wezla
Node* searchNode(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}

// Funkcja do wypisywania wezlow w kolejnosci przechodzenia
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Glowna funkcja programu
int main() {
    Node* root = NULL;
    int data;

    // Dodawanie wezlow
    printf("Wprowadz dane dla wezlow (0 konczy wprowadzanie): ");
    while (1) {
        scanf("%d", &data);
        if (data == 0) break;
        root = insertNode(root, data);
    }

    // Wyszukiwanie wezla
    printf("Wprowadz wartosc wezla do wyszukania: ");
    scanf("%d", &data);
    Node* foundNode = searchNode(root, data);
    if (foundNode != NULL) {
        printf("Wezel znaleziony: %d\n", foundNode->data);
    } else {
        printf("Wezel nie znaleziony.\n");
    }

    // Wypisanie wezlow drzewa
    printf("Wezly drzewa BST w kolejnosci przechodzenia: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}

