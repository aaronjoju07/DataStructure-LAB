#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int priority;
} Element;

typedef struct {
    Element heap[MAX_SIZE];
    int size;
} PriorityQueue;


void initializePriorityQueue(PriorityQueue *pq) {
    pq->size = 0;
}


void swap(Element *a, Element *b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}


void heapifyUp(PriorityQueue *pq, int index) {
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (pq->heap[index].priority < pq->heap[parentIndex].priority) {
            swap(&pq->heap[index], &pq->heap[parentIndex]);
            index = parentIndex;
        } else {
            break;
        }
    }
}


void insert(PriorityQueue *pq, int data, int priority) {
    if (pq->size < MAX_SIZE) {
        Element newElement = {data, priority};
        pq->heap[pq->size] = newElement;
        pq->size++;
        heapifyUp(pq, pq->size - 1);
    } else {
        printf("Priority queue is full.\n");
    }
}


void heapifyDown(PriorityQueue *pq, int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;

    if (leftChild < pq->size && pq->heap[leftChild].priority < pq->heap[smallest].priority) {
        smallest = leftChild;
    }

    if (rightChild < pq->size && pq->heap[rightChild].priority < pq->heap[smallest].priority) {
        smallest = rightChild;
    }

    if (smallest != index) {
        swap(&pq->heap[index], &pq->heap[smallest]);
        heapifyDown(pq, smallest);
    }
}


Element extractMin(PriorityQueue *pq) {
    if (pq->size > 0) {
        Element minElement = pq->heap[0];
        pq->size--;
        pq->heap[0] = pq->heap[pq->size];
        heapifyDown(pq, 0);
        return minElement;
    } else {
        printf("Priority queue is empty.\n");
        exit(1);
    }
}

int main() {
    PriorityQueue pq;
    initializePriorityQueue(&pq);


    insert(&pq, 5, 2);
    insert(&pq, 10, 1);
    insert(&pq, 3, 5);


    Element minElement = extractMin(&pq);
    printf("Extracted: %d (Priority: %d)\n", minElement.data, minElement.priority);

    minElement = extractMin(&pq);
    printf("Extracted: %d (Priority: %d)\n", minElement.data, minElement.priority);

    minElement = extractMin(&pq);
    printf("Extracted: %d (Priority: %d)\n", minElement.data, minElement.priority);

    return 0;
}
