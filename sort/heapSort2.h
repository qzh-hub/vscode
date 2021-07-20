#include <iostream>
#include <cmath>
#include <ctime>
#include <string>

using namespace std;

template<typename T>
void shiftDown2(T arr[], int n, int k){
    while(k*2+1 < n){
        int j = k*2+1;
        if(j+1<n && arr[j+1]>arr[j])
            j ++;
        if(arr[k] > arr[j])
            break;
        swap(arr[k], arr[j]);
        k = j;
    }
}

    

template<typename T>
void heapSort2(T arr[], int n){
    for(int i = (n-1)/2; i >= 0; i --){
        shiftDown2(arr, n, i);
    }
    for(int i = n-1; i > 0; i --){
        swap(arr[0], arr[i]);
        shiftDown2(arr, i, 0);
    }
}