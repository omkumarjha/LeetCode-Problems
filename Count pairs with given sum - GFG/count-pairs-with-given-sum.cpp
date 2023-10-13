//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    // Approach by code library YT TC - 0(n) and Sc 0(n);
    
    int getPairsCount(int arr[], int n, int k){
        map<int,int> freq;
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            int remaining = k - arr[i];
            
            // Now check ki iss remaining ke corresponding map mai koi entry hai ya nhi 
            if(freq[remaining]){
                ans += freq[remaining]; // refer example 2 for this jo last wala 1 hai woh uske pichle 3 se map hokar k banayega isliye humne count mai uss case mai 3 add kara tha.
            }
            
            // chahe remaining element ki freq present ho ya na ho map ke andar curr element ki to freq add hogi map mai.
            freq[arr[i]]++;
        }
        
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends