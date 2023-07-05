class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0 , maxLength = 0 , countZero = 0;
        int n = nums.size();

        for(int j = 0; j < n; j++){
            if(nums[j] == 0){
                countZero++;
            }
            while(countZero > 1){
                if(nums[i] == 0){
                    countZero--;
                }
                i++;
            }
            maxLength = max(maxLength , j-i);
        }
        return maxLength;
    }
    
};