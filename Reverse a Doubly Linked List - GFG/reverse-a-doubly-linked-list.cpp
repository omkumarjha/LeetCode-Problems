//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};

Node *newNode(int data)
{
    Node *temp=new Node(data);
    
    return temp;
}




void displayList(Node *head)
{
    //Head to Tail
    while(head->next)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<head->data;
    
    
    
}


int getLength(Node * head)
{
    Node *temp=head;
    
    int count=0;
    while(temp->next!=head)
    {
        count++;
        temp=temp->next;
    }
    return count+1;
}




bool verify(Node* head)
{
    int fl=0;
    int bl=0;
    
    Node *temp=head;
    
    while(temp->next)
    {
        temp=temp->next;
        fl++;
    }
    
    while(temp->prev)
    {
        temp=temp->prev;
        bl++;
    }
    
    return fl==bl;
}


// } Driver Code Ends
/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
*/
class Solution
{
    public:
    /*
    Node* reverseDLL(Node * head){
        ///1st way is to alter the data values and reverse thee Doubly linked list
        
        Node * start = head;
        Node * end = head;
        int i = 0 , j = 0;
        
        while(end -> next != NULL){
            end = end -> next;
            j++;
        }
        
        while(i < j){
            swap(start->data,end->data);
            start = start -> next;
            end = end -> prev;
            i++;
            j--;
        }
        
        return head;
        
    }
    */


    // Below approach mai hum links ko change karke kar rahe hai isme hum har eak node ke next ko prev se swap kar rahe hai 
    Node* reverseDLL(Node * head){
        
        // Below approach jab tum curr ko last mai le jaake reverse kar rahe ho .
        
        Node * curr = head;
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        while(curr -> next != NULL){
            curr = curr -> next;
        }
        
        head = curr;
    
        
        while(curr != NULL){
            Node * temp = curr -> next;
            curr -> next = curr -> prev;
            curr -> prev = temp;
            curr = curr -> next;
        }
        
        return head;
        
        
        
        // Below approach jisme humne curr ko head pe hi rakhkar reversing start kardi .
        // Node * curr = head;
        
        // if(head == NULL || head->next == NULL){
        //     return head;
        // }
        
        // while(curr != NULL){
        //     Node * temp = curr -> next;
        //     curr -> next = curr -> prev;
        //     curr -> prev = temp;
        //     curr = curr -> prev;
        // }
        
        // curr = head;
        
        // while(curr -> prev != NULL){
        //     curr = curr -> prev;
        // }
        
        // head = curr;
        
        // return head;
        
    }
};



//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    Node *head=NULL, *tail=NULL;
        int x;
	    cin>>x;
	    head = newNode(x);
	    tail = head;
	    
	    for(int i=0;i<n - 1;i++)
	    {
	        cin>>x;
	        Node* temp=newNode(x);
	        tail->next=temp;
	        temp->prev= tail;
	        tail = temp;
	    }
	    Solution ob;
	    head=ob.reverseDLL(head);
	    
	    
	    if(verify(head))
	    displayList(head);
	    else
	    cout<<"Your pointers are not correctly connected";
 
	    cout<<endl;
	}
	return 0;
}


// } Driver Code Ends