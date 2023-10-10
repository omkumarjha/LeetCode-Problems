//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
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
        if (i >= ip.size())
            break;
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
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  
  Node * createChildToParentMapping(Node * root,int start,map<Node * , Node * > &nodeToParent){
        // We are implementing this using level order traversal
        Node * res = NULL;
        queue<Node * > q;
        q.push(root);

        nodeToParent[root] = NULL;

        while(!q.empty()){
            Node * front = q.front();
            q.pop();

            if(front->data == start){
                res = front;
            }
            if(front->left){
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            if(front->right){
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }

        return res;
    }
    
  
  void infectTree(Node* root, int &minutes,map<Node * , Node * > &nodeToParent){
        map<Node*,bool> visited;
        queue<Node*> q;
        q.push(root);
        visited[root] = true;

        while(!q.empty()){
            int size = q.size(); // for every node hum uske left , right and parent ko check kar rahe hai ki kya usko infect kiya jaa sakta hai agar ha to kar denge and visited ke andar mapping bhih store kar denge and flag ko bhi set kardenge so that we can increse the minutes .
            
            int flag = 0;

            for(int i = 0; i < size; i++){
                Node * front = q.front();
                q.pop();

                if(front->left != NULL && !visited[front->left]){
                    visited[front->left] = true;
                    q.push(front->left);
                    flag = 1;
                }
                if(front->right != NULL && !visited[front->right]){
                    visited[front->right] = true;
                    q.push(front->right);
                    flag = 1;
                }
                if(nodeToParent[front] != NULL && !visited[nodeToParent[front]]){
                    visited[nodeToParent[front]] = true;
                    q.push(nodeToParent[front]);
                    flag = 1;
                }
            }

            if(flag == 1){
                minutes++;
            }
        }
    }
    
    int minTime(Node* root, int target) {
        
        map<Node * , Node*> nodeToParent;
        int minutes = 0;

        Node * startNode = createChildToParentMapping(root,target,nodeToParent); // 1st step
        infectTree(startNode,minutes,nodeToParent);

        return minutes;
        
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends