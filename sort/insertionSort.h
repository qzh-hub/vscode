#include <iostream>

// v1.0
// template<typename T>
// void insertionSort(T arr[], int n){
//     for(int i = 1; i < n; i ++){
//         for(int j = i; j > 0 && arr[j] < arr[j-1]; j --){
//             std::swap(arr[j], arr[j-1]);
//         }
//     }
//     return;
// }

// v2.0 每次循环只交换一次
template<typename T>
void insertionSort(T arr[], int n){
    for(int i = 1; i < n; i ++){
        int tmp = arr[i];
        int j;
        for(j = i; j > 0 && arr[j-1] > tmp; j --){
            arr[j] = arr[j-1];
        }
        arr[j] = tmp;
    }
    return;
}

template<typename T>
void insertionSort(T arr[], int l, int r){
    for(int i = l+1; i <= r; i ++){
        T tmp = arr[i];
        int j;
        for(j = i; j > l && arr[j-1] > tmp; j --){
            arr[j] = arr[j-1];
        }
        arr[j] = tmp;
    }
    return;
}