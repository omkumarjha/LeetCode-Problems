class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        // One of the approach hai ki 0(n^2) se karo and dono condition agar match ho rahi hai to true return kardo.

        // iss approach mai hum elemeents ki occurence ko map mai store nhi kar rahe hai balki hum element ko uski indeces ke sath map mai store kr rahe hai .

        map<int,int> mp;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            // check ki kya map mai nums[i] already present hai

            if(mp.count(nums[i])){
                // abb check karo ki kya diff wala condition satisfy kar raha hai 
                int j = mp[nums[i]];

                if(abs(i - j) <= k){
                    return true;
                }
            }

            // agar map mai nums[i] present nhi hai to uss case mai nums[i] ko index ke sath map mai dalo 
            mp[nums[i]] = i;
        }


        return false;

    }
}; 