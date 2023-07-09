//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) {
        // Logic by CODE WITH ALISHA YT channel

        for(int i = 0; i < n; i++){
            int element = arr[i];

            if(element >= 1 && element <=n){
                int chair = element - 1; // chair ko if ke baad isliye likha ki agar element -2^31 hota to -1 karke hum integer ki range se bahar chale jaate.
                if(arr[chair] != element){
                    swap(arr[chair],arr[i]);
                    i--;
                }
            }

        }

        for(int i = 0; i < n; i++){
            if(i+1 != arr[i]){ // i+1 isliye kyuki indexing to zero se hi hogi par humne assume kara hai ki 0th pe 1 aayega kyuki that is a smallest +ve number.
                return i+1;
            }
        }
        return n+1; // eg arr ka size 5 jisme element 1 to 5 hai to next +ve smallest number 6 hoga isliye
        
        
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends