//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
int kthAncestor(Node *root, int k, int node);

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        int k , node;
        scanf("%d ",&k);
        scanf("%d ",&node);
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		cout<<kthAncestor(root,k,node)<<endl;
    }
    return 0;
}

// } Driver Code Ends


//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function
// Approach by OM .
Node * solve(Node * root , int & k , int node){
    if(root == NULL){
        return NULL;
    }    
    else{
        if(root->data == node){
            return root;
        }
        
        Node * leftAns = solve(root->left , k , node);
        Node * rightAns = solve(root->right,k,node);
        
        if(leftAns != NULL && rightAns == NULL){
            k--;
            if(k == 0){
                k = INT_MAX; // to lock our answer so that kabhi bhi again k = 0 na ho and hamara answer successfully return ho jaye
                return root;
            }
            return leftAns;
        }
        else if(leftAns == NULL && rightAns != NULL){
            k--;
            if(k == 0){
                k = INT_MAX;
                return root;
            }
            return rightAns;
        }
        else{
            return NULL;
        }
    }
}

int kthAncestor(Node *root, int k, int node){
    
    Node * temp =  solve(root,k,node);
    
    
    // eak aaisa bhi case hoga jisme root->data hi node ke barabar hoga aur apne ko pata hai ki k 1 ya 1 se to jyada hi hoga matlab hume minimum eak level to uper jaana hi padega but agar root node hi match kar raha ho to uske uper to hum jaa nhi sakte so in that case we have to return -1 .
    if(temp == NULL || temp -> data == node){
        return -1;
    }
    else{
        return temp -> data;
    }
    
}
