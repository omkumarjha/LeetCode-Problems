//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        /*
        1st approach by using queue
        
        step 1 : fetch first halp of the element from normal queue and push it into the new queue
        step 2 : then jab tak newq empty nhi ho jaata tab tak newQ ke front ko normalq mai push karo and then normalq ke front ko normalq ke andar push karo 
        
        
        queue<int> newq;
        vector<int> ans;
        
        // step 1 : fetching
        
        int halfSize = q.size()/2;
        
        for(int i = 0; i < halfSize; i++){
            int val = q.front();
            q.pop();
            newq.push(val);
        }
        
        // step 2 
        
        while(!newq.empty()){
            int val = newq.front();
            newq.pop();
            q.push(val);
            
            val = q.front();
            q.pop();
            q.push(val);
        }
        
        // coping values from normal queue to our vector array
        
        while(!q.empty()){
            int val = q.front();
            q.pop();
            ans.push_back(val);
        }
        
        return ans;
        
        
        */
        
        // 2nd approach by using stack agar interviewer ne bola hai to otherwise uper wala approach optimized and easy hai iska bhi spaceC 0(n) hoga.
        
        /*
        step 1 : fetch first help from queue and push it into the stack
        step 2 : now stack jab tak empty na hota tab tak queue mai uske top of the element ko push karo 
        step 3 : Abb queue ke first half of the elements ko normal queue ke end mai dalo 
        step 4 : Again normal queue ke first half of the elements ko stack mai dalo .
        step 5 : Now jab tak stack empty na hojaye tab tak pehle to stack ka top normal queue ke andar dalo then normal queue ka front element normal queue ke back mai dl
        */
        
        vector<int> ans;
        stack<int> temp;
        
        int firstHalf = q.size()/2;
        
        // step 1
        for(int i = 0; i < firstHalf; i++){
            temp.push(q.front());
            q.pop();
        }
        
        // step 2
        while(!temp.empty()){
            q.push(temp.top());
            temp.pop();
        }
        
        // step 3 
        for(int i = 0; i < firstHalf; i++){
            q.push(q.front());
            q.pop();
        }
        
        // step 4
         for(int i = 0; i < firstHalf; i++){
            temp.push(q.front());
            q.pop();
        }
        
        // step 5
        
        while(!temp.empty()){
            int val = temp.top();
            temp.pop();
            ans.push_back(val);
            
            val = q.front();
            q.pop();
            ans.push_back(val);
        }
        
        return ans;
      
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends