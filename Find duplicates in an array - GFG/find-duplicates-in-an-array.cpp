//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
         vector<int> ans;
         
         // iss logic se abb chahe 2 element repeat ho ya 10 farak nhi padta .
         // chahye element 10 baar bhi repeat ho jo hum += n kar rahe hai woh eak hi index pe kar rahe hai to finally sirf wahi elemnet hamare ans mai jayega.
        
        for(int i=0; i<n; i++){
            int index = arr[i] % n; // % n isliye kar rahe hai to arr[i] ki original value pe aa paye.
            arr[index]+=n; 
        }
        
        for(int i=0; i<n; i++){
            if(arr[i]/n >= 2)
                ans.push_back(i);
        }
        
        if(ans.size() == 0)
            return {-1};
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends