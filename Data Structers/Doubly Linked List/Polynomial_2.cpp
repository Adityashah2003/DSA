#include <iostream>
using namespace std;
 

class node{
    private:
    int coff;
    int exp;
    node *next;
    public:
    node* attach(int c, int e, node *f){
        node *temp = new node;
        node *curr;
        temp->coff = c;
        temp->exp = e;
        temp->next = NULL;

        if(f ==NULL)
            return temp;
        curr =f;
        while(curr->next!=NULL){
            curr = curr->next;
            curr->next = temp;
            return f;
        }
    }
    node* read_poly(node *f){
        int c,e,i=0;
        cout<<"-1 to end";
        while(1){
            cout<<"coef: ";
            cin>>c;
            if(c==-1)
                break;
            cout<<"Exp: ";
            cin>>e;
            f = attach(c,e,f);
        }
        return f;
    }
    node* add_poly(node *a,node *b){
        node *c =NULL;
        int coff,com;
        while(a&&b){
            if(a->exp ==b->exp)
                com= 0;
            else if(a->exp>b->exp)
                com =1;
            else 
                com = -1;

            switch (com)
            {
            case 0:
                coff = a->coff + b->coff;
                if(coff!=0)
                    c = attach(coff,a->exp,c);
                a= a->next;
                b= b->next;
                break;
            
            case 1:
                c = attach(a->coff,a->exp,c);
                a->next;
                break;
            default:
                c = attach(b->coff,b->exp,c);
                b =b->next;
                break;
            }
            while(b){
                c = attach(b->coff,b->exp,c);
                b=b->next;
            }
            while(a){
                c = attach(a->coff,a->exp,c);
                a=a->next;
            }
        }
        return c;
    }
    node* mul(node *a,node *b){
        node* res = NULL;
        node* c1;
        node *c2;
        for(c1=a;c1;c1=c1->next){
            for(c2=b;c2;c2=c2->next){
                res = attach((c1->coff*c2->coff), (c1->exp+c2->exp),res);
            }
        }
        return res;
    }
    node* display(node *first){
        node* temp;
        if(first ==NULL)
            return first;
        temp=first;
        while(temp){
            if(temp->coff<0)
                cout<<temp->coff<<"x^"<<temp->exp;
            else   
                cout<< "+" <<temp->coff<< "x^" << temp->exp;
            temp=temp->next;
        }            
    }
};

int main(){
    node *poly1=NULL, *poly2=NULL, *poly3=NULL, *poly4=NULL,p;
    cout<<"Enter the first polynomial\n";
    poly1=p.read_poly(poly1);
    cout<<"Enter the second polynomial\n";
    poly2=p.read_poly(poly2);
    poly3 = p.add_poly(poly1,poly2);
    poly4 = p.mul(poly1,poly2);
    p.display(poly3);
    p.display(poly4);

}