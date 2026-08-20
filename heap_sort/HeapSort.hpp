
#ifndef HEAPSORT_H
#define HEAPSORT_H

template<class T>
class HeapSort {

    public:
        void sort(T* array,int n);
        HeapSort() = default;
    private:
        void fixDown(T* arr, int i,int n);
        void heapify(T* arr,int n);
        int parent(int i);
        int leftChild(int i);
        int rightChild(int i);
        void swap(T* arr, int i, int j);

};
#include "HeapSort.hpp"


template<class T>
int HeapSort<T>::parent(int i) {
    return (i - 1) / 2;
}

template<class T>
int HeapSort<T>::leftChild(int i) {
    return 2*i+1;
}

template<class T>
int HeapSort<T>::rightChild(int i) {
    return 2*i+2;
}

template<class T>
void HeapSort<T>::swap(T *arr, int i, int j) {
    T temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

template<class T>
void HeapSort<T>::heapify(T* arr,int n) {
    for (int i = n/2 - 1; i >= 0; i--) {
        fixDown(arr, i, n);
    }
}

template<class T>
void HeapSort<T>::fixDown(T *arr,int i ,int n) {
    while (true) {
        int left = leftChild(i);
        int right = rightChild(i);
        int largest = i;

        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }
        if (largest == i) {
            break;
        }
        swap(arr, i, largest);
        i = largest;
    }
}

template<class T>
void HeapSort<T>::sort(T *array, int n) {
    heapify(array, n);
    for (int i = n-1; i >= 0; i--) {
        swap(array, 0, i);
        fixDown(array, 0,i);
    }
}



#endif //HEAPSORT_H
