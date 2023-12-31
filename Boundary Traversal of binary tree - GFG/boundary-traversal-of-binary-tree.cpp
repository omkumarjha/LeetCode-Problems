//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
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
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    // Love babbar 0(n) and SC - 0(h) where h is the heigth of the tree.
    
    // left part ke nodes ko print karane ke liye except leaf nodes.
    void traversalForLeft(Node * root,vector<int> & ans){
        if(root == NULL || (root->left == NULL && root->right == NULL)){
            return ;
        }
        else{
            ans.push_back(root->data);
            // if else isliye lagaya hai ki jaroori nhi hai ki left nodes ka path straight line jaise hi hoga ho sakta hai ki left nodes ke bad left node exist hi na kare only right node ko to woh data loss we don't want isliye agar left jaana possible nhi hai to right chale jao .
            if(root->left){
                traversalForLeft(root->left,ans);
            }
            else{
                traversalForLeft(root->right,ans);
            }
        }
    }
    
    // To print leaf nodes from left to right .
    void traversalForLeaf(Node * root,vector<int> & ans){
        if(root == NULL){
            return ;
        }
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
            return ;
        }
        traversalForLeaf(root->left,ans);
        traversalForLeaf(root->right,ans);
    }
    
    // Right part ke nodes ko print karane ke liye except leaf nodes .
    void traversalForRight(Node * root,vector<int> & ans){
        if(root == NULL || (root->left == NULL && root->right == NULL)){
            return ;
        }
        else{
            if(root->right){
                traversalForRight(root->right,ans);
            }
            else{
                traversalForRight(root->left,ans);
            }
            // kyuki right part ke nodes ko hume bottom to top print karna hai isiliye jab calls return ho rahi hogi to hum data ko print kar rahe honge.
            ans.push_back(root->data);
        }
    }
    
    
    vector <int> boundary(Node *root){
        
        vector<int> ans;
        
        // Edge case for 0 node.
        if(root == NULL){
            return ans;
        }
        
        // Edge case for 1 node.
        if(root->left == NULL && root -> right == NULL){
            return {root->data};
        }
        
        ans.push_back(root->data); // takki root node ka data 2 baar print na ho isliye usko pehle se hi ans mai push kardiya.
        
        traversalForLeft(root->left,ans);
        traversalForLeaf(root,ans);
        traversalForRight(root->right,ans);
        
        return ans;
    
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends