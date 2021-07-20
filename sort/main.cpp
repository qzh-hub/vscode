#include <iostream>
#include "SortTestHelper.h"
#include "insertionSort.h"
#include "selectionSort.h"
#include "mergeSort.h"
#include "quickSort2.h"
#include "quickSort.h"
#include "heapSort.h"
#include "heapSort2.h"

using namespace std;

template<typename T>
void printArray(T arr[], int n){
    for(int i = 0; i < n; i ++)
        cout << arr[i] << " ";
    cout << endl;
}

int* copyIntArray(int a[], int n){
    int* arr = new int[n];
    copy(a, a+n, arr);
    return arr;
}

int  main(){
    int n = 200000;
    int* arr = SortTestHelper::generateRandomArray(n, 0, n);
    int* arr1 = copyIntArray(arr, n);
    int* arr2 = copyIntArray(arr, n);
    
    //int* arr = SortTestHelper::generateNearlyOrderedArray(n, 100);
    //int* arr2 = copyIntArray(arr, n);
    //selectionSort(arr, n);
    //printArray(arr, n);
    //SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
    //SortTestHelper::testSort("Quick Sort2", quickSort2, arr, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr1, n);
    SortTestHelper::testSort("Heap Sort", heapSort2, arr, n);
    //SortTestHelper::testSort("Merge Sort", mergeSort, arr, n);
    int flag = 1;
    for(int i = 1; i < n; i ++)
        if(arr1[i-1] > arr1[i]){
            flag = 0;
            break;
        }
    cout << flag;       
    delete[] arr;
    delete[] arr1;
    delete[] arr2;
}
