#include <bits/stdc++.h>
using namespace std;
#define max 50

struct node{
    int data;
    node *next;
    node *prev;
};

class DLL{
    node* head;
    node* tail;

public:
    DLL(){
    head = NULL;
    tail = NULL;
    }
    void append(int elem){
        node* temp = new node;
        temp->data= elem;
        temp->next= head;
        temp->prev = NULL;
        head = temp;
    }
    void insert_front(int elem){
        node* temp = new node;
        temp->data = elem;
        temp->next = head;
        temp->prev = NULL;
        head = temp;
    }
    void insert_last(int elem){
        node *temp = new node;
        node *prevn = new node;
        node *curr = head;  //imp
        temp->next = NULL;
        temp->data = elem;
        temp->prev = NULL;
        if(head == NULL)
            head = temp;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = temp;
        temp->prev = curr;
    }
    node* delete_front(){
        node *temp = head;
        if (head == NULL)
            return NULL;
        else{
            head = head->next;      //moved head to next node
            head->prev = NULL;
            delete temp;
        }
        return head;
    }
    void delete_last(){
        node *temp = new node;
        node *prevn = new node;
        node *curr = head;  //imp
        if(head == NULL)
            head = temp;
        while(curr->next != NULL){
            prevn= curr;
            curr = curr->next;
        }
        prevn->next = NULL;
        delete curr;
    }
    void delete_specific(int d){
        node *temp = new node;
        node *prevn = new node;
        node *curr = head;   //always initialise curr to head
        if(head == NULL)
            cout<<"Empty";
        else if(head->data == d){
            head = head->next;      //moved head to next node
            head->prev = NULL;
            delete temp;
        }
        else{
            while(curr ->next != NULL){
                if(curr->data ==d){
                    prevn->next = curr->next;
                    curr->next->prev = prevn;
                    delete curr;
                }
            prevn= curr;
            curr= curr->next; 
            }
        }
    }
    void insert_specific(int d,int elem){
        node *temp = new node;
        node *prevn = new node;
        node *curr = head;   //always initialise curr to head
        if(head == NULL)
            cout<<"Empty";
        else if(head->data == d){
            temp->data = elem;
            temp->next = head;
            temp->prev = NULL;
            head = temp;
        }
        else{
            while(curr ->next != NULL){
                if(curr->data ==d){
                    temp->data = elem;
                    prevn->next = temp;
                    temp->prev = prevn;
                    temp->next = curr;
                    curr->prev = temp;
                }
            prevn= curr;
            curr= curr->next; 
            }
        }
    }
    void  reverse(){
        node *temp=NULL;
        node *prevn=NULL;
        node *curr=head;
        while(curr!=NULL){
            swap(curr->next,curr->prev);
            prevn = curr;
            curr=curr->prev;
        }   
        head = prevn;
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
    DLL dll;
    dll.append(100);
    dll.append(2100);
    dll.append(10);
    dll.append(5);
    dll.append(49);
    // dll.insert_specific(2100,69);
    dll.traverse();

    cout<<endl;
    // dll.delete_front();
    // dll.delete_last();
    // dll.delete_specific(69);
    // dll.reverse();
    dll.traverse();
return 0;
}
