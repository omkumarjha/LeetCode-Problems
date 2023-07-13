class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(),nums.end());  Hum yeh STL function ka use karke bhi kar sakte hai .

        // Optimized approach By Take U Forward YT

        // Next permutation means nums se slighly greater value 
        /*
            find the first adacent pair from right side where left is smaller than right
            if you dont find such a pair, reverse the whole array
            swap the left element in the pair with the smallest element greater than that to its right
            then reverse the sub array from the point of swap(after the left element in the pair) till the end
        */
        int n = nums.size();
        int index = -1;

        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }
        if(index == -1){
            reverse(nums.begin(),nums.end());
            return ;
        }
        
        for(int i = n-1; i > index; i--){
            if(nums[i] > nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }

        reverse(nums.begin()+index+1,nums.end());

    }
};