#include <iostream>
#include <ctime>
#include <cassert>
using namespace std;
namespace SortHelper{

    int* generateRandomArray(int n, int rangeL, int rangeR){
        assert(rangeL <= rangeR);
        int* arr = new int[n];
        srand(time(NULL));
        for(int i = 0; i < n; i ++)
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;      
        return arr;
    }

    template<typename T>
    void testSort(string sortName, void(*sort)(T[], int), T arr[], int n){
        //记录算法运行时间
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        //swap(arr[0], arr[20000]);    
        //检验是否已经排好序
        int flag = 1;
        for(int i = 1; i < n; i ++){
            if(arr[i-1] > arr[i]){
                flag = 0;
                break;
            }
        }   
        cout << sortName << " : " << double(endTime-startTime)/CLOCKS_PER_SEC << "s" << "  " << "flag = "<< flag << endl;        
        return;
    }

    int* generateNearlyOrderedArray(int n, int swapTimes){
        int* arr = new int[n];
        srand(time(NULL));
        for(int i = 0; i < n; i ++)
            arr[i] = i;      
        for(int i = 0; i < swapTimes; i ++){
            int posx = rand()%n;
            int posy = rand()%n;
            swap(arr[posx], arr[posy]);
        }
        return arr;
    }
}