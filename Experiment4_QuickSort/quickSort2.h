#include <iostream>

template<typename T>
int __partition2(T arr[], int l, int r){
    swap(arr[l], arr[rand()%(r-l+1)+l]);
    int i = l+1, j = r;
    while(true){
        while(arr[i]<arr[l] && i<=r)
            i ++;
        while(arr[j]>arr[l] && j>=l+1)
            j --;
        if(i > j)
            break;
        swap(arr[i], arr[j]);
        i ++;
        j --;
    }
    swap(arr[l], arr[j]); //此时i在第一个大于tmp的元素上，j在第一个小于tmp的元素上
    return j;
}

template<typename T>
void __quickSort2(T arr[], int l, int r){
    /*if(l >= r)
        return;*/
    if(r-l <= 15){
        insertionSort(arr, l ,r);
        return;
    }
    int p = __partition2(arr, l, r);
    __quickSort2(arr, l, p-1);
    __quickSort2(arr, p+1, r);
}

template<typename T>
void quickSort2(T arr[], int n){
    srand(time(NULL));
    __quickSort2(arr, 0, n-1);
}