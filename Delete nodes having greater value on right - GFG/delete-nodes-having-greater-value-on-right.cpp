//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends

class Solution
{
    public:
    // Iss question mai wahi hai ki left to right jayenge to hume 0(n^2) type comparisons karne padenge so its better ki hum right to left jaye jisse hum direct curr element ko right side ke max data se compare kar payenge aur conclude kar payenge ki curr node ko answer mai rakhna hai ya nhi 
    
    Node * reverse(Node * head){
        
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
    
    Node *compute(Node *head){
        
        head = reverse(head);
        
        Node * curr = head;
        int max = head-> data;
        Node * prev = head;
        head = head -> next;
         
        while(head != NULL){
            if(head -> data >= max){
                max = head -> data;
                prev = head;
            }
            else{
                prev -> next = head -> next;
            }
            head = head -> next;
        }
        
        
        head = reverse(curr);
        
        return head;
    
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends