#include <iostream>

using namespace std;

template<typename T>
int partition(T arr[], int l, int r){
    swap(arr[l], arr[rand()%(r-l+1)+l]);
    int pos = l;
    for(int i = l+1; i <= r; i ++){
        if(arr[i] < arr[l]){
            pos ++;
            swap(arr[pos], arr[i]);
        }           
    }
    swap(arr[pos], arr[l]);
    return pos;
}

template<typename T>
int partition2(T arr[], int l, int r){
    swap(arr[l], arr[rand()%(r-l+1)+l]);
    int j = r, i = l+1;
    while(true){
        while(arr[i]<arr[l] && i<=r)
            i ++;
        while(arr[j]>arr[l] && j>=l+1)
            j --;
        if(i >= j)
            break;
        swap(arr[i], arr[j]);
        i ++;
        j --;
    }
    swap(arr[l], arr[j]);
    return j;
}

template<typename T>
void __quickSort(T arr[], int l, int r){
    if(l >= r)
        return;
    int pos = partition(arr, l, r);
    __quickSort(arr, l, pos-1);
    __quickSort(arr, pos+1, r);
}

template<typename T>
void __quickSort2(T arr[], int l, int r){
    if(l >= r)
        return;
    int pos = partition2(arr, l, r);
    __quickSort2(arr, l, pos-1);
    __quickSort2(arr, pos+1, r);
}

template<typename T>
void quickSort(T arr[], int n){
    srand(time(NULL));
    __quickSort(arr, 0, n-1);
}

template<typename T>
void quickSort2(T arr[], int n){
    srand(time(NULL));
    __quickSort2(arr, 0, n-1);
}
    

