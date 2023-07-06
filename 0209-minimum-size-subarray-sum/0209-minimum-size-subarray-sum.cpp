class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minimalLength = INT_MAX;
        int i = 0 , j = 0;
        int n = nums.size();
        int sum = 0;
        bool check = false;

        while(j < n){
            sum = sum + nums[j];

            while(j < n && sum >= target){
                sum = sum - nums[i];
                minimalLength = min(minimalLength,j-i+1);
                i++;
            }
            j++;
        }

        if(minimalLength == INT_MAX){
            return 0;
        }
        return minimalLength;
    }
};