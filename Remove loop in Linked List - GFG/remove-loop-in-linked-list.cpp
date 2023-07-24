//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

bool notOriginal(Node *head, unordered_map<Node *, int>&myMap){
    
    while(head){
        if(myMap.find(head)==myMap.end()) return true;
        if(myMap[head] != (head->data)) return true;
        
        head=head->next;
    }
}




// } Driver Code Ends
/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    // Below approach is "Floyd’s Cycle-Finding Algorithm"
    
     Node * hasCycle(Node *head){
        if(head==NULL || head->next==NULL)
            return NULL;
  
        Node* slow=head;
        Node* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)
                return slow;
        }
        return NULL;
    }
    
    // Logic to solve the delectCycle function
        /*
            1. using floyd's cycle detection algorithm find the node where fast and slow pointer met
            2. then slow pointer ko head pe rakho
            3. then slow pointer and intersection pointer ko eak - eak step aage bhadate rakho.
            4. agar intersection node and slow pointer met kar jaate hai it means there is cycle ortherwise not.
    */
        

    Node *detectCycle(Node *head) {
      
        Node * intersection = hasCycle(head);
        Node * slow = head;

        if(intersection == NULL){
            return NULL;
        }
        else{
            while(slow != intersection ){
                slow = slow -> next;
                intersection = intersection -> next;
            }
        }

        return slow;

    }
    
    // Abb kyuki apne ko cycle ka beginning mil gaya hai to hum ussi ko use karke aage check karenge ki kya hum uss beginning wale node mai fir se to nhi aa gaye agar ha iska matlab woh last node hai cycle ka to usse null se point out kara do cycle remove karwane ke liye
    
    void removeLoop(Node* head){
        
        Node * startOfCycle = detectCycle(head);
        
        if(startOfCycle == NULL){
            return;
        }
        
        Node * temp = startOfCycle;
        
        while(temp -> next != startOfCycle){
            temp = temp -> next;
        }
        
        temp -> next = NULL;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        unordered_map<Node *, int>myMap;
        
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        myMap[head]=num;
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
            myMap[tail]=num;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        ob.removeLoop(head);
        
        if( isLoop(head) || length(head)!=n || notOriginal(head, myMap))
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}

// } Driver Code Ends