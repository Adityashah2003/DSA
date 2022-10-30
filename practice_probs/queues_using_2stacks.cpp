#include <iostream>
using namespace std;
#define max 100

class stack{
public:
    int top;
    int arr[max];
    stack(){
        top =1;
    }
    bool isEmpty(){
        if(top==-1)
            return (top==-1);
    }
    bool isFull(){
        return (top+1==max);
    }
    void push(int elem){
        if(!isFull()){
            arr[++top]=elem;
        }
    }
    int pop(){
        if(!isEmpty()){
            return arr[top--];
        }
    }
    void display(){
        for(int i=top;i>=0;i--)
            cout<<arr[i]<<" ";
    }
};

class queue{
    stack s,s1,s2;
public:
    void enQ(int x){
        if(s1.isEmpty())
            s1.push(x);
        else{
            while(!s1.isEmpty()){
            s2.push(s1.pop());
            }
            s1.push(x);
            while(!s2.isEmpty()){
                s1.push(s2.pop());
            }
        }
    }
    int deQ(){
            return s1.pop();
    }
    void disp(){
        s1.display();
    }
};
int main()
{
    queue q;
    q.enQ(1);
    q.enQ(5);
    q.enQ(69);
    q.disp();
    q.deQ();
    q.disp();

    return 0;
}
