#include <iostream>
using namespace std ;
class node{
    public:
   int data ;
   node* next ;


   node(int data){
    this ->data=data;
    this->next= NULL;
   }
};

void printg(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout <<temp->data << " ";
        temp=temp->next;
    }

}

// removing duplicates in a linked  list ** SORTED LINKED LIST !!

node* duplicatesLL(node * &head){
    node * curr = head;
    while (curr != NULL){
        if( (curr->next!=NULL)&&curr ->data == curr->next->data ){
            node *next2 = curr->next->next;
            node * nodetodelte=curr->next;
            delete(nodetodelte);
            curr->next=next2;
        }
        else {
            curr=curr->next;
        }
    }
    return head;
}
void insertattail(node* &tail,int d){
    node * trmp = new node (d);
    tail ->next= trmp;
    tail=trmp;

}

int main()
{
    node * temp = new node(10);
    node * head = temp;
   node * tail = temp;
   insertattail(tail,11);
   insertattail(tail,11);
   insertattail(tail,12);
   insertattail(tail,13);
   insertattail(tail,13);
   insertattail(tail,11);  
   printg(head);
   cout << endl;
   duplicatesLL(head);
    printg(head); 
   return 0;
}