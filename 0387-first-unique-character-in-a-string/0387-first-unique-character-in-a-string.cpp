class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26] = {0};
       
       for(int i = 0; i < s.length(); i++){
           int diff = s[i] - 'a';
           arr[diff] = arr[diff] + 1;
       }
       
       for(int i = 0; i < s.length(); i++){
           int diff = s[i] - 'a';
           if(arr[diff] == 1){
               return i;
           }
       }
       
       
       return -1;
    }
};