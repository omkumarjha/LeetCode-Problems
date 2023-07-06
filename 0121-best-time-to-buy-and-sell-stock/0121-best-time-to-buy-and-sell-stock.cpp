class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // eak approach to hai ki 0(n^2) se nested loops ka use karke max profit nikalo
        // Logic by anuj bhaiya 

        // yaha pe hum paralally min stock mai buy karne wala din and use jo max profit hoga woh sab sath mai karre hai 

        int maxProfit = 0 , minSoFar = prices[0];

        for(int i = 1; i < prices.size(); i++){
            minSoFar = min(minSoFar,prices[i]);
            int profit = prices[i] - minSoFar;
            maxProfit = max(profit,maxProfit);
        }

        return maxProfit;
    }
};