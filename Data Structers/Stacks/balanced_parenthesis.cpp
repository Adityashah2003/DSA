#include<iostream>
using namespace std;
#include <string.h>
#define max 50

char open[]={'{','[','('};
char close[]={'}',']',')'};

class stack{
    int top;
    int arr[max];
public:
    stack(){
        top=-1;
    }
    bool isEmpty(){
        if(top==-1)
            return true;
        else 
            return false;
    }
    bool isFull(){
        if(top==max-1)
            return true;
        else 
            return false;
    }
    void push(int elem){
        if(isFull()){
            cout<<"stacks if full";
        }
        else
            arr[++top]=elem;
    }
    int pop(){
        if(isEmpty()){
            cout<<"stacks if empty";
        }
        else
            return arr[top--];
    }
    char peek(){
        if(top>=0)
            return arr[top];
        else{
            return -1;
        }
    }
};
int main(){
    stack s;
    char str[100];
    cout<<"Enter a string";
    cin>>str;
    int n = strlen(str);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(str[i]==open[j]){
                s.push(str[i]);
            }
            else if(str[i]==close[j] & s.peek()==open[j]){
                s.pop();
            }
        }
    }
    if(s.isEmpty())
        cout<<"Balanced";
    else    
        cout<<"nOt Balanced";
}