// basic operation in linked list 
// 1. singly- linked list 

// node creation 
//  singly linked list node
#include<bits/stdc++.h>
using namespace std;



class node {
    public:
    int data;
    node* next;
};


// dububly linked list Node

class Node {
    public:
    int data;
    Node* prev;
    Node* next;
};


node* newnode(int data)
{
    node* temp = new node;
    temp ->data = data;
    temp->next = NULL;
    return temp;
}

// to print the linked list 
void printlinkedlist(node* head)
{
    while(head != NULL)
    {
        cout<<head ->key<<endl;
        head = head->next;
    }
    cout<<endl;
}




