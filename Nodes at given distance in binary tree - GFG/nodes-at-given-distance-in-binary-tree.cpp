//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

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
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:
    
    vector <int> KDistanceNodes(Node* root, int target , int k){
        
        queue<Node*> q;
        unordered_map<Node*,Node*> parent;
        q.push(root);
        Node * targetNode = NULL;
        
        // To store the mapping for every child node to its parent node.
        while(!q.empty()){
            Node*front=q.front();
            q.pop();
            
            if(front != NULL && front->data == target){
                targetNode = front;
            }
            
            if(front->left){
                parent[front->left] = front;
                q.push(front->left);
            }
            if(front->right){
                parent[front->right] = front;
                q.push(front->right);
            }
        }

        unordered_map<Node*,bool> visited;
        q.push(targetNode);
        visited[targetNode]=true;
        int cnt=0;
        while(!q.empty()){
            if(cnt==k) break;
            cnt++;
            int size=q.size();
            for(int i=0;i<size;i++){
                Node*front=q.front();
                q.pop();
                if(front->left  &&  !visited[front->left]){
                    q.push(front->left);
                    visited[front->left]=true;
                }
                if(front->right  &&  !visited[front->right]){
                    q.push(front->right);
                    visited[front->right]=true;
                }
                if(parent[front]  &&  !visited[ parent[front] ]){
                    q.push( parent[front] );
                    visited[parent[front]]=true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            Node*front=q.front();
            q.pop();
            ans.push_back( front->data );
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
        
    
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends