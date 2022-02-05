#include <stdio.h>

#define V 4

void init(char arr[][V]) {
    for (char i = 0; i < V; i++) {
        for (char j = 0; j < V; j++) {
            arr[i][j] = 0;
        }
    }
}

void addEdges(char arr[][V], char i, char j, int weight) {
    arr[i][j] = weight;
    arr[j][i] = weight;
}

void printAdjMatrix(char arr[][V]) {
    for (char i = 0; i < V; i++) {
        printf("%d: ", i);
        for (char j = 0; j < V; j++) {
            printf("%5d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char adjMatrix[V][V];
    init(adjMatrix);
    addEdges(adjMatrix, 0, 1, 25);
    addEdges(adjMatrix, 0, 2, 40);
    addEdges(adjMatrix, 1, 2, 86);
    addEdges(adjMatrix, 2, 0, 90);
    addEdges(adjMatrix, 2, 3, 120);

    printAdjMatrix(adjMatrix);

    return 0;
}
