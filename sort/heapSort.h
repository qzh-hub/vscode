#include <iostream>
#include <cmath>
#include <ctime>
#include <string>

using namespace std;

template<typename T>
class MaxHeap{
    private:
        T* data;
        int count;
        //int capacity;

        void shiftUp(int k){
            while(k>1 && data[k/2]<data[k]){
                swap(data[k/2], data[k]);
                k /= 2;
            }
        }

        void shiftDown(int k){
            while(k*2 <= count){
                int j = k*2;
                if(j+1<=count && data[j+1]>data[j])
                    j ++;
                if(data[k] > data[j])
                    break;
                swap(data[k], data[j]);
                k = j;
            }
        }

    public:

        MaxHeap(int capacity){
            data = new T[capacity+1];  //索引从1开始
            count = 0;
            //this->capacity = capacity;
        }

        MaxHeap(T arr[], int n){
            data = new T[n+1];
            count = n;
            for(int i = 0; i < n; i ++){
                data[i+1] = arr[i];
            }
            int k = n/2;
            while(k > 0){
                shiftDown(k);    
                k --;
            }
        }

        ~MaxHeap(){
            delete[] data;
        }

        int size(){
            return count;
        }

        bool isEmpty(){
            return count == 0;
        }

        void insert(T item){
            data[count+1] = item;
            count ++;
            shiftUp(count);
        }

        void showData(){
            for(int i = 1; i <= count; i ++){
                cout << data[i] << " ";              
            }
            cout << endl;
        }

        T extractMax(){
            T res = data[1];
            data[1] = data[count];
            count --;
            shiftDown(1);
            return res;
        }
};

template<typename T>
void heapSort(T arr[], int n){
    MaxHeap<T> maxheap = MaxHeap<T>(arr, n);
    for(int i = n-1; i >= 0; i --){
        arr[i] = maxheap.extractMax();
    }
}

/*template<typename T>
void heapSort(T arr[], int n){

}*/