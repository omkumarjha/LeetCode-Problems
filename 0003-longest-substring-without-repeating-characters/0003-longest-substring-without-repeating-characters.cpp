class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<int> st;
        int n = s.length();
        st.insert(s[0]);
        int i = 0 , j = 1;
        int maxi = INT_MIN;

        // EDGE CASE 
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }

        while(j < n){
            char element = s[j];

            if(st.count(element)){
                while(i < j){
                    if(s[i] == s[j]){
                        i++;
                        break;
                    }
                    else{
                        st.erase(s[i]);
                        i++;
                    }
                }
            }

            st.insert(element);
            maxi = max(maxi,j-i+1);
            j++;
        }

        return maxi;

    }
};