// Name: Noah Borden
// -----------------------------------------------
// Assignment: Homework 2 - Due: 3/31/2025

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return;
}

void heapify(int arr[], int S, int i) {
    int largest = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    if ((left < S) && (arr[left] > arr[largest])) {
        largest = left;
    }
    if ((right < S) && (arr[right] > arr[largest])) {
        largest = right;
    }
    if (largest != i) {
        swap(arr, i, largest);
        heapify(arr, S, largest);
    }
    return;
}

void heapSort(int arr[], int S) {
    for (int i = (S / 2) - 1; i >= 0; i--) {
        heapify(arr, S, i);
    }
    for (int i = S - 1; i >= 0; i--) {
        swap(arr, 0, i);
        heapify(arr, i, 0);
    }
    return;
}

void print(int arr[], int S) {
    for (int i = 0; i < S; i++) {
        cout << arr[i] << " ";
    }
    return;
}

int main() {
    srand(time(0));

    const int SIZE = 10;
    int array[SIZE];
    for (int i = 0; i < SIZE; i++) array[i] = rand() % 100;

    cout << endl << "Shuffled array:   ";
    print(array, SIZE);

    cout << endl << endl << "Sorting with heap sort...";
    heapSort(array, SIZE);

    cout << endl << endl << "Sorted array:     ";
    print(array, SIZE);

    cout << endl << endl;

    return 0;
}