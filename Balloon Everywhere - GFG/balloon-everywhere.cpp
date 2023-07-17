//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        int arr[26] = {0};
        int count = 0;
        
        // below mai just occurence store kar waya hai baloon ke characters ka array ke andar 
        for(int i = 0; i < s.length(); i++){
            
            if(s[i] == 'b' || s[i] == 'a' || s[i] == 'l' || s[i] == 'o'|| s[i] == 'n'){
                int diff = s[i] - 'a';
                arr[diff] = arr[diff] + 1;
            }
            
        }
        
        // below mai bas yahi hai ki jaise l hai woh 2 ho sakta hai magar 2 se kam nhi to agar koi bhi eak condition fail ho jaati hai to bas wahi tak hum balloon ke possible instances form kar sakte hai . to understand go to GFG weekly contest 111 YT>
        while(arr[1] > 0 && arr[0] > 0 && arr[11] > 1 && arr[14] > 1 && arr[13] > 0){
            count++;
            arr[1]--;
            arr[0]--;
            arr[11]-=2;
            arr[14]-=2;
            arr[13]--;
        }
        
        return count;
        
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends