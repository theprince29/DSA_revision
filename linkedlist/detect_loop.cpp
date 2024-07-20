// detect loop in linked list 

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    int flag;
};


void push(Node** headr, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*headr);
    new_node->flag = 0;
    (*headr) = new_node;
}


// approch 1: Using flag for remembering the visited node, Some modification in Node Class; Time:O(n) and Space: O(n)
bool detectcycle(Node* head)
{
    while(head != NULL)
    {
        if(head->flag ==1)
        {
            return true;
        }
        head->flag = 1;
        head = head ->next;
    }
    return false;
}
// approch 2: Without modifing the node structure, Marking visited node


// approch 3: Using hashing time O(n) and space O(n)
bool detectloop(Node* head)
{
    unordered_set<Node*> s;
    
    while(head !=NULL)
    {
        if(s.find(head)!=s.end())
        {
            return true;
        }
        s.insert(head);
        head = head ->next;
    }
    return false;
}

// approch 4: Floyd's Cycle find algorithm  Time: O(n) and space:O(1)
bool Floydccycle(Node* list)
{
    Node *slow = list, *fast = list;
    while(slow && fast && fast->next)
    {
        slow  = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            return true;
        }
    }
    return false;
}



int main()
{
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
        cout << "Prince, I found a Loop inside the linked list";
    else
        cout << "There is no loop inside the linked list";
 
    return 0;
}

