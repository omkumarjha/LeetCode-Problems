//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    
    int leftMostOccurenceOfX(int arr[],int n,int x){
        int ans = -1;
        
        int start = 0 , end = n-1 , mid = start + (end - start)/2;
        
        while(start <= end){
            if(arr[mid] == x){
                ans = mid;
                end = mid - 1;
            }
            else if(arr[mid] > x){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
            mid = start + (end - start)/2;
        }
        return ans;
    }
    
    int rightMostOccurenceOfX(int arr[],int n,int x){
        int ans = -1;
        
        int start = 0 , end = n-1 , mid = start + (end - start)/2;
        
        while(start <= end){
            if(arr[mid] == x){
                ans = mid;
                start = mid + 1;
            }
            else if(arr[mid] > x){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
            mid = start + (end - start)/2;
        }
        return ans;
    }
    
    
	int count(int arr[], int n, int x) {
	    int len1 = leftMostOccurenceOfX(arr,n,x);
	    int len2 = rightMostOccurenceOfX(arr,n,x);
	    
	    if(len1 == -1 && len2 == -1){
	        return 0;
	    }
	    return (len2-len1) + 1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends