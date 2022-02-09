#include <stdio.h>
#include <stdlib.h>

#define V 5

typedef struct Node {
    int des;
    struct Node* next;
} Node;

typedef struct NodeHead {
    struct Node* head;
} NodeHead;

typedef struct Graph {
    struct NodeHead* array;
} Graph;

struct Node* createNode(int des) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->des = des;
    newNode->next = NULL;

    return newNode;
};

struct Graph* createGraph(int v) {
    Graph* newGraph = (Graph*)malloc(sizeof(Graph));
    newGraph->array = (NodeHead*)malloc(v * sizeof(NodeHead));

    for (int i = 0; i < v; i++) {
        newGraph->array[i].head = NULL;
    }

    return newGraph;
}

void addEdge(Graph* graph, int src, int des) {
    Node* check = NULL;
    Node* newNode = createNode(des);

    if (graph->array[src].head == NULL) {
        graph->array[src].head = newNode;

    } else {
        check = graph->array[src].head;
        while (check->next != NULL) {
            check = check->next;
        }
        check->next = newNode;
    }

    newNode = createNode(src);
    if (graph->array[des].head == NULL) {
        graph->array[des].head = newNode;

    } else {
        check = graph->array[des].head;
        while (check->next != NULL) {
            check = check->next;
        }
        check->next = newNode;
    }
}

void printGraph(Graph* graph) {
    for (int i = 0; i < V; i++) {
        Node* start = graph->array[i].head;
        printf("\n%d: ", i);
        while (start) {
            printf("%d-> ", start->des);
            start = start->next;
        }
    }
    printf("\n\n");
}

int main() {
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