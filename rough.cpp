#include<iostream>
using namespace std;
class A{
    public:
    int a;
    A(int x):a(x){
        cout<<"Created"<<endl;
    }
    A(){
        cout<<"A()"<<endl;
    }
    A(const A &cpy):a(cpy.a){
        cout<<"Copy Constructor"<<endl;
    }
};
void func(const A cl){
    cout<<(cl.a)<<endl;
}
int main(){
    A abc(2);
    func(abc);
    A a;
    a = abc;
    func(a);
    // A a = std::move(abc);
    return 0;
}