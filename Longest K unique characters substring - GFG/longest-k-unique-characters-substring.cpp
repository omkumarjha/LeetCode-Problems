//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int unique = 0 , maxi = -1 , n = s.length();
        int arr[26] = {0};
        
        int i = 0 , j = 0;
        
        while(j < n){
            char curr = s[j];
            int diff = curr - 'a';
            
            if(arr[diff] == 0){
                unique++;
            }
            arr[diff] = arr[diff] + 1;
            
            while(unique > k){
                char curr = s[i];
                int diff = curr - 'a';
                arr[diff] = arr[diff] - 1;
                
                if(arr[diff] == 0){
                    unique--;
                }
                i++;
            }
            
            if(unique == k){
                maxi = max(maxi,j-i+1);
            }
            j++;
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends