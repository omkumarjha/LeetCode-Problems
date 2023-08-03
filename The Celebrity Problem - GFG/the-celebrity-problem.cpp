//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:

    // Below approach ki TC 0(n^2) hai
    
    // Main keywords 
    // 1. All people knows celebrity means celebrity ki column ke number of 1s == n-1
    // 2. celebrity does not know anyone at a party , menas celebrity ki row ke number of zeroes == 0

    int celebrity(vector<vector<int> >& M, int n){
        int one = 0 , nonZero = 0;
        
        for(int i = 0; i < n; i++){
            one = 0;
            nonZero = 0; // below loop se mai number of one count karr rha hoon ith column mai
            for(int j = 0; j < n; j++){
                if(M[j][i] == 1){
                    one++;
                }
            }
            // below loop se mai ith row ke number of zeroes count kar raha hoon 
            for(int k = 0; k < n; k++){
                if(M[i][k] == 1){
                    nonZero++;
                }
            }
            
            // condition for celebrity 
            if(one == n-1 && nonZero == 0){
                return i;
            }
            
        }
        
        return -1;
    }

    // Below approach TC 0(n) hai
    
    // int celebrity(vector<vector<int> >& M, int n){  
        
        
        
        
    // }
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
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends