#include <stdio.h>
#include <stdlib.h>

#define V 5

typedef struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;
} AdjListNode;

typedef struct AdjList {
    struct AdjListNode* head;
} AdjList;

typedef struct Graph {
    int v;
    struct AdjList* array;
} Graph;

struct AdjListNode* newAdjListNode(int dest, int weight) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));

    newNode->dest = dest;
    newNode->weight = weight;
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

void addEdge(Graph* graph, int src, int dest, int weight) {
    AdjListNode* check = NULL;
    AdjListNode* newNode = newAdjListNode(dest, weight);

    if (graph->array[src].head == NULL) {
        graph->array[src].head = newNode;

    } else {
        check = graph->array[src].head;
        while (check->next != NULL) {
            check = check->next;
        }
        check->next = newNode;
    }

    newNode = newAdjListNode(src, weight);
    if (graph->array[dest].head == NULL) {
        graph->array[dest].head = newNode;

    } else {
        check = graph->array[dest].head;
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
            printf("-> %d (%d) ", pCrawl->dest, pCrawl->weight);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph(V);  // V is defined as 5
    addEdge(graph, 0, 1, 69);
    addEdge(graph, 0, 4, 21);
    addEdge(graph, 1, 2, 64);
    addEdge(graph, 1, 3, 49);
    addEdge(graph, 1, 4, 102);
    addEdge(graph, 2, 3, 84);
    addEdge(graph, 3, 4, 12);

    printGraph(graph);

    return 0;
}