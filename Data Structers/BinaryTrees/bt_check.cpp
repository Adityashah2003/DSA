#include <bits/stdc++.h>
using namespace std;
#define max 50


struct node{
    char data;
    node *left;
    node *right;
};
class binarytree{

private:    node *root;
protected:
    node* createTree(){
        char val;
        cout<<">";
        cin>>val;
        if(val=='p')
            return NULL;
        node *temp= new node;
        temp->data=val;   
        cout<<"Left child of "<<val<<endl;
        temp->left=createTree();
        cout<<"Right child of "<<val<<endl;
        temp->right=createTree();
    }
public:
    binarytree(){
        root = NULL;
    }
    void create(){
        cout<<"Use p to break"<<endl;
        cout<<"Enter root"<<endl;
        root=createTree();
    }
    void IterativePreorder(){

        if(root==NULL)
            return;
        stack <node*> s;
        node *curr=root;

        s.push(curr);
        while(!s.empty()){
            curr = s.top();
            s.pop();
            cout<<curr->data;
            if(curr->right){
                s.push(curr->right);
            }
            if(curr->left){
                s.push(curr->left);
            }
        }
    }
    void IterativePostorder(){
        if(root==NULL)
            return;
        stack <node*> s1;
        stack <node*> s2;
        node *curr=root;
        node *temp = new node;
        s1.push(curr);
        while(!s1.empty()){
            temp = s1.top();
            s1.pop();
            s2.push(temp);
            if (curr->left)
                s1.push(curr->left);
            if (curr->right)
                s1.push(curr->right);
        }
        while (!s2.empty()) {
            curr = s2.top();
            s2.pop();
            cout << curr->data << " ";
        }
    }
    void IterativeInorder(){
        if(root==NULL)
            return;
        stack <node*> s;
        node *curr=root;

        while(curr!=NULL || !s.empty()){
            while(curr!=NULL){
                s.push(curr);
                curr=curr->left;
            }
            curr=s.top();
            s.pop();
            cout<<curr->data;
            curr=curr->right;
        }
        cout<<endl;
    }
};
int main(){
    binarytree bt;
    bt.create();
    bt.IterativePreorder();
    bt.IterativeInorder();
}
