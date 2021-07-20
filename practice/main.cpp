#include <iostream>
#include <ctime>
#include "mergeSort.h"
#include "quickSort.h"
#include "searchNum.h"

using namespace std;

int* generateArray(int n, int lRange, int rRange){
    int* arr = new int[n];
    srand(time(NULL));
    for(int i = 0; i < n; i ++){
        arr[i] = rand()%(rRange-lRange+1)+lRange;
    }
    return arr;
}

int* copyIntArray(int a[], int n){
    int* arr = new int[n];
    copy(a, a+n, arr);
    return arr;
}

void testSort(string sortName, void(*sort)(int [], int), int arr[], int n){
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock(); 
        int flag = 1;
        for(int i = 1; i < n; i ++){
            if(arr[i-1] > arr[i]){
                flag = 0;
                break;
            }
        }
        cout << sortName << " : " << double(endTime-startTime)/CLOCKS_PER_SEC << "s" << endl;
        cout << flag << endl;
        return;
}

int main(){
    int n = 20, k = 19;
    int* arr = generateArray(n, 0, n);
    int* arr1 = copyIntArray(arr, n);
    int find = searchNumofK(arr, n, k-1);
    for(int i = 0; i < n; i ++)
        cout << arr[i] << " ";
    cout << endl << find;
    //testSort("QuickSort2", quickSort2, arr1, n);
    //testSort("QuickSort", quickSort, arr, n);
    delete[] arr;
    return 0;
}