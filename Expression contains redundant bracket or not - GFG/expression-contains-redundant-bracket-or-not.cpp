//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // logic agar apne ko koi aaisa bracket ka pair mil jaata hai jaha koi bhi operator nhi hai consume karne ke liye then it means uss expression mai redundant bracket hai 
    // eg ((a+b)) to isme jab pehla closing bracket aaya hoga to woh check karega ki kya opening se pehle koi operator present hai kyuki isme hai to abb hamara stack mai sirf "(" value hai and jab next closing aayega to usko to koi operator milega hi nhi it means expression mai redndant brackets hai 
    int checkRedundancy(string s) {
        
        stack<char> st;
        
        for(int i=0; i < s.length(); i++){
            char currChar = s[i];
            
            if(currChar == '(' || currChar == '+' || currChar == '-' || currChar == '*' || currChar == '/'){
                st.push(currChar);
            }
            else{
                // agar char opening ya koi operator nhi hai to pakka woh koi closing ya letters honge to humko letters se to koi matlab hai nahi isliye hum clossing ka case check kar rahe hai 
                
                if(currChar == ')'){
                    bool isRedundant = true;
                    
                    while(st.top() != '('){
                        char top = st.top();
                        if(top == '+' || top == '-' || top == '*' || top == '/'){
                            isRedundant = false;
                        }
                        st.pop();
                    }
                    
                    if(isRedundant){
                        return true;
                    }
                    st.pop();
                }
            }
        }
        
        return false;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends