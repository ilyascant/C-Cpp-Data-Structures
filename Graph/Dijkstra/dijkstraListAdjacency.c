#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define V 5

typedef struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;

} AdjListNode;

typedef struct AdjList {
    int order;
    int weight;
    bool isVisited;
    struct AdjList* prev;
    struct AdjListNode* head;
} AdjList;

typedef struct Graph {
    int v;
    struct AdjList* arr;

} Graph;

AdjListNode* new_node(int dest, int weight) {
    AdjListNode* node = (AdjListNode*)malloc(sizeof(AdjListNode));
    node->dest = dest;
    node->weight = weight;
    node->next = NULL;
    return node;
}

Graph* new_graph(int v) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->v = v;
    graph->arr = (AdjList*)malloc(v * sizeof(AdjList));

    for (int i = 0; i < v; i++) {
        graph->arr[i].head = NULL;
    }

    return graph;
}

void add_edge(Graph* graph, int src, int dest, int weight) {
    AdjListNode* check = NULL;

    AdjListNode* node = new_node(dest, weight);
    if (graph->arr[src].head == NULL) {
        graph->arr[src].head = node;
    } else {
        check = graph->arr[src].head;
        while (check->next != NULL) {
            check = check->next;
        }
        check->next = node;
    }

    node = new_node(src, weight);
    if (graph->arr[dest].head == NULL) {
        graph->arr[dest].head = node;
    } else {
        check = graph->arr[dest].head;
        while (check->next) {
            check = check->next;
        }
        check->next = node;
    }
}
int find_min_index(AdjList* dist, int v) {
    int min = INT_MAX, min_index;
    for (int i = 0; i < v; i++) {
        if (!dist[i].isVisited && dist[i].weight <= min) {
            min = dist[i].weight;
            min_index = i;
        }
    }
    return min_index;
}

void print_dijkstra(AdjList* dist, int src, int v) {
    int i = 0;
    while (i < v) {
        printf("Shortest Path From Src ( %d ) To Dest ( %d ): ", src, i);
        printf("%d\n", dist[i].weight);
        AdjList* tmp = dist[i].prev;
        printf("PATH: %d ", i);
        while (tmp != NULL) {
            printf("--> %d ", tmp->order);
            tmp = tmp->prev;
        }
        printf("\n");
        i++;
    }
    printf("\n");
}

void printGraph(Graph* graph) {
    int v;
    for (v = 0; v < graph->v; v++) {
        AdjListNode* pCrawl = graph->arr[v].head;
        printf("\nAdjacency list of vertex %d\nhead ", v);
        while (pCrawl) {
            printf("-> %d (%d) ", pCrawl->dest, pCrawl->weight);
            pCrawl = pCrawl->next;
        }
    }
}

void dijkstra(Graph* graph, int src) {
    AdjList* dist = (AdjList*)malloc(graph->v * sizeof(AdjList));

    for (int i = 0; i < graph->v; i++) {
        dist[i] = graph->arr[i];
        dist[i].weight = INT_MAX;
        dist[i].isVisited = false;
        dist[i].prev = NULL;
    }

    dist[src].weight = 0;

    for (int i = 0; i < graph->v - 1; i++) {
        int min_index = find_min_index(dist, graph->v);
        dist[min_index].isVisited = true;
        AdjListNode* tmp = graph->arr[min_index].head;
        while (tmp) {
            if (!dist[tmp->dest].isVisited && dist[min_index].weight != INT_MAX && dist[tmp->dest].weight > dist[min_index].weight + tmp->weight) {
                dist[tmp->dest].weight = dist[min_index].weight + tmp->weight;
                dist[tmp->dest].prev = &dist[min_index];
                dist[min_index].order = min_index;
            }
            tmp = tmp->next;
        }
    }
    print_dijkstra(dist, src, graph->v);
}

int main() {
    clock_t t;
    t = clock();
    printf("\nTIMER STARTS\n");

    // -----------------------------------------------------
    Graph* graph = new_graph(V);
    add_edge(graph, 0, 1, 6);
    add_edge(graph, 0, 3, 1);
    add_edge(graph, 1, 2, 5);
    add_edge(graph, 1, 3, 2);
    add_edge(graph, 1, 4, 2);
    add_edge(graph, 2, 4, 5);
    add_edge(graph, 3, 4, 1);

    printGraph(graph);
    printf("\n\n");
    dijkstra(graph, 0);
    // -----------------------------------------------------

    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("TIMER ENDS \n");
    printf("THE PROGRAM TOOK \"%f\" SECONDS TO EXECUTE", time_taken);

    return 0;
}