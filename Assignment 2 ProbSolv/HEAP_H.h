#pragma once
#include <algorithm>
#include <iostream>

template<typename T>
struct Heap {
	void ReheapDown(int root, int bottom);
	void ReheapUp(int root, int bottom);
	T* elements;// Array to be allocated dynamically
	int numElements;
	Heap() = default;
	Heap(const Heap& other) {
		this->numElements = other.numElements; // copy the numElements
		this->elements = new T[numElements]; // create a new array for our copy
		for (int i = 0; i < numElements; ++i) {
			this->elements[i] = other.elements[i]; // copy each element from the original array into our new one
		}
	}
};



// Implementations:
//======================================================================================

template<typename T>
void Heap<T>::ReheapUp(int root, int bottom) {
	int parent;
	if (bottom > root) {
		parent = (bottom - 1) / 2;
		if (elements[parent] < elements[bottom]) {
			std::swap(elements[parent], elements[bottom]);
			ReheapUp(root, parent);
		}
	}
}

template<typename T>
void Heap<T>::ReheapDown(int root, int bottom) {
	int maxChild;
	int rightChild;
	int leftChild;
	leftChild = root * 2 + 1;
	rightChild = root * 2 + 2;
	if (leftChild <= bottom) {
		if (leftChild == bottom) maxChild = leftChild;
		else {
			if (elements[leftChild] <= elements[rightChild]) maxChild = rightChild;
			else maxChild = leftChild;
		}
		if (elements[root] < elements[maxChild]) {
			std::swap(elements[root], elements[maxChild]);
			ReheapDown(maxChild, bottom);
		}
	}
}
