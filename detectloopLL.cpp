#include<iostream>
using namespace std;
#include<map>
class Node{
    public:
    int data;
    Node* Next;

    Node(int d){
        this data -> d;
        this next -> NULL;
    }

}
bool detectloop(Node * head){
    if(head == NULL){
        return false;
    }
    Node* temp = head ;
    map<Node*,bool> visited ;
     while(temp!=NULL){
        if(visited[temp]== true){
            return true;
        }
        visited[temp]= true;
        temp= temp->next;
     }
}


//Floyd's Cycle detection Method


Node* floyd(Node* head){
    if(head== NULL){
        return NULL;
    }
    Node* fast= head;
    Node* slow =head;
   while(fast!=NULL && slow!=NULL){
    fast=fast->Next;
    if(fast!= NULL){
        fast->Next;
    }
    slow = slow->Next;
    if(fast==slow){
        cout<<"cycle is present at"<<slow->data;
        return slow;
    }}
    return NULL;
}
  
  
  // finding starting point of loop --



   Node* startingnode(Node*head){
    if (head==Null){
        return NULL;
    }
    Node* intersection= floyd(head);
    Node* slow = head;
    while(slow!=intersection){
        slow= slow->Next;
        intersection=intersection->Next;

    }
    return slow;

   }
void removeloop(Node*head){
    Node* loopstart= startingnode(head);
    Node* temp=loopstart;
    while(temp->Next!=loopstart){
        temp=temp->Next;
    }
    temp ->Next = NULL;
    return;
}