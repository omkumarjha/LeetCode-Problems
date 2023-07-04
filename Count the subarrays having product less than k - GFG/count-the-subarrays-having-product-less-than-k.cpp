//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    // Approach 1 jisme sare possible continguos sub arrays ke product find karke check karenge 
    
    // bool isValid(const vector<int>& a, int i,int j, long long k){
    //     long long int prod = 1;
        
    //     for(int k = i; k <= j; k++){
    //         prod = prod * a[k];
    //     }
        
    //     return prod < k;
    // }
    
    // int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        
    //     int count = 0;
        
    //     for(int i = 0; i < a.size(); i++){
    //         for(int j = i; j < a.size(); j++){
    //             if(isValid(a,i,j,k)){
    //                 count++;
    //             }
    //         }
    //     }
        
    //     return count;
    // }
    
    
    // Approach 2 Sliding window approach by Engineering Brains
    
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        
        int count = 0 ;
        long long int product = 1;
        int start = 0 , end = 0;
        
        while(end < n){
            product = product * a[end];
            
            if(product >= k){
                while(start < end && product >= k){
                    product = product / a[start];
                    start++;
                }
            }
            if(product < k){
                int length = (end - start) + 1;
                count = count + length;
            }
            end++;
            
        }
        
        return count;
        
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends