//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n){
 
        stack<int> st;
        st.push(-1); // isliye kyuki last element -1 hi hone wala hai 
        vector<int> ans(n);

        for(int i = n-1; i >= 0; i--){
            int curr = arr[i];
    
            // jab tak stack ka top greater hoga curr se tab tak hum while loop chalaenge 
            while(st.top() >= curr){
                st.pop();
            }
    
            // yaha pe abb stack ka top less hi hoga curr element se 
            ans[i] = st.top();
            st.push(curr);
        }
    
        return ans;

    } 
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}


// } Driver Code Ends