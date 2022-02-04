#include <stdio.h>
#include <stdlib.h>

typedef struct AdjListNode {
    int dest;
    struct AdjListNode* next;
} AdjListNode;

typedef struct AdjList {
    struct AdjListNode* head;
} AdjList;

typedef struct Graph {
    int V;
    struct AdjList* array;
} Graph;

struct AdjListNode* newAdjListNode(int dest) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));

    newNode->dest = dest;
    newNode->next = NULL;

    return newNode;
}

struct Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));

    graph->V = V;

    graph->array = (AdjList*)malloc(V * sizeof(AdjList));

    int i;

    for (i = 0; i < V; i++) {
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

    newNode = newAdjListNode(src);
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
    for (v = 0; v < graph->V; v++) {
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
    int V = 5;
    Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    return 0;
}
