class Solution {
public:
    void findSubsets(vector<int>& nums,vector<vector<int>>& ans,vector<int> output,int index){
        if(index >= nums.size()){
            ans.push_back(output);
            return;
        }
        else{
            // Exclude element at index i
            findSubsets(nums,ans,output,index+1);

            // Include element at index i
            int element = nums[index];
            output.push_back(element);
            findSubsets(nums,ans,output,index+1);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans; // iske andar hum subsets ke set ko contain kar rahe honge
        vector<int> output;
        int index = 0;

        findSubsets(nums,ans,output,index);
        return ans;
    }
};