class Solution {
public:

    void threeSum(set<vector<int>>& ans, vector<int>& nums, int pivot, int i, int target) {
        int l, r;
        for (; i < nums.size() - 2; i++) {
            l = i + 1;
            r = nums.size() - 1;
            while (l < r) {
                int cur_sum = nums[l] + nums[r] + nums[i];
                if (cur_sum == target) {
                    ans.insert({ pivot, nums[i], nums[l], nums[r] });
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                }
                else if (cur_sum < target) {
                    l++;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                }
                else {
                    r--;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                }
            }
        }
    }

    /*
    [-1,2,2,-5,0,-1,4]
    3
    [-5,-1,-1,0,2,2,4]
    */
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        std::sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        for (size_t i = 0; i < nums.size() - 3; i++) {
            threeSum(ans, nums, nums[i], i + 1, target - nums[i]);
        }
        vector<vector<int>> res(ans.size());
        std::copy(ans.begin(), ans.end(), res.begin());
        return res;
    }
};