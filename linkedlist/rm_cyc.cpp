#include<bits/stdc++.h>
using namespace std;

// linked list 

class Node{
    public:
    int data;
    Node* next;
};


Node* Floydccycle(Node* list)
{   

    if(list == NULL) return NULL;

    Node *slow = list, *fast = list;
    while(slow && fast && fast->next)
    {
        slow  = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {   
            cout<<"\npresent slow fast intersection at"<<slow->data<<endl;
            return slow;
        }
    }
    return NULL;

}


Node* getstartingnodeofcycle(Node* head)
{
    if(head == NULL) return NULL;

    Node* intersection = Floydccycle(head);
    Node* slow = head;
    while(slow != intersection)
    {
        slow = slow ->next;
        intersection = intersection ->next;

    }
    return slow;
}

void removeloop(Node* head)
{
    if(head == NULL) return NULL;
    
    Node* startofloop = getstartingnodeofcycle(head);
    Node* nextnode = startofloop;
    while(nextnode->next)

}




void push(Node** headr , int new_data )
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*headr);
    (*headr) = new_node;
}



void print(Node* head)
{
    while(head !=  nullptr)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}





int main(){
    
    
     Node* head = NULL;
    
    push(&head,90);
    push(&head,90);
    push(&head,90);
    push(&head,90);
    push(&head,90);
    push(&head,90);
    push(&head,90);
    push(&head,90);
    push(&head,90);
    push(&head,90);
    push(&head,90);
    push(&head,90);
    push(&head,90);
    push(&head,90);
    head->next->next->next->next = head;
    
    if (Floydccycle(head))
        cout << "\nPrince, I found a Loop inside the linked list \n";
    else
        cout << "\nThere is no loop inside the linked list";
 
    return 0;
}