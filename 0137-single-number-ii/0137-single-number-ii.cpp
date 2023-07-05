class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = 0 , ans = 0;

        for(int i = 0; i < 32; i++){
            sum = 0;
            for(int j = 0; j < nums.size(); j++){
                if(((nums[j] >> i) & 1) == 1){
                    sum++;
                }
            }
            sum = sum % 3; // kyuki 3 ka group mai se check karna hai woh unique single elem.
            ans = ans | (sum << i);
        }

        return ans;
    }
};