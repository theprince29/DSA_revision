// doublely linked list in cpp data structure 
#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;
};

// insertion at beginning 
void push_be(Node** headr,int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*headr);
    new_node->prev = NULL;
    
    if((*headr) != NULL)
    (*headr)->prev = new_node ;
    (*headr)=new_node; // moving head to new head node
}





int main()
{



    return 0;
}