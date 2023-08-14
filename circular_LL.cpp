#include<iostream>
using namespace std;
class node{
 public:
 int data ;
 node* next;

 node(int d){
    this->data=d;
    this->next=NULL;
 }
 ~node(){
    int value=this->data;
    if(this->next!=NULL){
        delete next;
        next=NULL;
    }
    cout<<"memory is free from  "<< value <<endl;
 }
};

void insertnode(node* &tail,int element,int d){
   if (tail==NULL){
    node*newnode=new node(d);
    tail=newnode;
    newnode->next=newnode;
   }
   else{
    node* curr=tail;
    while(curr->data!=element){
        curr=curr->next;
    }
    node*temp=new node(d);
    temp->next=curr->next;
    curr->next=temp;
   }
}
void deletenode(node*& tail,int value){
   if (tail==NULL){
      cout<<"the list is empty"<<endl;
   }
   else{
      node* prev=tail;
     node* curr=prev->next;
      while(curr->data!=value){
         prev=curr;
         curr=curr->next;
      }
      prev->next=curr->next;
      if (tail==curr){
         tail=prev;
      }
      curr->next=NULL;
      delete curr;
   }
}
void print(node*&tail){
 node*temp=tail;
  do{
    cout<<tail->data<<" ";
tail=tail->next;
  } while(tail!=temp);
  cout<<endl;
}
int main (){
// node*node1=new node(10);
node* tail=NULL;
insertnode(tail,5,3);
print(tail);

insertnode(tail,3,5);
print(tail);
insertnode(tail,5,6);
print(tail);
insertnode(tail,6,9);
print(tail);
deletenode(tail,3);
  print(tail);
}