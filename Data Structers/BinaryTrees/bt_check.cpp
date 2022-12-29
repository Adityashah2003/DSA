#include<bits/stdc++.h>
using namespace std;
#define max 100

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
	Node (int data)
	{
		this->data = data;
		left = right = NULL;
	}
};
class Stacks{
public:    
    Node* arr[max];
    int top;
    Stacks(){
        top= -1;
    }
    bool isempty(){
        if(top==-1)
            return true;
        else 
            return false;
    }
    bool isFull(){
        if(top == max-1)
            return true;
        else    
            return false;
    }
    void push(Node *c){
        if(isFull())
            cout<<"Stack is full";
        else    
            arr[++top]=c;
    }
    Node* pop(){
        if(isempty())
            cout<<"Stack is empty";
        else    
            return arr[top--];
    }
    Node* peek(){
        return arr[top];
    }

};
class bt{
public:
    void inOrder( Node *root){
        Stacks s;
        Node *curr = root;
        while (curr != NULL || s.isempty() == false){
            while (curr != NULL){
                s.push(curr);
                curr = curr->left;
            }
            curr = s.peek();
            s.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
    }
    void preorder(Node* root){
        Node* curr = root;
        Stacks s1;
        s1.push(curr);
        while(!s1.isempty()){
            curr = s1.peek();
            cout << curr->data << " ";
            s1.pop();
            if(curr->right)
                s1.push(curr->right);
            if(curr->left)
                s1.push(curr->left);
        }        
    }
    void postorder(Node* root){
        Node* curr = root;
        Node* temp;
        Stacks s2;
        Stacks s3;
        s2.push(curr);
        while(!s2.isempty()){
            curr = s2.peek();
            s2.pop();
            s3.push(curr);

            if(curr->left)
                s2.push(curr->left); 
            if(curr->right)
                s2.push(curr->right);
        }
        while(!s3.isempty()){
            temp = s3.pop();
            cout<<temp->data;
        }
    }
};
int main()
{
	struct Node *root = new Node(1);
	root->left	 = new Node(2);
	root->right	 = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);

    bt bt;
	bt.inOrder(root);
    bt.preorder(root);
    bt.postorder(root);

	return 0;
}
