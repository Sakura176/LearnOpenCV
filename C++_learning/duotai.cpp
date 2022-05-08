#include <iostream>

using namespace std;

class WashMachine{
public:
    virtual void wash(){
        cout << "洗衣机在洗衣服" << endl;
    }
};


class SmartWashMachine : public WashMachine{
public:
   virtual  void wash(){
        cout << "智能洗衣机在洗衣服" << endl;

    }
};


int main(){

    WashMachine *w2 = new SmartWashMachine(); //父类指针指向子类对象 打印..智能洗衣机在洗衣服
    w2->wash();

    return 0 ;
}