//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    
    Node* reverseList(Node* head) {
        // Edge cases 
        if(head == NULL || head->next == NULL){
            return head;
        }

        Node * temp = NULL;
        Node * curr = head;
        Node * prev = head;

        while(curr != NULL){
            curr = curr -> next;
            prev->next = temp;
            temp = prev;
            prev = curr;
        }

        return temp;

    }
    
    void rearrange(struct Node *odd){
        
        // Edge case
        if(odd->next == NULL){
            return ;
        }
        
        Node * tail1 = odd;
        Node * tail2 = odd->next;
        Node * temp = tail2;
        
        while(tail2 != NULL && tail2->next != NULL){
            tail1->next = tail2->next;
            tail2->next = tail2->next->next;
            tail1 = tail1 -> next;
            tail2 = tail2 -> next;
        }
        
        tail1->next = reverseList(temp);
    
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends