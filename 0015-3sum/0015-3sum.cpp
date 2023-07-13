class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        set<vector<int>> st;

        sort(nums.begin(),nums.end());

        for(int i = 0; i < n-2 && nums[i] <= 0; i++){

            int j = i+1 , k = n-1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];

                if(sum == 0){
                    st.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(sum < 0){
                    j++;
                }
                else{
                    k--;
                }
            }

        }

        for(auto triplet : st){
            ans.push_back(triplet);
        }

        return ans;
    }
};