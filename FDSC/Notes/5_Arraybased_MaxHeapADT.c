/* Another implementation of array based max heap ADT */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#define MAXSIZE 100
#define ElementType int

typedef struct HeapStruct *MaxHeap;
struct HeapStruct {
    ElementType *elements;      // array
    int size;                   // current size
    int capacity;               // max element number
};

MaxHeap Create(int size);
void Insert(MaxHeap heap, ElementType item);
ElementType Delete(MaxHeap heap);
bool IsFull(MaxHeap heap);
bool IsEmpty(MaxHeap heap);

int main(void)
{
    printf("%d", INT_MIN);

    return 0;
}

MaxHeap Create(int size)
{
    /* create a emtpy max heap with capacity of size */
    MaxHeap heap = (MaxHeap)malloc(sizeof(struct HeapStruct));
    heap->elements = (ElementType *)malloc((size+1) * sizeof(ElementType));
    heap->size = 0;
    heap->capacity = size;
    heap->elements[0] = INT_MAX;   // sentinel

    return heap;
}

void Insert(MaxHeap heap, ElementType item)
{
    int i;
    if (IsFull(heap))
    {
        printf("The max heap is full.\n");
        return;
    }
    i = ++(heap->size);
    while (item > heap->elements[i/2]) // because sentinel exists
    {
        heap->elements[i] = heap->elements[i/2];
        i /= 2;
    }
    heap->elements[i] = item;
}

ElementType Delete(MaxHeap heap)
{
    /* delete and return the max element from the heap, which is the root */
    int parent, child;
    ElementType MaxItem, temp;
    if (IsEmpty(heap))
    {
        printf("The heap is empty.\n");
        exit(EXIT_FAILURE);
    }
    MaxItem = heap->elements[1];
    temp = heap->elements[(heap->size)--];
    parent = 1; child = 2;
    while (child <= heap->size)
    {
        if ((child < heap->size) &&
            (heap->elements[child] < heap->elements[child+1]))
            child++;
        if (temp >= heap->elements[child]) break;
        heap->elements[parent] = heap->elements[child];
        parent = child;
        child *= 2;
    }
    heap->elements[parent] = temp;
    return MaxItem;
}

bool IsFull(MaxHeap heap)
{
    return (heap->size >= heap->capacity);
}

bool IsEmpty(MaxHeap heap)
{
    return (heap->size == 0);
}