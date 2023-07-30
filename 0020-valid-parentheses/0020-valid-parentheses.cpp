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

        if(st.empty()){
            return true;
        }
        return false;
        
    }
};