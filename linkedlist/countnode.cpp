// find the length of linked list 
// approch 1: iterative approch 

#include<bits/stdc++.h>
using namespace std;

class Node 
{
    public:
    int data;
    Node* next;
};

void push(Node** headr,int new_data)
{
    Node* new_node = new Node();
    new_node->data=new_data;
    new_node->next=(*headr);
    (*headr)=new_node;
}
// iterative method
int getcount(Node* head)   //takes O(n)
{
    int count =0;
    Node* curr = head;
    while(curr != NULL)
    {
        count++;
        curr =curr->next;
    }

    return count;
}

// approch 2: recurcive methode
int getCount(Node* head)   //takes O(n) time and space O(n)
{
    if(head == NULL)
    {
        return 0;
    }

    return 1+getCount(head->next);
}
// approch 3: recurcive methode
int getCount(Node* head,int count = 0)   //takes O(n) time and space O(1)
{
    if(head == NULL)
    {
        return count;
    }

    return getCount(head->next,count+1);
}

int main()
{
    Node* head;

    push(&head,9);
    push(&head,9);
    push(&head,9);
    push(&head,9);
    push(&head,9);
    push(&head,9);
    push(&head,9);
    push(&head,9);
    push(&head,9);
    push(&head,9);

    cout<<"number of in linked list is : "<<getcount(head)<<endl;



    return 0 ;
}


