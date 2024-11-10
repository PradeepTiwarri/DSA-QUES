#include<iostream>
using namespace std ;
 
 class Node{
    public:
    int data ;
    Node * next;

    Node(int d){
        this ->data =d;
        this ->next = NULL;
    }
 };
    void print(Node * &head){
        Node * temp= head;
        while(temp != NULL ){
            cout<<temp->data<<" ,";
            temp=temp ->next;
        }
    }
    void insertathead(Node* &head,int d ){
        Node* temp = new Node(d);

        temp ->next =head;
        head = temp;
    }
    void insertattail(Node* &tail,int d){
        Node* temp= new Node(d);
        tail ->next = temp;
        tail = temp;
    }
    void insertatposition(Node*&head,Node*&tail,int position,int d){
        if(position==1){
            insertathead(head,d);
            return;
        }
        Node* temp= head;
        int cnt = 1;
         while(cnt < position-1){
            temp =temp -> next ;
            cnt ++;

         }
         if (temp->next == NULL){
            insertattail(tail,d);
            return;
         }
         Node* nodetoinsert=new Node(d);
        nodetoinsert ->next = temp ->next;
         temp -> next = nodetoinsert ;

    }

 
 int main(){
    Node * node1 = new Node(10);
   // cout << node1 -> data<< endl;
  // cout<< node1 -> next << endl;
    Node* head = node1;
    
    Node * tail = node1;
   insertathead(head,12);
    
    insertattail(tail,16);
    insertatposition(head,tail,1,20);
    print(head);
   


    return 0;

 }