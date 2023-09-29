//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

vector<int> leftView(struct Node *root);

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

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
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


int main() {
    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        vector<int> vec = leftView(root);
        for(int x : vec)
        cout<<x<<" ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends


/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//below approach mai hum level order traversal karke left view of a binary tree find kar rahe hai 
// TC 0(n) SC - 0(n)
/*
vector<int> leftView(Node *root){
    
    vector<int> ans;
    
    // Edge case
    if(root == NULL){
        return ans;
    }
    
    ans.push_back(root->data);
    queue<Node * > q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        Node * temp = q.front();
        q.pop();
        
        if(temp == NULL){
            if(!q.empty()){
                ans.push_back(q.front()->data);
                q.push(NULL);
            }
        }
        else{
            if(temp -> left){
                q.push(temp->left);
            }
            if(temp -> right){
                q.push(temp->right);
            }
        }
    }
    
    return ans;

}

*/

// Below approach is a recursive algorithm jisse hum left view of a binary tree find karenge. Try to make recursive tree to understand it better
// TC - 0(n) && SC - 0(n)

void solve(Node * root , vector<int> &ans,int level){
    // Base case
    if(root == NULL){
        return ;
    }
    else{
        // agar hum new level pe aa chuke hai it means root -> data ko ans mai dal do . ex initially level 0 pe to ans vector khali hi hoga to uss case mai condition met kar jayegi 
        if(level == ans.size()){
            ans.push_back(root->data);
        }
        solve(root->left,ans,level+1);
        solve(root->right,ans,level+1); // agar uper se niche jaoge to offcource level to bhadega hi .
    }
}

vector<int> leftView(Node *root){
    
    vector<int> ans;
    solve(root,ans,0);
    return ans;
}
