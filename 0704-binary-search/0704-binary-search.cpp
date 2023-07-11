class Solution {
public:
    int binarySearch(vector<int> nums,int target){
        int n = nums.size();
        int start = 0 , end = n - 1;
        int mid = start + (end - start)/2;

        while(start <= end){
            if(nums[mid] == target){
                return mid;
            }
            if(target > nums[mid]){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
            mid = start + (end - start)/2;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return binarySearch(nums,target);
    }
};