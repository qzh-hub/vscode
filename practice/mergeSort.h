#include <iostream>

void merge(int arr[], int l, int mid, int r){
    int aux[r-l+1];
    for(int i = l; i <= r; i ++){
        aux[i-l] = arr[i];
    }
    int i = l, j = mid+1;
    for(int k = l; k <= r; k ++){
        if(i > mid){
            arr[k] = aux[j-l];
            j ++;
        }
        else if(j > r){
            arr[k] = aux[i-l];
            i ++;
        }
        else if(aux[i-l] < aux[j-l]){
            arr[k] = aux[i-l];
            i ++;
        }
        else{
            arr[k] = aux[j-l];
            j ++;
        }
    }
    return;

}

void __mergeSort(int arr[], int l, int r){
    if(l >= r)
        return;
    int mid = l+(r-l)/2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);
    if(arr[mid] > arr[mid+1])
        merge(arr, l, mid, r);
}

void mergeSort(int arr[], int n){
    __mergeSort(arr, 0, n-1);
    return;
}