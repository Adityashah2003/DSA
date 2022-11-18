#include <bits/stdc++.h>
using namespace std;
#define max 50

class Stack{
    int top;
    int arr[max];
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
    int peek(){
        if(top>=0)
            return arr[top];
        else{
            return -1;
        }
    }  
};
int Operator(char ch, int a, int b){
    switch(ch){
        case '*': return(a*b);break;
        case '+': return(a+b);break;
        case '-': return(a-b);break;
        case '/': return(a/b);break;
        case '^': return(a^b);break;
        default:
        return 0;
    }
}
int post_eval(string s){
    int str1;
    int str2;
    Stack s1;
    int i=0;
    for(i=0;s[i];++i){
        if(s[i] == ' ')
            continue;
        else if (isdigit(s[i])){
            int num=0;
            while(isdigit(s[i]))
            {
                num = num * 10 + (int)(s[i] - '0');
                i++;
            }
            i--;
            s1.push(num);
        }
        else{
            int val1 = s1.pop();
            int val2 = s1.pop();
            switch (s[i])
            {
            case '+': s1.push( val2 + val1); break;
            case '-': s1.push( val2 - val1); break;
            case '*': s1.push( val2 * val1); break;
            case '/': s1.push( val2/val1); break;
            }
        }
    }
    return s1.pop();
}
int main()
{
    string exp = "5 6 + 2 *";
    cout << post_eval(exp);
    return 0;
}