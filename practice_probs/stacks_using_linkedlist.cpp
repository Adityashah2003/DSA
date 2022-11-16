#include <bits/stdc++.h>
using namespace std;
#define max 50

struct node{
    int data;
    node *next;
};

class LinkedList{
    node* head;
public:
    LinkedList(){
    head = NULL;
    }
    void append(int elem){
        node* temp = new node;
        temp->data= elem;
        temp->next= head;
        head = temp;
    }
    void insert_last(int elem){
        node *temp = new node;
        node *curr = head;  //imp

        temp->next = NULL;
        temp->data = elem;
        if(head == NULL)
            head = temp;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = temp;
    }
    void delete_last(){
        node *temp = new node;
        node *prev = new node;
        node *curr = head;  //imp
        if(head == NULL)
            head = temp;
        while(curr->next != NULL){
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        delete curr;
    }
    void traverse(){
    node *temp= new node;
    temp=head;  
    while(temp!=NULL){
        cout<<temp->data<<' ';
        temp=temp->next;
    }
    cout<<endl;
    }
};
int main(){
    LinkedList L;
    L.append(100);
    L.insert_last(49);
    L.insert_last(59);
    L.insert_last(69);
    L.insert_last(79);
    L.traverse();
    cout<<endl;
    L.delete_last();
    // L.reverse();
    L.traverse();
return 0;
}
