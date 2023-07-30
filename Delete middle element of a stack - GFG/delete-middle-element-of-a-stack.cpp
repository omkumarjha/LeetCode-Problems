//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    /*
    void deleteMid(stack<int>&s, int sizeOfStack){
        // iss approach mai basically humne middle element se uper ke sare element doosre stack mai dale then middle ko hataya then fir temp ke elements   ko one by one original stack mai dala 
        // Yeh extra space le raha hai 
        int count = floor(s.size()/2);
        
        stack<int> temp ;
        
        while(count--){
            temp.push(s.top());
            s.pop();
        }
        
        s.pop(); // yeh middle element ko pop out lkar dega
        
        while(!temp.empty()){
            s.push(temp.top());
            temp.pop();
        }
        
    }
    */
    
    // Below approach recursion ka use karke 0(1) space mai question ko solve kar rah hai .
    void solve(stack<int> &s,int count,int size){
        // sare ke sare function call stack ki same value ko share karte hai .
        
        // base case
        if(count == size/2){
            s.pop(); // yeh middle element ko pop out karega
            return;
        }
        else{
            int num = s.top();
            s.pop();
            
            // Aage ke liye recursive call
            solve(s,count+1,size);

            s.push(num);
        }
        
    }
    
    void deleteMid(stack<int>&s, int sizeOfStack){
        int count = 0;
        
        solve(s,count,sizeOfStack);
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends