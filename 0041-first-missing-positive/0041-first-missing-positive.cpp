class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // Logic by CODE WITH ALISHA YT channel
        int n = nums.size();

        for(int i = 0; i < n; i++){
            int element = nums[i];

            if(element >= 1 && element <=n){
                int chair = element - 1; // chair ko if ke baad isliye likha ki agar element -2^31 hota to -1 karke hum integer ki range se bahar chale jaate.
                if(nums[chair] != element){
                    swap(nums[chair],nums[i]);
                    i--;
                }
            }

        }

        for(int i = 0; i < n; i++){
            if(i+1 != nums[i]){ // i+1 isliye kyuki indexing to zero se hi hogi par humne assume kara hai ki 0th pe 1 aayega kyuki that is a smallest +ve number.
                return i+1;
            }
        }
        return n+1; // eg arr ka size 5 jisme element 1 to 5 hai to next +ve smallest number 6 hoga isliye
    }
};