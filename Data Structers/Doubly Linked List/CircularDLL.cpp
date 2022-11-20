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
        //EDGE CASE: Empty List
        if(head==NULL){
            head=temp;
            temp->next=head;
            temp->prev=head;
            return;
        }
        curr=head;
        int count=0;
        do{
            curr=curr->next;            
        }while(curr!=head);

        curr->next = temp;
        temp->next = head;
        head->prev = temp;
        temp->prev = curr;
    
    }
    // TODO: ERROR: Deletion doesn't work if elements are less than 2
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
                if(curr->prev!= NULL)
                    curr->prev->next=curr->next;
                if(curr->next!= NULL)
                    curr->next->prev=curr->prev;
                if(curr==head!=NULL){
                    head=curr->next;
                }
                delete curr;
                break;
            }
            curr=curr->next;
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