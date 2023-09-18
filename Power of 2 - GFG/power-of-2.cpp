//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
       int start = 0 , end = 62;
       int mid = start + (end - start)/2;
       
       while(start <= end){
           long long val = pow(2,mid);
           if(val == n){
               return true;
           }
           if(val > n){
               end = mid - 1;
           }
           else{
               start = mid + 1;
           }
           mid = start + (end - start)/2;
       }
       
       
       return false;
        
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{

    int t;
    cin>>t;//testcases

    for(int i=0;i<t;i++)
    {
        long long n; //input a number n
        cin>>n;

        Solution ob;
         if(ob.isPowerofTwo(n))//Now, if log2 produces an integer not decimal then we are sure raising 2 to this value
             cout<<"YES"<<endl;
         else
            cout<<"NO"<<endl;

    }

    return 0;
}

// } Driver Code Ends