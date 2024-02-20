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
