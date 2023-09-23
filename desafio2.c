#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct Node* proximo;
} No;

void inserirOrdenado(No** lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;

    if (*lista == NULL || valor < (*lista)->valor) {
        novo->proximo = *lista;
        *lista = novo;
    } else {
        No* atual = *lista;
        while (atual->proximo != NULL && valor > atual->proximo->valor) {
            atual = atual->proximo;
        }
        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }
}

void imprimirLista(No* lista) {
    while (lista != NULL) {
        printf("%d ", lista->valor);
        lista = lista->proximo;
    }
    printf("\n");
}

int main() {
    No* lista = NULL;

    inserirOrdenado(&lista, 3);
    inserirOrdenado(&lista, 1);
    inserirOrdenado(&lista, 5);
    inserirOrdenado(&lista, 2);
    inserirOrdenado(&lista, 4);

    imprimirLista(lista);

    return 0;
}