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

void printList(Node* head)
{
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
// Function to insert a node at the beginning of the list
 int decimalValue(Node *head)
        {
           stack<bool>st;
           // Your Code Here
           if(head == NULL) return 0 ;
           while(head !=NULL)
           {
               st.push((head->data));
               head = head ->next;
           }
           int ans=0;
           int k =0;
           while(!st.empty())
           {
               ans += st.top()*pow(2,k);
               st.pop();
               k++;
           }
           return ans;
        }
int main() {
    // Write C++ code here
    Node* head = NULL;
    push(&head,1);
    push(&head,1);

    push(&head,0);
    push(&head,1);
   
   cout<<"binary to decimal "<<endl;
    printList(head);
    cout << "Decimal value is: " << decimalValue(head) << endl;

    return 0;
 }
