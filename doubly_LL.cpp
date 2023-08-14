#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node* prev;
// constrictor
    node(int d){
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
    }  
//  destructor
   ~node(){
    int value=this->data;
    if(next!=NULL){
        delete next;
       this->next=NULL;
    }
    cout<<"Memory is free with data "<<value <<endl;
   }
};
void insertatHead(node* &head,int d){
    node*temp=new node(d);
    temp->next=head;
    head->prev=temp;
     head=temp;
}
void insertatTail(node*&tail,int d){
    node* temp=new node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}
void insertatMiddle(node* & tail,node* & head,int position,int d){
    
    if(position==1){
        insertatHead(head,d);
        return;
    }
   node* temp=head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
     if (temp->next==NULL){
        insertatTail(tail,d);
        return;
    }
    node*nodetoinsert=new node(d);
    nodetoinsert->next=temp->next;
    temp->next->prev=nodetoinsert;
    temp->next=nodetoinsert;
    nodetoinsert->prev=temp;
}
void delection(node*&head,int position){
    if(position==1){
        node*temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
           }
    else{
        node*prev=NULL;
        node*curr=head;
        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
void print(node * &head){
      node *temp=head;
       while( temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
         }
       cout<<endl;
     }
int getlength(node *head){
node *temp=head;
   int cnt=1;
       while( temp!=NULL){
cnt++;
temp=temp->next;
         } 
}


int main(){
node *node1=new node(10);
node *head=node1;
node* tail=node1;
print(head); 
// cout<<getlength(head);
insertatHead(head,14);
insertatHead(head,16);
insertatTail(tail,13);
insertatTail(tail,23);
// insertatTail(tail,87);
print(head);
insertatMiddle(tail,head,2,12);
print(head);
delection(head,6);
print(head);

}