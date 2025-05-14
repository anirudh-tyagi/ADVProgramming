#include<iostream>
using namespace std;
class stack{
    private:
    int*arr;
    int capacity;
    int top;
    public:
    stack(int size){
        capacity = size;  //size of stack
        arr=new int[capacity]; //array for stack
        top=-1;
        cout<<"stack of size :"<<capacity<<"has been created"
    
    }
    void pop(void){
        if(top==-1){
            cout<<"stack underflow"<<endl;
            return;
        }
        top =top-1;
    }
    void push(int value){
        if (top==capacity-1){
            cout<<"stack overflow"<<endl;
            return;
        }
        arr [++top]=value;
    }
    int top_element(void){
        if(top==-1){
            cout<<"stack underflow : "<<endl;
            return 0;
        }
        return arr[top];
    }
    

~stack (){
    delete[] arr;
    cout<<"memory destroyed :"<<endl;

}

};
main(){
    stack s1(6);
    s1.pop();
    s1.push(4);
    s1.push(14);
    s1.push(45);
    s1.push(35);    
    s1.push(454);
    cout<<"top element "<<s1.top_element()<< endl;
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    return 0;
}