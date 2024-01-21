#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_HOTELS 3
struct Edge {
    int src, dest, distance;
};

struct Graph {
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;

    graph->edge = (struct Edge*)malloc(graph->E * sizeof(struct Edge));

    return graph;
}

int minDistance(int distance[], int mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < MAX_HOTELS; v++) {
        if (mstSet[v] == 0 && distance[v] < min) {
            min = distance[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST(int parent[], int graph[MAX_HOTELS][MAX_HOTELS]) {
    printf("Minimum Spanning Tree:\n");
    printf("Hotel \tDistance\n");
    for (int i = 1; i < MAX_HOTELS; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[MAX_HOTELS][MAX_HOTELS]) {
    int parent[MAX_HOTELS];
    int distance[MAX_HOTELS];
    int mstSet[MAX_HOTELS];

    for (int i = 0; i < MAX_HOTELS; i++) {
        distance[i] = INT_MAX;
        mstSet[i] = 0;
    }

    distance[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < MAX_HOTELS - 1; count++) {
        int u = minDistance(distance, mstSet);

        mstSet[u] = 1;

        for (int v = 0; v < MAX_HOTELS; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < distance[v]) {
                parent[v] = u;
                distance[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int myComp(const void* a, const void* b) {
    return ((struct Edge*)a)->distance - ((struct Edge*)b)->distance;
}

int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void Union(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

void kruskalMST(struct Graph* graph) {
    int* parent = (int*)malloc(MAX_HOTELS * sizeof(int));
    for (int i = 0; i < MAX_HOTELS; i++)
        parent[i] = -1;

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

    printf("Minimum Spanning Tree:\n");
    for (int i = 0; i < graph->E; i++) {
        int x = find(parent, graph->edge[i].src);
        int y = find(parent, graph->edge[i].dest);

        if (x != y) {
            printf("%d - %d \t%d \n", graph->edge[i].src, graph->edge[i].dest, graph->edge[i].distance);
            Union(parent, x, y);
        }
    }
}

int main() {
    int hotelDistances[MAX_HOTELS][MAX_HOTELS];
    int choice;

    printf("Enter the distances between hotels (0 for no connection):\n");
    for (int i = 0; i < MAX_HOTELS; i++) {
        // printf("Hotel");
        for (int j = 0; j < MAX_HOTELS; j++) {
            scanf("%d", &hotelDistances[i][j]);
        }
    }

    struct Graph* userGraph = createGraph(MAX_HOTELS, MAX_HOTELS * (MAX_HOTELS - 1) / 2);

    int k = 0;
    for (int i = 0; i < MAX_HOTELS; i++) {
        for (int j = i + 1; j < MAX_HOTELS; j++) {
            userGraph->edge[k].src = i;
            userGraph->edge[k].dest = j;
            userGraph->edge[k].distance = hotelDistances[i][j];
            k++;
        }
    }

    printf("Choose the MST algorithm:\n");
    printf("1. Prim's Algorithm\n");
    printf("2. Kruskal's Algorithm\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            primMST(hotelDistances);
            break;
        case 2:
            kruskalMST(userGraph);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}
