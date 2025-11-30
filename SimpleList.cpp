#include "SimpleList.h"


template <class T>
SimpleList<T>::SimpleList() {
    numElements = 0; 
    elements = new T[CAPACITY]; 
}

template <class T>
SimpleList<T>::~SimpleList() {
    delete[] elements; 
}

template <class T>
T SimpleList<T>::at(int index) const {
    if(index > numElements - 1 || index < 0) {
        throw InvalidIndexException(); 
    }
    return elements[index]; 
}

template <class T>
bool SimpleList<T>::empty() const {
    if(numElements == 0) {
        return true; 
    } else {
        return false; 
    }
}

template <class T>
T SimpleList<T>::first() const {
    if(numElements == 0) {
        throw EmptyListException(); 
    }
    return elements[0]; 
}

template <class T>
T SimpleList<T>::last() const {
    if(numElements == 0) {
        throw EmptyListException(); 
    }
    return elements[numElements-1]; 
}

template <class T>
void SimpleList<T>::insert(T item) {
    if(numElements == CAPACITY) {
        throw FullListException(); 
    }
    elements[numElements] = item; 
    numElements++; 
}

template <class T>
void SimpleList<T>::remove(int index) {
    if(index > numElements || index < 0) {
        throw InvalidIndexException(); 
    }
    if(numElements == 0) {
        throw EmptyListException();
    }
    while(index + 1 < numElements) {
        elements[index] = elements[index + 1]; 
        index++; 
    }
    numElements--;
}

template <class T>
int SimpleList<T>::getNumElements() const {
    return numElements; 
}

