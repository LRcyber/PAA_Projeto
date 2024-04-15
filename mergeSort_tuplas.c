#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar a tupla (caractere, contador)
struct Tuple {
    char value;
    int count;
};

// Função mesclar duas metades ordenadas do array
void merge(struct Tuple arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Arrays temporários para armazenar as metades esquerda e direita
    struct Tuple L[n1], R[n2];

    // Transferindo dados para os arrays temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Mesclando arrays temporários de volta para arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        // Comparando os elementos de L[] e R[], e mesclando de forma ordenada
        if (L[i].value <= R[j].value) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiando os elementos restantes de L[], se houver algum
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiando os elementos restantes de R[], se houver algum
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função de ordenação por mergesort
void mergeSort(struct Tuple arr[], int l, int r) {
    if (l < r) {
        // Encontrando o ponto médio do array
        int m = l + (r - l) / 2;

        // Chamanda recursivamente mergeSort para as metades esquerda e direita
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Mesclando as duas metades ordenadas
        merge(arr, l, m, r);
    }
}

// Função para imprimir as tuplas e os contadores atualizados
void printTuples(struct Tuple arr[], int size) {
    printf("Tuplas e contadores atualizados:\n");
    for (int i = 0; i < size; i++) {
        printf("(%c, %d)\n", arr[i].value, arr[i].count);
    }
}

int main() {
    // Vetor de caracteres de entrada
    char vetor[] = "Luciana";

    // Tamanho do vetor
    int size = strlen(vetor);

    // Inicializando uma matriz de estruturas Tuple
    struct Tuple tuples[size];
    int index = 0;

    // Contando a ocorrência de cada caractere
    for (int i = 0; i < size; i++) {
        int found = 0;
        // Verificando se o caractere já está na lista de tuplas
        for (int j = 0; j < index; j++) {
            if (tuples[j].value == vetor[i]) {
                tuples[j].count++;
                found = 1;
                break;
            }
        }
        // Se não estiver, adiciona uma nova tupla
        if (!found) {
            tuples[index].value = vetor[i];
            tuples[index].count = 1;
            index++;
        }
    }

    // Ordenando as tuplas pelo valor
    mergeSort(tuples, 0, index - 1);

    // Imprimindo as tuplas e os contadores atualizados
    printTuples(tuples, index);

    return 0;
}
