//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.

    // Inorder array ke har eak element ki mapping uske index se kardi .
void createMapping(int inorder[],int n,map<int,int> &nodeToIndex){
    for(int i = 0; i < n; i++){
        nodeToIndex[inorder[i]] = i;
    }
}
    
Node * solve(int * postorder,int * inorder,int & postorderIndex,int inorderStart,int inorderEnd,int n,map<int,int> &nodeToIndex){
        // base case
        if(postorderIndex < 0 || inorderStart > inorderEnd){
            return NULL;
        }
        else{
            int element = postorder[postorderIndex--];
            Node * root = new Node(element);
            int pos = nodeToIndex[element];

            // Reccursive call for left and right part 
            // kyuki hum tree construct kar rahe hai isliye root -> left ya root -> right karrahe hai otherwise for normal accessing the elemnet we can neglect that.
            
            root->right = solve(postorder,inorder,postorderIndex,pos+1,inorderEnd,n,nodeToIndex);
            root->left = solve(postorder,inorder,postorderIndex,inorderStart,pos-1,n,nodeToIndex);

            return root;
        }
}
    
    
Node *buildTree(int in[], int post[], int n) {
        map<int,int> nodeToIndex;
        createMapping(in,n,nodeToIndex);

        int postorderIndex = n-1;
        return solve(post,in,postorderIndex,0,n-1,n,nodeToIndex);
}
