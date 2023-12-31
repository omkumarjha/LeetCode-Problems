//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
  
    // To check whether Binary tree is Max heap or not 
    // 1. check if it is complete binary tree .
    // 2. if it is satisfying the MAX heap property .
       
    // Below has 0(n) TC and 0(n) SC as recursive calls.
  
    int countNodes(struct Node * root){
        if(root == NULL) return 0;
        else{
            int left = countNodes(root->left);
            int right = countNodes(root->right);
            
            return (left + right + 1);
        }
    }
    // for this refer my COPY .
    bool isCBT(struct Node * root,int index,int totalNodes){
        if(root == NULL) return true;
        if(index > totalNodes){
            return false;
        }
        else{
            bool left = isCBT(root->left,2*index,totalNodes);
            bool right = isCBT(root->right,2*index+1,totalNodes);
            
            return (left && right);
        }
    }
    
    bool isMaxHeap(struct Node * root){
        // Agar hum yaha pe aaye hai iska matlab Binary tree CBT ko satisfy kar rahi hai . it means below cases ho sakte hai 
        // 1. when both left and right are null 
        // 2. when right child is null
        // 2. when both left and right are non NULL
        
        if(root -> left == NULL && root->right == NULL) return true;
        
        else if(root -> right == NULL){
            return (root->data > root->left->data);
        }
        else{
            // when both left and right child exists 
            bool left = isMaxHeap(root->left);
            bool right = isMaxHeap(root->right);
            
            return (left && right && root->data > root->left->data && root->data > root->right->data);
        }
    }
    
    bool isHeap(struct Node* tree) {
       int totalNodes = countNodes(tree);
       int index = 1; // we are following 1 based indexing
       
       // Agar Binary tree CBT and max heap property dono ko satify kar raha hai it means woh heap hai .
       if(isCBT(tree,index,totalNodes) && isMaxHeap(tree)){
           return true;
       }
       return false; // else woh heap nhi hai .
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
// } Driver Code Ends