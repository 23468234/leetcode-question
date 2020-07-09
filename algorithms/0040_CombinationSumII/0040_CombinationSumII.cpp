class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.empty()){
            return {{}};
        }
		
        vector<vector<int>> rst;
        vector<int> tmp;
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        dfs(rst, tmp, 0, candidates, target, used);
        return rst;        
    }

    void dfs(vector<vector<int>> &rst, vector<int>& tmp, int sum, vector<int>& nums, int target, vector<bool> &used){       
        if (sum == target){
            rst.push_back(tmp);
            return;
        }

        for (int i = 0; i < nums.size(); ++i){
            if (used[i]){
                continue;
            }
            if (tmp.size() > 0 && tmp.at(tmp.size() - 1) > nums.at(i)){
                continue;
            }

            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]){
                continue;
            }

            if (sum + nums[i] > target){
                continue;
            }

            used[i] = true;
            sum = sum + nums[i];
            tmp.push_back(nums.at(i));
            dfs(rst, tmp, sum, nums, target, used);
            tmp.pop_back();
            sum = sum - nums[i];
            used[i] = false;
        }
    }
};