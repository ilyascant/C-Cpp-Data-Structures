#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define V 5

typedef struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;
} AdjListNode;

typedef struct AdjList {
    int weight;
    bool isVisited;
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

int find_min_index(AdjList* dist) {
    int min = INT_MAX, min_index;

    for (int i = 0; i < V; i++) {
        if (!dist[i].isVisited && dist[i].weight <= min) {
            min = dist[i].weight;
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(Graph* graph, int src) {
    AdjList* dist = (AdjList*)malloc(V * sizeof(AdjList));
    for (int i = 0; i < V; i++) {
        dist[i] = graph->array[i];
        dist[i].weight = INT_MAX;
        dist[i].isVisited = false;
    }
    dist[src].weight = 0;

    for (int i = 0; i < V - 1; i++) {
        int min_index = find_min_index(dist);
        AdjListNode* tmp = dist[min_index].head;
        dist[min_index].isVisited = true;
        for (int j = 0; j < V; j++) {
            if (tmp) {
                if (j == tmp->dest && !dist[j].isVisited && dist[min_index].weight != INT_MAX && dist[j].weight > dist[min_index].weight + tmp->weight) {
                    dist[j].weight = dist[min_index].weight + tmp->weight;
                }
                if (j == tmp->dest) tmp = tmp->next;

            } else {
                continue;
            }
        }
    }
    for (int i = 0; i < V; i++) {
        printf("From Note ( %d ) to Note ( %d ), Shortest Path's Weight is-> %d\n", src, i, dist[i].weight);
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
    addEdge(graph, 0, 1, 6);
    addEdge(graph, 0, 3, 1);
    addEdge(graph, 1, 2, 5);
    addEdge(graph, 1, 3, 2);
    addEdge(graph, 1, 4, 2);
    addEdge(graph, 2, 4, 5);
    addEdge(graph, 3, 4, 1);

    // printGraph(graph);
    dijkstra(graph, 0);

    return 0;
}
