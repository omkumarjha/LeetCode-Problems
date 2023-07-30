class Solution {
public:
    bool isValid(string s) {
        
        // Edge case
        if(s.length() == 1){
            return false;
        }
        
        stack<char> st;

        for(int i = 0; i < s.length(); i++){
            char element = s[i];
            
            if(element == '(' || element == '[' || element == '{'){
                st.push(element);
            }
            else if(element == ')'){
                if(st.empty() == false && st.top() == '('){ 
                    // empty wale ka example ki agar string start hi closing se ho rahi hai it means not valid.
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(element == ']'){
                if(st.empty() == false && st.top() == '['){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(element == '}'){
                if(st.empty() == false && st.top() == '{'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }

        if(st.empty()){  // iska matlab sare brackets correctly open and close hue hai .
            return true;
        }
        return false;  // example "((" to isme to stack empty thodi hoga.
        
    }
};