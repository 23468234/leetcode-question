class Solution {
public:
    void func(vector<vector<int> > &result, vector<int> &nums, vector<int> &current, vector<bool>&nums1)
    {
        if (current.size() == nums1.size()){
            result.push_back(current);
        }
        else
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums1[i])
                {
                    if (i > 0 && nums[i] == nums[i - 1] && nums1[i - 1])//除重！！
                        continue;
                    current.push_back(nums[i]);
                    nums1[i] = false;
                    func(result, nums, current, nums1);
                    nums1[i] = true;
                    current.pop_back();
                }
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.size() == 0)
            return vector<vector<int>>();

        if (nums.size() == 1)
            return vector<vector<int>>(1, vector<int>(1, nums[0]));
        
        vector<bool> nums1(nums.size(), true);
        vector<int> current;
        sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        func(result, nums, current, nums1);
        return result;	
    }
};