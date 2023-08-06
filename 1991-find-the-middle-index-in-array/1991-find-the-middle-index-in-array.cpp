class Solution {
public:
    int sumOfArray(vector<int> nums){
        int n = nums.size();
        int sum = 0;

        for(int i= 0; i < n; i++){
            sum += nums[i];
        }
        return sum;
    }

    int findMiddleIndex(vector<int>& nums) {
         int n = nums.size();
        int leftSum = 0 , rightSum = 0;

        // Edge case
        if(n == 1){
            return 0;
        }

        int sum = sumOfArray(nums);

        for(int i = 0; i < n; i++){
            if(i == 0){
                leftSum = 0;
            }
            else{
                leftSum += nums[i-1];
            }

            if(i == n-1){
                rightSum = 0;
            }
            else{
                rightSum = sum - (nums[i] + leftSum);
            }
            if(leftSum == rightSum){
                return i;
            }
        }

        return -1;
    }
};