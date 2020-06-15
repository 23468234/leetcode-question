class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {        
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1])            {
                int tmp = nums[i];
                nums[i] = nums[tmp - 1];
                nums[tmp - 1] = tmp;
            }
        }
        for (int i = 0; i < nums.size(); ++i)        {
           if (i + 1 != nums[i])           {
               return i+1;
           }
        }

        return nums.size() + 1;
    }
};

