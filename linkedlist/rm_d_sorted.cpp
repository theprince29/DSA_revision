// removing duplicate form sorted linked list 

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};


void removeduplicate(Node* head)
{
    Node* current = head; //for treversing the linked list 
    Node* next_next;  //for stroing the next pointer of a node be deleted

    if(current == NULL) return;

    while(current->next != NULL)
    {
        if(current->data == current->next->data)
        {
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else{
            current = current->next;
        }
    }

}

void push(Node** headr, int new_data)
{
    Node* new_node = new Node();

    new_node->data = new_data;
    new_node->next = (*headr);
    (*headr) = new_node;
}

void printList(Node* head)
{
    while(head!= NULL)
    {
        cout<<" "<<head->data;
        head=head->next;
    }
}

int main()
{
    Node* head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    push(&head, 40);

    cout<<"\n Linked List before dulicate removal "<<endl;
    printList(head);

    removeduplicate(head);    
    cout<<"\nLinked list after duplicate removal "<<endl;
    printList(head);

    return 0;
}
