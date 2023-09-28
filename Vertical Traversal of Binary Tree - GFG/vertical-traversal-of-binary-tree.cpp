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

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;
        
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root){
        // isme apne ko vertical order traversal karna hai but hum woh na karke level order traversal hi kar rhe hai and each horizontal distance ki mappimng store karwa rahe hai uske corresponding node ke sath 
        // and kyuki map ke andar keys sorted order mai hote hai to isliye jab hum nodes ko fetch karenge to woh vertical order mai hi aayega 
        // think of the nodes lie on the number line starting from the left to the right and agar hum left mai jayenge to hor dis -1 hoga and right mai + 1 hoga 
        // Follow love babbar TC 0(n) SC 0(n) because har eak node ki mapping ho rahi hai 
        
        
        map<int,vector<int>> nodes;
        queue<pair<Node * , int >> q;
        q.push(make_pair(root,0));
        vector<int> ans;
        
        while(!q.empty()){
            pair<Node * ,int> temp = q.front();
            q.pop();
            
            Node * frontNode = temp.first;
            int hd = temp.second;
            
            nodes[hd].push_back(frontNode->data);
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left,hd-1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,hd+1));
            }
        }
        
        
        for(auto i : nodes){
            for(auto j : i.second){
                ans.push_back(j);
            }
        }
        
        return ans;
        
        
       
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        // string c;
        // getline(cin,c);
        Solution obj;
    	Node* root = buildTree(s);
    	
    	vector <int> res = obj.verticalOrder(root);
    	for (int i : res) cout << i << " ";
        cout << endl;
    }
	return 0;
}



// } Driver Code Ends