//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


// } Driver Code Ends
//User function Template for C++
/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */

class Solution {
  public:
  // TC - 0(n) and SC - 0(h)
    void solve(Node * root,vector<int> &ans){
        queue<Node *> q;
        q.push(root);
        q.push(NULL);
        int maxi = INT_MIN;

        while(!q.empty()){
            Node * front = q.front();
            q.pop();

            if(front == NULL){ // Means tumhara eak level complete ho chuka hai to uss level ka max value ans mai dalo
                ans.push_back(maxi);
                maxi = INT_MIN;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                maxi = max(maxi,front->data);
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
        }
    }
    vector<int> maximumValue(Node* node) {
        vector<int> ans;
        if(node == NULL){
            return {};
        }
        if(node -> left == NULL && node -> right == NULL){
            return {node->data};
        }
        solve(node,ans);

        return ans;
    }
};

//{ Driver Code Starts.

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
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
/* Function to get Largest value at each level of Binary Tree */
vector<int> maximumValue(struct Node* tree);


int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector<int> answer = ob.maximumValue(root);
        for(auto i:answer)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends