//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
// Function to Build Tree
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


// } Driver Code Ends
/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution
{
    public:
    // Question solved by Om just by refering few hints.
    int solve(Node * root , bool & isSum){
        if(root == NULL){ // Base case
            return 0;
        }
        
        int leftSum = solve(root->left,isSum);
        // agar hum leaf node pe hai to just uski value uper bhej do . isme hume kuch check nhi karna ya koi right ke liye call nhi marni .
        if(root->left == NULL && root->right == NULL){
            return root->data;
        }
        
        int rightSum = solve(root->right,isSum);
        
        // kyuki question mai bol rakha hai for every node x hume left sum and right sum ko root->data se compare karna hai to agar kisi eak case mai bhi equal nhi aata hai to tree sum tree nhi hogi.
        if((leftSum + rightSum) != root->data){
            isSum = false;
        }
        
        return (leftSum + rightSum + root->data);
    }
    
    bool isSumTree(Node* root){
        
        // Edge cases as given in the statement.
        if((root == NULL) || (root->left == NULL && root->right == NULL)){
            return true;
        }
        
        // initially humne tree ko sum tree assume karliya.
        bool isSum = true;
        solve(root,isSum);
        
        return isSum;
        
        
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        Solution ob;
        cout <<ob.isSumTree(root) << endl;
    }
    return 1;
}
// } Driver Code Ends