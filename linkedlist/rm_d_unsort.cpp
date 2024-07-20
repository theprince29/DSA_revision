// Remove duplicate form unsorted list 
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void push(Node** head, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
}

void printList(Node* head)
{
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
void removeduplicate(Node* head)
{
    unordered_set<int>s;
    Node* curr = head;
    Node* prev = NULL;
    
    while(curr != NULL)
    {
        if(s.find(curr->data) != s.end())
        {
            prev->next = curr->next;
            delete(curr);
        }
        else{
            s.insert(curr->data);
            prev=curr;
        }
        curr = prev->next;
    }
}


int main()
{
    Node* head = NULL;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for(int i=0; i<10 ; i++)
    {
        int x = std::rand() % 100 + 1;
        push(&head,x);
        // push(&head,x);
    }
    cout<<"\nUnsorted list with duplicate values"<<endl;
    printList(head);

    removeduplicate(head);
    cout<<"AFTER REMOVING DUPLICATES THE LINKED LIST IS:"<<endl;
    printList(head);
    
    return 0;
}

