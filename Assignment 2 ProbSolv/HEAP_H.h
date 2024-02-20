#ifndef HEAP_H
#define HEAP_H

template<class ItemType>
struct Heap {
    void Insert(ItemType value);
    ItemType Remove();
    void ReheapDown(int root, int bottom);
    void ReheapUp(int root, int bottom);
    void Swap(int index1, int index2);
    ItemType* elements;
    int numElements = 0;
    Heap(ItemType* arr);
};

#endif // !Heap_H