#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100


struct Hotel {
    char name[50];
    int floor;
    int capacity;
};


int graph[MAX_VERTICES][MAX_VERTICES];
int vertices;


int queue[MAX_VERTICES];
int front = -1, rear = -1;


bool visited[MAX_VERTICES];


struct Hotel hotels[MAX_VERTICES];


void initGraph(int v);
void addEdge(int start, int end);
void BFS(int start);
void DFS(int start);
void enqueue(int value);
int dequeue();
bool isEmpty();
void inputHotelData();


void initGraph(int v) {
    vertices = v;
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            graph[i][j] = 0;
        }
        visited[i] = false;
    }
}


void addEdge(int start, int end) {
    graph[start][end] = 1;
    graph[end][start] = 1; 
}


void BFS(int start) {
    enqueue(start);
    visited[start] = true;

    while (!isEmpty()) {
        int current = dequeue();
        printf("%s ", hotels[current].name);

        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = true;
            }
        }
    }
}


void DFS(int start) {
    printf("%s ", hotels[start].name);
    visited[start] = true;

    for (int i = 0; i < vertices; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}


void enqueue(int value) {
    if (rear == MAX_VERTICES - 1) {
        printf("Queue is full\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
    }
}

int dequeue() {
    int value;
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return -1;
    } else {
        value = queue[front];
        front++;
        return value;
    }
}

bool isEmpty() {
    return (front == -1 || front > rear);
}

// Function to input hotel data
void inputHotelData() {
    printf("Enter the number of hotels: ");
    scanf("%d", &vertices);

    for (int i = 0; i < vertices; i++) {
        printf("Enter details for Hotel %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", hotels[i].name);
        printf("Number of floors: ");
        scanf("%d", &hotels[i].floor);
        printf("Capacity: ");
        scanf("%d", &hotels[i].capacity);
    }
}

int main() {
    inputHotelData();

    // Build graph based on hotel capacity
    initGraph(vertices);
    for (int i = 0; i < vertices; i++) {
        for (int j = i + 1; j < vertices; j++) {
            if (hotels[i].capacity >= hotels[j].capacity) {
                addEdge(i, j);
            }
        }
    }

    printf("\nBreadth-First Traversal (BFS): ");
    BFS(0);


    for (int i = 0; i < vertices; i++) {
        visited[i] = false;
    }

    printf("\nDepth-First Traversal (DFS): ");
    DFS(0);

    return 0;
}
