#include <iostream>


template<typename T>
void __merge(T arr[], int l, int mid, int r){
    T aux[r-l+1];
    for(int i = 0; i < r-l+1; i ++)
        aux[i] = arr[i+l];
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
    
}

//自顶向下的归并
template<typename T>
void __mergeSort(T arr[], int l, int r){
    if(l >= r)
        return;
    //优化 数组长度较小时可使用插入排序提高速度
    // if(r-l < 15){
    //     insertionSort(arr, l ,r)；
    //     return;
    // }
    int mid = l + (r-l)/2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);
    //优化，减少归并次数
    if(arr[mid] > arr[mid+1])
        __merge(arr, l, mid, r);
}

//自底向上的归并
template<typename T>
void mergeSortBU(T arr[], int n){
    for(int sz = 1; sz <= n; sz += sz){
        for(int i = 0; i+sz < n; i += sz*2){
            if(arr[i+sz-1] > arr[i+sz])
                __merge(arr, i, i+sz-1, min(i+sz+sz-1, n-1));
        }
    }
    return;
}

template<typename T>
void mergeSort(T arr[], int n){
    __mergeSort(arr, 0, n-1);
}
