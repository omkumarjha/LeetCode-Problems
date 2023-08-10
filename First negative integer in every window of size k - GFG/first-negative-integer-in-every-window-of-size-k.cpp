//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {
    
        // Below approach mai hum window by window search kar rahe hai par iski worst case mai TC 0(n*2) ho sakti hai so we hae to optimize this.
        /*
        vector<long long> ans;
        
        for(int i = 0; i <= (N-K); i++){
            int isNegative = false;
            
            for(int j = i; j <= (i+K-1); j++){
                if(A[j] < 0){
                    ans.push_back(A[j]);
                    isNegative = true;
                    break;
                }
            }
            
            if(!isNegative){
                ans.push_back(0);
            }
        }
        */
        
        // Optimized approach by Love Babbar isme hum pehli k size ke window ko process karke first -ve integer ans mai dal denge and next mai aage ke windows ko process karenge 
        
        vector<long long> ans;
        deque<int> dq;
        
        // pehli window ko process karo 
        
        for(int i = 0; i < K; i++){
            if(A[i] < 0){
                dq.push_back(i);
            }
        }
        
        if(dq.size() > 0){
            ans.push_back(A[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
        
        // Abb aage ke windows ko process karo 
        
        for(int i = K; i < N; i++){
            // Remove karo dq ka front agar woh curr window mai lie nhi kar raha to understand (i-.front) >= k refer example 1 with k = 3 .
            
            if(!dq.empty() && (i-dq.front()) >= K){ // agar yeh formula true hota hai iska matlab dq ka front curr window mai lie nhi kar raha 
                dq.pop_front();
            }
            
            // abb curr element ko check karenge 
            
            if(A[i] < 0){
                dq.push_back(i);
            }
            
            // Now ans mai -ve integer dalo 
            
            if(dq.size() > 0){
                ans.push_back(A[dq.front()]);
            }
            else{
                ans.push_back(0);
            }
            
        }
        
        
        return ans;
 }