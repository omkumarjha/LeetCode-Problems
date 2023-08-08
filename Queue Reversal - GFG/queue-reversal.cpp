//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//function Template for C++

//Function to reverse the queue.
class Solution
{
    public:
    
    void reverse(queue<int> &q){
        if(q.empty()){
            return;
        }
        
        int num = q.front();
        q.pop();
        
        reverse(q);
        
        q.push(num);
    }
    
    queue<int> rev(queue<int> q){
        
        // 1st approach using array otherwise stack se bhi kar sakte hai 
        /*
        queue<int> ans;
        int n = q.size();
        
        int arr[n];
        
        for(int i = n-1; i >=0; i--){
            arr[i] = q.front();
            q.pop();
        }
        
        for(int i = 0; i < n; i++){
            ans.push(arr[i]);
        }
        
        return ans;
        */
        
        // 2nd approach using recursion 
        
        reverse(q);
        
        return q;
    }
};


//{ Driver Code Starts.
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    Solution ob;
    queue<int> a=ob.rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}
// } Driver Code Ends