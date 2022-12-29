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
    void insert_front(int elem){
        node* temp = new node;
        temp->data = elem;
        temp->next = head;
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
    node* delete_front(){
        node *temp = head;
        if (head == NULL)
            return NULL;
        else{
            head = head->next;      //moved head to next node
            delete temp;
        }
        return head;
    }
    void delete_last(){
        node *temp = new node;
        node *curr = head;  //imp
        if(head == NULL)
            head = temp;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = temp;
        delete curr;
    }
    void delete_specific(int d){
        node *temp = new node;
        node *prev = new node;
        node *curr = head;   //always initialise curr to head
        if(head == NULL)
            cout<<"Empty";
        else if(head->data == d){
            temp = head;
            head = head ->next;
            delete temp;
        }
        else{
            while(curr ->next != NULL){
                if(curr->data ==d){
                    prev->next = curr->next;
                    delete curr;
                }
            prev= curr;
            curr= curr->next; 
            }
        }
    }
    void insert_specific(int d,int elem){
        node *temp = new node;
        node *prev = new node;
        node *curr = head;   //always initialise curr to head
        if(head == NULL)
            cout<<"Empty";
        else if(head->data == d){
            temp->data = elem;
            temp->next = NULL;
            head->next = temp;
        }
        else{
            while(curr ->next != NULL){
                if(curr->data ==d){
                    temp->data = elem;
                    prev->next = temp;
                    temp->next = curr;
                }
            prev= curr;
            curr= curr->next; 
            }
        }
    }
    void  reverse(){
        node *first = new node;
        node *prev = NULL;
        node *curr = head;

        while(curr != NULL){
            first = curr ->next;
            curr ->next=prev;
            prev = curr;
            curr = first;
        }  
        head = prev;
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
    L.append(2100);
    L.append(10);
    L.insert_front(5);
    L.insert_last(49);
    L.traverse();
    cout<<endl;
    L.insert_specific(2100,69);
    // L.reverse();
    L.traverse();
return 0;
}
