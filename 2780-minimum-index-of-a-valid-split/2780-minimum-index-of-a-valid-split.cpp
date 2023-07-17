class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size();

        // Storing the occurences of element
        for(auto num : nums){
            mp[num]++;
        }

        int dominant = -1;
        // kyuki apne ko pata hai ki nums ke andar eak element dominant to hoga hi to woh domainant element hum pata kar rahe hai .

        for(auto itr : mp){
            if(itr.second > n/2){
                dominant = itr.first;
                break;
            }
        }

        int leftSubarrayIndex = 0;
        int validSplit = -1;

        // i se n-1 tak isliye chalaya loop kyuki question mai bola tha and yeh left and right variables ka matlab kya hai so actually humko question mai de rakha hai ki koi eak index i pe apne ko split krna hai to bas humko to yeh pata hi hai ki kon sa dominant element hai to isliye left variable ke andar hum woh element ki presence kitni hai usko store kar rahe hai and uski madat se right wale mai bhi hum pata kar rahe hai bakki fir freq(x) * 2 > m wala case lagake chaek kar lenge ki kya dono subarrays mai dominant element ki definantion valid follow ho rahi hai ya nhi .

        for(int i = 0; i < n-1; i++){
            if(nums[i] == dominant){
                leftSubarrayIndex++;
            }
            int rightSubarrayIndex = mp[dominant] - leftSubarrayIndex;
            // 1st condition is for left subarray dominancy and second is for right subarrray dominancy 
            if(leftSubarrayIndex * 2 > i+1 && rightSubarrayIndex * 2 > n-i-1){
                validSplit = i;
                break;
            }
        }

        return validSplit;

    }
};