class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> nums={"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};        
        vector<string> result;
        if(digits.empty()){
            return result;
        }
        result.push_back("");
        for(int i=0;i<digits.size();i++){
            vector<string> tempresult;
            int num=digits[i]-'0'-1;
            for(int j=0;j<nums[num].size();j++){
                for(int k=0;k<result.size();k++){
                    std::string tmp = result[k] + nums[num][j];
                    tempresult.push_back(tmp);
                }                
            }
            result=tempresult;
        }
        return result;
    }
};