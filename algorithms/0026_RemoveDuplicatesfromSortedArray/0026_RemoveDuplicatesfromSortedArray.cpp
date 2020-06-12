class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return 0;
        }
        int k = 1;
        int bk = nums[0];

        for (std::size_t i = 1; i < nums.size(); i++)
        {
            if (bk != nums[i])
            {
                nums[k++] = nums[i];
                bk = nums[i];
            }
        }

        return k;
    }
};