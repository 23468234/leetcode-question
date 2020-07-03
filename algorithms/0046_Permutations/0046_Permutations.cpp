class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> rst(1, vector<int>());
        for (int i = 0; i < nums.size(); ++i){            
            vector<vector<int>> tmp;
            for (int k = 0; k < nums.size(); ++k){
                for (int j = 0; j < rst.size(); ++j){
                    vector<int> line = rst[j];
                    if (line.end() != find(line.begin(), line.end(), nums[k])){
                        continue;
                    }
                    line.emplace_back(nums[k]);
                    tmp.emplace_back(line);
                }
            }
            rst.swap(tmp);
        }

        return rst;        
    }
};