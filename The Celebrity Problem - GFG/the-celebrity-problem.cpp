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

    /*
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
    */

    // Below approach TC 0(n) ka hai and it uses stack 
    
    bool knows(vector<vector<int> >& M, int a, int b, int n) {
        if(M[a][b] == 1)
            return true;
        else
            return false;
    }

    int celebrity(vector<vector<int> >& M, int n) {
        
        stack<int> s;
        //step1: push all element in stack
        for(int i=0; i<n; i++) {
            s.push(i);
        }   
        
        //step2: get 2 elements at a time and compare them
        
        while(s.size() > 1) {
            
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(knows(M,a,b,n)){ // a agar b ko janta hai means a to celebrity hoga nhi 
                s.push(b);
            }
            else if(knows(M,b,a,n)){  // aaisa bhi case ho sakta hai jisme a and b koi eak doosre ko naa jaane.but hum still eak element ko push karte chal rahe hai takki last mai stack ke andar eak single element bache and uski madat se hum -1 return kar payenge 
                s.push(a);
            }
        }
        if(s.size() != 1){
            return -1;
        }
        
        int ans = s.top();
        //step3: single element in stack is potential celebrity 
        //so verify it
        
        int zeroCount = 0;
        
        for(int i=0; i<n; i++) {
            if(M[ans][i] == 0)
                zeroCount++;
        }
        
        //all zeroes
        if(zeroCount != n)
            return -1;
        
        //column check
        int oneCount = 0;
        
        for(int i=0; i<n; i++) {
            if(M[i][ans] == 1)
                oneCount++;
        }
        
        if(oneCount != n-1)
            return -1;
        
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