class Solution {
public:

    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;

        for(int i = 0; i < n-1; i++){
            int diff = 1;
            int count = 0;
            int prev = nums[i];
            for(int j = i+1; j < n; j++){
                if(nums[j] - prev == diff){
                    diff = diff * -1;
                    prev = nums[j];
                    count = max(count,j-i+1);
                }
                else{
                    break;
                }
            }

            maxi = max(maxi,count);
        }

        if(maxi == 0 || maxi == INT_MIN){
            return -1;
        }
        return maxi;
    }
        
};