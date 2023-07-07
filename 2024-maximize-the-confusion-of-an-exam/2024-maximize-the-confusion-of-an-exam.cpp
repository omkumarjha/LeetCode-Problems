class Solution {
public:
    // Iss question mai jo hum k operation laga rahe hai woh hume T -> F and F -> T both pe karne ke liye lagana hai .
    // To isliye pehle pata karo ki T -> F mai kitne maximum consecutive questions with same answer aa rahe hai then same wahi cheej F -> T mai karo uske baad finally jo dono ka maximum hoga woh check karke return kardo

    int findMaxConsecutive(string answerKey,int k,char target){
        int i = 0 , j = 0 , ans = INT_MIN;
        int n = answerKey.length();
        int count = 0;

        while(j < n){
            if(answerKey[j] == target){
                count++;
            }
            while(j < n && count > k){
                if(answerKey[i] == target){
                    count--;
                }
                i++;
            }
            ans = max(ans,(j-i+1));
            j++;
        }
        return ans;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int max1 = findMaxConsecutive(answerKey, k,'T'); // iska matlab hum T->F mai and F ko ignore kar rahe hai.
        int max2 = findMaxConsecutive(answerKey, k,'F'); // iska matlab hum F->T mai and T ko ignore kar rahe hai.

        int maxi = max(max1,max2);
        return maxi;
    }
};