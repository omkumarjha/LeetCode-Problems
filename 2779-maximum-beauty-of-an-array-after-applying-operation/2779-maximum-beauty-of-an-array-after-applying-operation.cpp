class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        int maxi = INT_MIN;
        int i = 0 , j = 0;

        while(j < nums.size()){
            if((nums[j] - nums[i]) > 2*k){
                i++;
            }
            else{
                maxi = max(maxi,j-i+1);
            }
             j++;
        }


        return maxi;
    }
};