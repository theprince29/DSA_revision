// check a linked list is a palindrome using stack

#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

void push(Node** headr, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*headr);
    (*headr) = new_node;
}

// approch 1: to find by using stack
bool Palindrome(Node* head)
{
    Node* slow = head;
    stack<int>s;
    while(slow != NULL)
    {
        s.push(slow ->data);
        slow = slow ->next;
    }
    while (head !=NULL)
    {
        int i = s.top();
        s.pop();
        if(head->data != i)
        {
            return false;
        }
        head = head->next;
    }
    return true;
}


// approch 2: checking the linked is palindrome or not by reversing the linked list 
// Link list node
struct Node {
    char data;
    struct Node* next;
};
 
void reverse(struct Node**);
bool compareLists(struct Node*, struct Node*);
 
// Function to check if given linked list is
// palindrome or not
bool isPalindrome(struct Node* head)
{
    struct Node *slow_ptr = head, *fast_ptr = head;
    struct Node *second_half, *prev_of_slow_ptr = head;
 
    // To handle odd size list
    struct Node* midnode = NULL;
 
    // initialize result
    bool res = true;
 
    if (head != NULL && head->next != NULL) {
 
        // Get the middle of the list. Move slow_ptr by 1
        // and fast_ptr by 2, slow_ptr will have the middle
        // node
        while (fast_ptr != NULL && fast_ptr->next != NULL) {
            fast_ptr = fast_ptr->next->next;
 
            // We need previous of the slow_ptr for
            // linked lists with odd elements
            prev_of_slow_ptr = slow_ptr;
            slow_ptr = slow_ptr->next;
        }
 
        // fast_ptr would become NULL when there
        // are even elements in list. And not NULL
        // for odd elements. We need to skip the
        // middle node for odd case and store it
        // somewhere so that we can restore the
        // original list
        if (fast_ptr != NULL) {
            midnode = slow_ptr;
            slow_ptr = slow_ptr->next;
        }
 
        // Now reverse the second half and
        // compare it with first half
        second_half = slow_ptr;
 
        // NULL terminate first half
        prev_of_slow_ptr->next = NULL;
 
        // Reverse the second half
        reverse(&second_half);
 
        // compare
        res = compareLists(head, second_half);
 
        // Construct the original list back
        reverse(
            &second_half); // Reverse the second half again
 
        // If there was a mid node (odd size case)
        // which was not part of either first half
        // or second half.
        if (midnode != NULL) {
            prev_of_slow_ptr->next = midnode;
            midnode->next = second_half;
        }
        else
            prev_of_slow_ptr->next = second_half;
    }
    return res;
}
 
// Function to reverse the linked list
// Note that this function may change
// the head
void reverse(struct Node** head_ref)
{
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next;
 
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
 
// Function to check if two input
// lists have same data
bool compareLists(struct Node* head1, struct Node* head2)
{
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;
 
    while (temp1 && temp2) {
        if (temp1->data == temp2->data) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
            return 0;
    }
 
    // Both are empty return 1
    if (temp1 == NULL && temp2 == NULL)
        return 1;
 
    // Will reach here when one is NULL
    // and other is not
    return 0;
}
 
// A utility function to print a given linked list
void printList(struct Node* ptr)
{
    while (ptr != NULL) {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL"
         << "\n";
}
 
// **********APPROCH 3: BY recursion checking a linked list is palindrome or not: =================================
bool ispalindromic(Node** left, Node* right) {
    if (right == NULL)
        return true;

    bool isp = ispalindromic(left, right->next);
    if (isp == false)
        return false;

    bool isp1 = (right->data == (*left)->data);
    *left = (*left)->next;

    return isp1;
}

bool ispalindrom(Node* head) {
    return ispalindromic(&head, head);   
}
// =====================================================================================================
int main() {
    // Write C++ code here
    Node* head = NULL;
    push(&head,20);
    push(&head,20);
    push(&head,10);
    push(&head,20);
    push(&head,20);
    push(&head,20);
    push(&head,20);
    push(&head,20);
    push(&head,20);
    push(&head,10);
    push(&head,20);
    push(&head,20);
    // head->next->next->next->next->next = head;
        
        if(Palindrome(head))
        {
            cout<<"Prince, Your linked list is a palindrome ";
        }
        else
        {
            cout<<"Prince your linked list is not a palindrome";
        }
        
    return 0;
}
