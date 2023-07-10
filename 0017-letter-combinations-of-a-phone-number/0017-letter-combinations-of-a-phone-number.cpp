class Solution {
public:
    void findCombinations(string digits,vector<string>& ans,string output,int index,string mapping[]){
        // Base case
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }
        else{
            int number = digits[index] - '0';
            string value = mapping[number];
            for(int i = 0; i < value.length(); i++){
                output.push_back(value[i]);
                findCombinations(digits,ans,output,index+1,mapping);
                output.pop_back(); // backtracking
            }
        }
    }
    vector<string> letterCombinations(string digits){
        vector<string> ans;

        if(digits.length() == 0){
            return ans;
        }

        string output = "";
        int index = 0;
        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        findCombinations(digits,ans,output,index,mapping);

        return ans;

    }
};