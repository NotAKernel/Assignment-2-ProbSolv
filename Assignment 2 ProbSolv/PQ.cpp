#include "PQ_H.h"


template<typename T>
PriorityQueue<T>::PriorityQueue(int max)
{
    maxItems = max;
    items.elements = new T[max];
    items.numElements = 0;
    numItems = 0;
}

template<typename T>
PriorityQueue<T>::~PriorityQueue()
{
    delete[] items.elements;
}

template<typename T>
void PriorityQueue<T>::MakeEmpty()
{
    numItems = 0;
}

template<typename T>
bool PriorityQueue<T>::IsEmpty() const
// Post: Function value = true if the queue is   
// 		  empty; false, otherwise
{
    return numItems == 0;
}
template<typename T>
bool PriorityQueue<T>::IsFull() const
// Post: Function value = true if the queue is   
// 		 full; false, otherwise
{
    return numItems == maxItems;
}

template<typename T>
void PriorityQueue<T>::Enqueue(T newItem)
// Post: newItem is in the queue.
{
    numItems++;
    items.elements[numItems - 1] = newItem;
    items.ReheapUp(0, numItems - 1);
}

template<typename T>
void PriorityQueue<T>::Dequeue(T& item)
// Post: element with highest priority has been  
// removed from the queue; a copy is returned in item.
{
    item = items.elements[0];
    items.elements[0] = items.elements[numItems - 1];
    numItems--;
    items.ReheapDown(0, numItems - 1);
}


template<typename T>
void PriorityQueue<T>::ChangePriority(T& oldItem, int index, T newItem)
// Post: a copy of the element at index is      
// returned in item; element at index has been   
// changed and newItem has been added to the queue
{
    oldItem = items.elements[index];
    items.elements[index] = newItem;
    if (newItem < oldItem)
        items.ReheapDown(index, numItems - 1);
    else
        items.ReheapUp(0, index);
}


template<typename T>
void PriorityQueue<T>::RemoveItem(T& item, int index)
// Post: element at index has been removed from  
// the queue; a copy is returned in item.
{
    item = items.elements[index];
    items.elements[index] = items.elements[numItems - 1];
    numItems--;
    if (items.elements[index] < item)
        items.ReheapDown(index, numItems - 1);
    else
        items.ReheapUp(0, index);
}

template<typename T>
int PriorityQueue<T>::GetNumItems()
{
    return numItems;
}

template<typename T>
Heap<T> PriorityQueue<T>::CopyHeap()
{
    return Heap<T>(items);
}
