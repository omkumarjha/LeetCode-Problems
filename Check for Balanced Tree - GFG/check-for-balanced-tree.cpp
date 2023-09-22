//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

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
/* A binary tree node structure

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

class Solution{
    public:
    // Logic by Love babaar TC 0(n) and SC - only recursive calls.
    // iss pair ka int part yeh define kar raha hai ki curr root node ke left/right ke mai kitne number of nodes hai .
    // koi bhi tree balanced tab hoti hai jab har eak node ke left subarray and right subarray ke nodes hi height ka diff <= 1 ho.
    pair<bool,int> solve(Node * root){
        // base case
        if(root == NULL){
            // agar root null hota hai to tree balanced hoti hai and root == NULL mai to koi node hi nhi hai to uske niche hi height to 0 hi hogi.
            pair<bool,int> p = make_pair(true,0);
            return p;
        }

        pair<bool,int> left = solve(root->left);
        pair<bool,int> right = solve(root->right);

        bool leftAns = left.first;
        bool rightAns = right.first;

        // abb mujhe yeh to check karna hoga na ki root ke niche ka jo tree hai woh balanced hai ki nhi 
        bool diff = abs(left.second-right.second) <= 1;

        // abb kyuki apne ko parent node ko niche se pair<bool,int> dena hai jisme evaluated bool and int value hogi so we have to create it.
        pair<bool,int> ans;
        ans.second = max(left.second,right.second) + 1;

        if(diff && leftAns && rightAns){
            ans.first = true;
        }
        else{
            ans.first = false;
        }

        return ans;

    }
    
    bool isBalanced(Node *root){
         pair<bool,int> p = solve(root);
        return p.first;
    }
};


//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.isBalanced(root) << endl;
    }
    return 0;
}

// } Driver Code Ends