//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    
    void insertAtBottom(stack<int> &s,int element){
        // base case
        if(s.empty()){
            s.push(element);
            return;
        }
        else{
            // current element ko reserve karke bahar nikal do 
            int num = s.top();
            s.pop();
            
            insertAtBottom(s,element);
            
            s.push(num);
        }
        
    }
    
    void Reverse(stack<int> &St){
        // Base case
        if(St.empty()){
            return;
        }
        else{
            // current element ko reserve karke bahar nikal do 
            int num = St.top();
            St.pop();
            // cout<<num<<endl;
            
            // recursive call aage ke elements ko reverse karne ke liye
            Reverse(St);
            
            // Now jaise hamara stack empty ho jaata hai to jo bhi humne element reserve kara tha har call mai usko stack ke bottom mai dalo 
            
            // cout<<num<<endl;
            insertAtBottom(St,num);
        }
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends