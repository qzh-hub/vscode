#include <iostream>
#include "SortHelper.h"
#include "insertionSort.h"
#include "selectionSort.h"
#include "quickSort2.h"
#include "quickSort.h"

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
    int n = 1000000;
    for(int i = 0; i < 11; i ++){
        int* arr = SortHelper::generateRandomArray(n, 0, n);
        int num = rand() % (n+1);
        for(int k = 0; k < i*n/10; k ++){
            arr[k] = num;
        }
        for(int j = 0; j < i*n/10; j ++){
            int posx = j;
            int posy = rand()%n;
            swap(arr[posx], arr[posy]);
        }
        int* arr1 = copyIntArray(arr, n);
        cout << "i = " << i << endl;
        SortHelper::testSort("Quick Sort", quickSort, arr, n);
        SortHelper::testSort("Quick Sort plus", quickSort2, arr1, n);
        //printArray(arr, n);
        cout << endl;
        //printArray(arr1, n); 
        delete[] arr;
        delete[] arr1;
    }
    

       
    //printArray(arr, 10);
    //printArray(arr1, 10); 
    
}
