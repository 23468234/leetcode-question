class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.empty()){
            return {{}};
        }
		
        vector<vector<int>> rst;
        vector<int> tmp;
        dfs(rst, tmp, 0, candidates, target);
        return rst;        
    }

    void dfs(vector<vector<int>> &rst, vector<int>& tmp, int sum, vector<int>& nums, int target){       
        if (sum == target){
            rst.push_back(tmp);
            return;
        }

        for (int i = 0; i < nums.size(); ++i){
            if (tmp.size() > 0 && tmp.at(tmp.size() - 1) > nums.at(i)){
                continue;
            }

            if (sum + nums[i] > target){
                continue;
            }

            sum = sum + nums[i];
            tmp.push_back(nums.at(i));
            dfs(rst, tmp, sum, nums, target);
            tmp.pop_back();
            sum = sum - nums[i];
        }
    }
};