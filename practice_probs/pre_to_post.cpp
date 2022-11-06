#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
template <typename T>
#define max 50

class Stack{
    int top;
    T arr[max];
public:
    Stack(){
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
    void push(T elem){
        if(isFull()){
            cout<<"stacks if full";
        }
        else
            arr[++top]=elem;
    }
    T pop(){
        if(isEmpty()){
            cout<<"stacks if empty";
        }
        else
            return arr[top--];
    }
    T peek(){
        if(top>=0)
            return arr[top];
        else{
            return " ";
        }
    }  
};
string pre_post(string s){
    Stack<string> s1;
    string res;
    string op1;
    string op2;
    int i=0;

    for(i=0;i<s.length();i++){
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')|| (c >= '0' && c <='9'))
            s1.push(string(1,c));
        else{
            op1 = s1.peek();
            s1.pop();
            op2 = s1.peek();
            s1.pop();
            res = op1+op2+c;
            s1.push(res);
        }
    }
    string ans = "";
    while (!s1.isEmpty()) {
        ans += s1.peek();
        s1.pop();
    }
    return ans;
};
int main()
{
    string pre_exp = "+ab";
    reverse(pre_exp.begin(),pre_exp.end());
    cout << "Postfix is : " << pre_post(pre_exp);
    return 0;
}