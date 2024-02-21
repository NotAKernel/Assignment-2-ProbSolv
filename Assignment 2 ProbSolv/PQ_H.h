#pragma once
#include "HEAP_H.h"

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
    void PrintQueue();

private:
    int numItems;                    //length
    Heap<T> items;
    int maxItems;
};
