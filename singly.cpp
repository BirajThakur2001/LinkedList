#include<iostream>
using namespace std;
class node{
    public:
int data;
node*next;

//constructor
node (int data){
    this->data=data;
    this->next=NULL;
}
// destructor
~node(){
    int value=this->data;
    if(this->next!=NULL){
       delete next;
       this->next=NULL;
         }
  cout<<"Memory is free for node with data"<<value<<endl;
}
};
void insertatHead(node*&head,int d){
    node*temp=new node(d);
    temp->next=head;
    head=temp;
}
void insertatTail(node*&tail,int d){
    node*temp=new node(d);
    tail->next=temp;
    tail=temp;
}
void print(node* &head){
    node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;

    }cout<<endl;
}

void insertatmiddle(node* &head,node* &tail,int position,int d){
   
   if (position==1){
        insertatHead(head,d);
        return;
    } 
    node* temp=head;
    int cnt=1;
    while (cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    
    if (temp->next==NULL){
        insertatTail(tail,d);
        return;
    }
    node*nodetoinsert=new node(d);
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;

}
void deletion(node*head,int position){
    if (position==1){
        node*temp=head;
        head=head->next;
       temp->next=NULL;
        delete temp;
    }
    else{
        node*curr=head;
        node*prev=NULL;
        int cnt=1;
        while(cnt<position){
           prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

int main(){
  node *node1=new node(10);
  node *head=node1;
  node *tail=node1;
   print(head);
//    insertatHead(head,12);
//    print(head);
//     insertatHead(head,20);
//    print(head);
   insertatTail(tail,23);
   print(head);
   insertatTail(tail,26);
   print(head);
   insertatmiddle(head,tail,4,16);
    print(head);

    deletion(head,2);
    print(head);

}