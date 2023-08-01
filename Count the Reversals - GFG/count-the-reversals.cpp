//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s){
    
    // Logic 
    /*
    1 -> Agar expression ki length odd hai then woh kabhi bhi valid expression bann hi nhi sakta kyuki always ya to koi opening brackets jyada ho jayega ya fir koi eak closing brackets jyada ho jayenge
    2 -> pehla step ke baad string mai jo bhi valid brackets pairs exist kar rahe hai unko hatao string mai se 
    3 -> then if a = number of opening brackets and b = number of closing brackets then to find the minimum number of reversals required to convert the string into a balanced expression we use -> (a+1)/2 + (b+1)/2 forula 
    */
    
    // Odd length expression 
    if(s.length() % 2 == 1){
        return -1;
    }
    else{
        // now sare valid brackets ko remove karna hai 
        stack<char> st;
        
        for(int i = 0; i < s.length(); i++){
            char ch = s[i];
            
            if(ch == '{'){
                st.push(ch);
            }
            else{
                // iska matlab woh closing bracket hai 
                if(!st.empty() && st.top() == '{'){
                    st.pop();
                }
                else{
                    st.push(ch);
                }
            }
        }
        
        // Now a and b calculate karke formula apply karna hai 
        
        int a = 0 , b = 0;
        
        while(!st.empty()){
            char ch = st.top();
            
            if(ch == '{'){
                a++;
            }
            else{
                b++;
            }
            st.pop();
        }
        
        return (a+1)/2 + (b+1)/2;
        
    }
    
}