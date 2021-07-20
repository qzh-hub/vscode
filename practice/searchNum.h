#include <iostream>
#include <ctime>


int __partition(int arr[], int l, int r){
    std::swap(arr[l], arr[rand()%(r-l+1)+l]);
    int j = l;
    int tmp = arr[l];
    for(int i = l+1; i <= r; i ++){
        if(arr[i]<tmp){
            std::swap(arr[++j], arr[i]); 
        }       
    }
    std::swap(arr[l], arr[j]);
    return j;
}

int quickSortsearch(int arr[], int l, int r, int k){
    if(l == r)
        return arr[l];
    int p = __partition(arr, l, r);
    if(p == k){
        return arr[p];
    }
    if(p > k)
        return quickSortsearch(arr, l, p-1, k);
    else
        return  quickSortsearch(arr, p+1, r, k);
}

int searchNumofK(int arr[], int n, int k){
    srand(time(NULL));
    return quickSortsearch(arr, 0, n-1, k);
}