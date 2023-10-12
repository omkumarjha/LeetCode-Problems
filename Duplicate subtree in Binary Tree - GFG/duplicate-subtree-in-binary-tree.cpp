//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *left;
	struct Node *right;

	Node(char x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

struct Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node *root = new Node(stoi(ip[0]));

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
/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

class Solution {
  public:
    
    string serializeSubtrees(Node* node, map<string, int>& subtrees) {
        if (node == NULL) return "#"; // Null nodes are represented by '#' . we are using # for the delemeter . because node ka structure same bhi hona chahiye duplicacy ke liye isliye yeh delimeter ko use karne se hum nodes ka structure same aa raha hai ya nhi usko track kar sakte hai . 
        
        if(node -> left == NULL && node -> right == NULL){
            string s = to_string(node->data);
            return s;
        }
        
        string left = serializeSubtrees(node->left, subtrees);
        string right = serializeSubtrees(node->right, subtrees);
        
        string s = left + "," + right + "," + to_string(node->data); // Serialize the current subtree . yaha pe comma laga rahe hai kyuki aaisa bhi ho sakta hai ki nodes ka structure same ho but uss subtree ke data values alag alga place mai ho to usko track rakhne ke liye . 
        
        subtrees[s]++;
        return s;
    }
    
    int dupSub(Node *root) {
        map<string, int> subtrees; // Store serialized subtree and its frequency
        
        serializeSubtrees(root, subtrees); // Traverse the tree and serialize subtrees
        
        for(auto itr : subtrees){
            if(itr.second >= 2){
                return true;
            }
        }
        
        return false;
        
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin >> t;
	//cout << t << "\n";
	while (t--)
	{
		string treeString;
		getline(cin >> ws, treeString);
		struct Node* root = buildTree(treeString);
		Solution ob;
		cout << ob.dupSub(root) << "\n";
	}
	return 0;
}
// } Driver Code Ends