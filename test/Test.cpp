#include <iostream>
#include <vector>

using namespace std;
class A{
    public:
        int id;
        A():id(0){
            cout << "default ctor.this = " << this << "  id = " << id <<endl;
        }
        A(int i):id(i){
            cout << "ctor.this = " << this << "  id = " << id <<endl;
        }
        ~A(){
            cout << "dtor.this = " << this << "  id = " << id <<endl;
        }
};

int main(){
    /*A* buf = new A[3];
    A* tmp = buf;
    cout << "buf = " << buf <<"     tmp = " << tmp << endl;
    A* tmp2;
    for(int i = 0; i < 3; i ++){
        if(i == 1)
            tmp2 = tmp;
        new(tmp++) A(i);
    }*/
    vector<int> a;
    for(int i = 0; i < 2; i ++){
        a.emplace_back(i);
    }
    //cout << "buf = " << buf <<"     tmp = " << tmp << "     tmp2->id = " << tmp2->id << endl;
    //delete[] buf;
    //cout << "     tmp2->id = " << tmp2 << "  " << tmp2->id << endl;
    /*cout << &a[0] << endl;
    vector<int>::iterator it = a.begin();
    auto res = &a[0];
    int count = 0;
    cout << count << " : " << res << endl;
    for(int i = 5; i < 500; i ++){
        a.emplace_back(i);
        if(&a[0] != res){
            count ++;
            res = &a[0];
            cout << "i = " << i << "  " << count << " : " << res << endl;
        }
    }*/
    cout << a.capacity() << endl;
    auto iter = a.begin();
    cout << *iter << endl;
    a.emplace_back(6);
    a.emplace_back(7);
    
    cout << *iter;
    int* b;
    int c[4];
    //cout << sizeof(a) << " " << sizeof(b) << " " << sizeof(c);
    return 0;
}
