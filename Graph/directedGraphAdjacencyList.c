#include <stdio.h>
#include <stdlib.h>

#define V 5

typedef struct AdjListNode {
    int dest;
    struct AdjListNode* next;
} AdjListNode;

typedef struct AdjList {
    struct AdjListNode* head;
} AdjList;

typedef struct Graph {
    int v;
    struct AdjList* array;
} Graph;

struct AdjListNode* newAdjListNode(int dest) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));

    newNode->dest = dest;
    newNode->next = NULL;

    return newNode;
}

struct Graph* createGraph(int v) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));

    graph->v = v;

    graph->array = (AdjList*)malloc(v * sizeof(AdjList));

    int i;

    for (i = 0; i < v; i++) {
        graph->array[i].head = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    AdjListNode* check = NULL;
    AdjListNode* newNode = newAdjListNode(dest);

    if (graph->array[src].head == NULL) {
        graph->array[src].head = newNode;

    } else {
        check = graph->array[src].head;
        while (check->next != NULL) {
            check = check->next;
        }
        check->next = newNode;
    }
}

void printGraph(Graph* graph) {
    int v;
    for (v = 0; v < graph->v; v++) {
        AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph(V);  // V is defined as 5
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);
    addEdge(graph, 3, 0);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 2);

    printGraph(graph);

    return 0;
}