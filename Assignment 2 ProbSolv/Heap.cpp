#include "HEAP_H.h"

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
	int rightChild = root * 2 + 2;
	int leftChild = root * 2 + 1;

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
