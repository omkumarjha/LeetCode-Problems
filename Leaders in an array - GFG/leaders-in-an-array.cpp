//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        
    
        //Approach 1 (brute force): jisme 0(n^2) se hum har eak element check karenge ki kya woh aage ke sare elements se greatter then and equal to hai if yes then wahi leader hoga.
   
        // Below approach 2 (optimized approach) : TC 0(n) and SC 0(n)
        /*
        int maxArr[n];
        vector<int> ans;
        
        maxArr[n-1] = a[n-1];
        
        // Jaise example 1 ke hisab se hum pehle yeh check karenge ki kya 17 leader hai to uske liye agar 17 aur uske aage ke sare element mai se greater sirf 17 hi hai then it means wahi leader hoga. 
        
        for(int i = n-2; i >=0; i--){
            maxArr[i] = max(a[i],maxArr[i+1]);
        }
        
        // Agar koi bhi respective element same mil jaata hai it means wahi element leader hoga.
        for(int i = 0; i < n; i++){
            if(a[i] == maxArr[i]){
                ans.push_back(a[i]);
            }
        }
        
        return ans;
        
        */
        
        // Approach 3 (optimal approach) : TC 0(n) and sc 0(1) space ke liye humne answer vector create kraa hua hai but uske space ko humne add nhi kara hai 
        
        int maxi = INT_MIN;
        vector<int> ans;
        
        // below optimal approach mai bas hum yahi kar rahe hai ki agar eak given element apne right maximum se greater hota hai iska matlab wahi leader hoga.
        for(int i = n-1; i >= 0; i--){
            if(a[i] >= maxi){
                ans.push_back(a[i]);
            }
            maxi = max(maxi,a[i]);
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}

// } Driver Code Ends