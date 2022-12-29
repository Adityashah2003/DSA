// Menu Driven program to implement a Circular Doubly Linked List
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next, *prev;
};

class DoublyCircular{
private:
    Node *head;
public:
    DoublyCircular(){
        head=NULL;
    }
    void insert(int elem){
        Node *temp= new Node;
        Node *curr= new Node;
        temp->data=elem;
        if(head==NULL){
            head=temp;
            temp->next=head;
            temp->prev=head;
            return;
        }
        curr=head;
        do{
            curr=curr->next;
        }while(curr!=head);
        cout<<curr->data;            

        curr->prev->next=temp;
        temp->prev=curr->prev;
        temp->next=curr;
        curr->prev=temp;
    }
    void delete_elem(int elem){
        Node *curr= head;
        if(head==NULL){
            cout<<"List empty!";
            return;
        }
        else if(head->data=elem){
            head=NULL;
            delete head;
        }
        do{
            if(curr->data==elem){
                if(curr->prev)
                    curr->prev->next=curr->next;
                if(curr->next)
                    curr->next->prev=curr->prev;
                if(curr==head){
                    head=curr->next;
                }
                delete curr;
                break;
            }
        }while(curr!=head);
    }

    void display(){
        Node *curr= new Node;
        curr=head;
        do{
            cout<<curr->data<<' ';
            curr=curr->next;
        }while(curr!=head);
        cout<<endl;
    }
};

int main(){
    DoublyCircular DC;
    int choice, elem;
    cout<<"THE FOLLOWING OPEARTIONS CAN BE PERFORMED ON THE CIRCULAR DOUBLY LINKED LIST:"<<endl;
    cout<<"1.Insert an element at a position"<<endl;
    cout<<"2.Delete an element"<<endl;
    cout<<"3.Display"<<endl;
    cout<<"4.Exit"<<endl;
    while(true){
        cout<<">";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter the element to insert :";
                cin>>elem;
                DC.insert(elem);
                break;
            case 2:
                cout<<"Enter the element to delete:";
                cin>>elem;
                DC.delete_elem(elem);
                break;
            case 3:
                DC.display();
                break;
            case 4:
                return 0;
            default:
                cout<<"Invalid Choice"<<endl;
        }
    }
}