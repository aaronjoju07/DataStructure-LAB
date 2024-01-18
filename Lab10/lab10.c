#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge* edges;
};

struct Subset {
    int parent, rank;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootX].parent = rootY;
        subsets[rootY].rank++;
    }
}

int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

void primMST(struct Graph* graph) {
    int parent[MAX];
    int key[MAX];
    int inMST[MAX];

    for (int i = 0; i < graph->V; i++) {
        key[i] = MAX;
        inMST[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < graph->V - 1; count++) {
        int u = -1;
        for (int v = 0; v < graph->V; v++) {
            if (!inMST[v] && (u == -1 || key[v] < key[u]))
                u = v;
        }

        inMST[u] = 1;

        for (int v = 0; v < graph->V; v++) {
            if (graph->edges[u * graph->V + v].weight != 0 &&
                !inMST[v] && graph->edges[u * graph->V + v].weight < key[v]) {
                key[v] = graph->edges[u * graph->V + v].weight;
                parent[v] = u;
            }
        }
    }

    printf("Prim's MST edges:\n");
    for (int i = 1; i < graph->V; i++) {
        printf("(%d, %d) - %d\n", parent[i], i, key[i]);
    }
}

void kruskalMST(struct Graph* graph) {
    struct Edge result[MAX];
    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compareEdges);

    struct Subset subsets[MAX];
    for (int v = 0; v < graph->V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int e = 0, i = 0;
    while (e < graph->V - 1 && i < graph->E) {
        struct Edge nextEdge = graph->edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            Union(subsets, x, y);
        }
    }

    printf("\nKruskal's MST edges:\n");
    for (int i = 0; i < e; i++) {
        printf("(%d, %d) - %d\n", result[i].src, result[i].dest, result[i].weight);
    }
}

int main() {
    int V, E;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    struct Graph* graph = createGraph(V, E);

    printf("Enter the edges (source, destination, weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &graph->edges[i].src, &graph->edges[i].dest, &graph->edges[i].weight);
    }

    primMST(graph);
    kruskalMST(graph);

    return 0;
}
