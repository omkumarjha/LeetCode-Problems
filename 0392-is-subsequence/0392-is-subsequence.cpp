class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0 , j = 0 , index = 0;
        // Logic Made by ME

        while(i < s.length() && j < t.length()){
            if(s[i] == t[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }

        if(i >= s.length()){ // Agar length barabar hoti hai means humne s ko poora traverse kar liya to return true
            return true;
        }
        return false;
    }
};