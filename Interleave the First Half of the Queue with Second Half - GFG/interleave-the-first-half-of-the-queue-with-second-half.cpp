//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        /*
        1st approach by using queue
        
        step 1 : fetch first halp of the element from normal queue and push it into the new queue
        step 2 : then jab tak newq empty nhi ho jaata tab tak newQ ke front ko normalq mai push karo and then normalq ke front ko normalq ke andar push karo 
        
        
        */
        
        queue<int> newq;
        vector<int> ans;
        
        // step 1 : fetching
        
        int halfSize = q.size()/2;
        
        for(int i = 0; i < halfSize; i++){
            int val = q.front();
            q.pop();
            newq.push(val);
        }
        
        // step 2 
        
        while(!newq.empty()){
            int val = newq.front();
            newq.pop();
            q.push(val);
            
            val = q.front();
            q.pop();
            q.push(val);
        }
        
        coping value
        while(!q.empty()){
            int val = q.front();
            q.pop();
            ans.push_back(val);
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends