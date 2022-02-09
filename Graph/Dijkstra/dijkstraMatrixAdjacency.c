#include <limits.h>  // For INT_MAX
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define V 5

int pick_min_index(int dist[V], bool isVisited[V]) {
    int min = INT_MAX, min_index;

    for (int i = 0; i < V; i++) {
        if (isVisited[i] == false && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool isVisited[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, isVisited[i] = false;

    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        int min_index = pick_min_index(dist, isVisited);
        isVisited[min_index] = true;

        for (int j = 0; j < V; j++) {
            if (!isVisited[j] && dist[min_index] != INT_MAX && graph[min_index][j] && dist[j] > dist[min_index] + graph[min_index][j]) {
                dist[j] = dist[min_index] + graph[min_index][j];
            }
        }
    }

    for (int i = 0; i < V; i++) {
        printf("%d\n", dist[i]);
    }
}

int main(void) {
    clock_t t;
    t = clock();
    printf("TIMER STARTS\n");

    int graph[V][V] = {{0, 6, 0, 1, 0},
                       {6, 0, 5, 2, 2},
                       {0, 5, 0, 0, 5},
                       {1, 2, 0, 0, 1},
                       {0, 2, 5, 1, 0}};
    dijkstra(graph, 0);
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("TIMER ENDS \n");
    printf("THE PROGRAM TOOK %f SECONDS TO EXECUTE", time_taken);
    return 0;
}