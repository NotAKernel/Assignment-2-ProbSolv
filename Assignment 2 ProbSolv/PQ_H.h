#pragma once
#include "Heap.h"

template<typename T>
class PriorityQueue {
public:
    PriorityQueue(int);     // parameterized class constructor
    ~PriorityQueue();			// class destructor
    void MakeEmpty();
    // Function: Initializes the queue to an empty
    // state.
    // Post: Queue is empty.
    bool IsEmpty() const;
    // Function: Determines whether the queue is
    // empty.
    // Post: Function value = (queue is empty)
    bool IsFull() const;
    // Function: Determines whether the queue is
    // full.
    // Post: Function value = (queue is full)
    void Enqueue(T newItem);
    // Function: Adds newItem to the rear of the
    // queue.
    // Pre:  Queue is not full.
    // Post: newItem is in the queue.
    void Dequeue(T& item);
    // Function: Removes element with highest
    // priority from the queue
    // and returns it in item.
    // Pre:  Queue is not empty.
    // Post: Highest priority element has been 
    //       removed from the queue.
    //       item is a copy of the removed element

    void ChangePriority(T& oldItem, int index, T newItem);
    void RemoveItem(T& item, int index);

private:
    int numItems;                    //length
    Heap<T> items;
    int maxItems;
};



// Implementations:
//======================================================================================

template<typename T>
PriorityQueue<T>::PriorityQueue(int max)
{
    maxItems = max;
    items.elements = new T[max];
    items.numElements = max;
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