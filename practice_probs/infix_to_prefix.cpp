#include<iostream>
#include<locale> //for function isalnum()
#include<algorithm>
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
    char peek(){
        if(top>=0)
            return arr[top];
        else{
            return -1;
        }
    }  
};
int pred(char c)
{
    if (c == '^')
        return 3;
    else if (c=='%'|| c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
void infix_prefix(string s){
    string result;
    Stack s1;
    int i=0;
    for(i=0;i<s.length();i++){
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')|| (c >= '0' && c <='9'))
            result += c;
        else if (c=='(')
            s1.push(c);
        else if (c==')'){
            while(!s1.isEmpty() && s1.peek()=='('){
                result += s1.peek();
                s1.pop();
            }
            s1.pop();
        }
        else{
            while(!s1.isEmpty()&& pred(c)<=pred(s1.peek())){
                result += s1.peek();
                s1.pop();
            }
            s1.push(c);
        }   
    }
    while (!s1.isEmpty()) {
        result += s1.peek();
        s1.pop();
    }
    reverse(result.begin(), result.end());
    cout << result << endl;
}
int main(){
    string s = "a+b";
    reverse(s.begin(), s.end());
    infix_prefix(s);
return 0;
}
