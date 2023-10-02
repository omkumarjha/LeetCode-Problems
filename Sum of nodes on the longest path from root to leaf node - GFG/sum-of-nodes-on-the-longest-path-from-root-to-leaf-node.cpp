//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    // maxi and maxlength ko by reference isliye pass kara hai takki agar kisi eak call stack mai inki value update hoti hai to wahi value kisi doosre call stack mai bhi rahe .
    
    void solve(Node * root , int & maxi,int sum,int & maxLen , int len){
        if(root == NULL){
            return ;
        }
        else{
            sum += root -> data;
            len++;
            
            solve(root->left,maxi,sum,maxLen,len);
            solve(root->right,maxi,sum,maxLen,len);
            
            // Below ke if else tabhi chalenge jab we are in leaf node.
            if((root->left == NULL && root->right == NULL ) && len > maxLen){
                maxLen = len;
                maxi = sum;
            }
            else if((root->left == NULL && root->right == NULL ) && len == maxLen){
                maxi = max(sum,maxi);
            }
            
            // jab calls return ho rahi hogi to nodes ka sum and number of nodes ka count minus karte chalna hai .
            sum -= root->data; // yeh do steps optional hai kyuki har eak call stack mai inki value already differ kar rahi hogi
            len--;
        }
    }
    
    int sumOfLongRootToLeafPath(Node *root){
        
        int maxi = INT_MIN , sum = 0 , maxLen = INT_MIN , len = 0;
        solve(root,maxi,sum,maxLen,len);
        
        return maxi;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    scanf("%d", &t);
    cin.ignore();
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution obj;
        int res = obj.sumOfLongRootToLeafPath(root);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends