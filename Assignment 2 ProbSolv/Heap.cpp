#include "HEAP_H.h"

template<class ItemType>
void Heap<ItemType>::Insert(ItemType value)
{
    elements[numElements] = value;
    numElements++;
    if (numElements > 1)
        ReheapUp(0, numElements - 1); 
}

template<class ItemType>
ItemType Heap<ItemType>::Remove()
{
    if (numElements == 0) {
        return 0;
    }

    Swap(0, numElements - 1); 
    numElements--; 
    ReheapDown(0, numElements); 
    return elements[numElements]; 
}

template<class ItemType>
void Heap<ItemType>::ReheapDown(int root, int bottom)
{
    int maxChild;
    int rightChild;
    int leftChild;

    leftChild = (root * 2) + 1;
    rightChild = (root * 2) + 2;

    if (leftChild < bottom) { // Changed <= to <
        if (rightChild < bottom && elements[leftChild] < elements[rightChild])
            maxChild = rightChild;
        else
            maxChild = leftChild;

        if (elements[root] < elements[maxChild]) {
            Swap(root, maxChild);
            ReheapDown(maxChild, bottom);
        }
    }
}

template<class ItemType>
void Heap<ItemType>::ReheapUp(int root, int bottom)
{
    if (bottom > root) {
        int parent = (bottom - 1) / 2;
        if (elements[parent] < elements[bottom]) {
            Swap(parent, bottom);
            ReheapUp(root, parent);
        }
    }
}

template<class ItemType>
void Heap<ItemType>::Swap(int index1, int index2)
{
    ItemType temp = elements[index1];
    elements[index1] = elements[index2];
    elements[index2] = temp;
}

template<class ItemType>
Heap<ItemType>::Heap(ItemType* arr)
{
    this->elements = arr;
}