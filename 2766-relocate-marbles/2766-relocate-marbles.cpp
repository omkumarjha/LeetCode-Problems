class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        vector<int> ans;
        map<int,int> mp;

        // Stored occurences of the positions
        for(auto num : nums){
            mp[num]++;
        }

        for(int i = 0; i < moveFrom.size(); i++){
            int startPos = moveFrom[i];
            int endPos = moveTo[i];

            // agar dono positions same hai iska matlab internally unko unhi position mai move kardo jo ki required nhi hai.
            if(startPos == endPos){
                continue;
            }

            mp[endPos] = mp[endPos] + mp[startPos]; // yaha pe hmne eak nyi entry create kardi and usme previous value ko store kardiya 
            mp[startPos] = 0; // finally jab kaam ho gyaa to previus key pe jo value thi usko 0 kardiya.
        }

        for(auto itr : mp){
            if(itr.second > 0){
                ans.push_back(itr.first);
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};