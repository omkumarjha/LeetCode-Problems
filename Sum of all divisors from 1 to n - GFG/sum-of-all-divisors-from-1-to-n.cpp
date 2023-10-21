//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long sumOfDivisors(int N){
        // Below approach is taking o(n^2) TC 
        
        // long long ans = 0;
        
        // for(int i = N; i >= 1; i--){
        //     for(int j = i; j >= 1; j -= j/2){
        //         if(i % j == 0){
        //             ans += j;
        //         }
        //     }
        // }
        
        // return ans;
        
        // Below approach is by 'Real and Imaginory' YT channel TC - 0(n) and SC - 0(1)
        
        long long ans = 0;
        
        for(int i = 1; i <= N; i++){
            if(N % i == 0){
                ans += N; // To iss case mai N ans mai pura contribution dega
            }
            else{
                ans += i *(N/i); // eg 6 ko 5 completely divide nhi kar sakta so in this case we will store 5 * (6/5) = 5.
            }
        }
        
        return ans;
        
        
    
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        long long ans  = ob.sumOfDivisors(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends