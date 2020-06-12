
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0){
            return -1;
        }
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int pos = (left + right) / 2;
            if (nums[pos] == target){
                return pos;
            }
            else if (nums[pos] < nums[right]){
                if (nums[pos] < target && target <= nums[right])
                {
                    left = pos + 1;
                }
                else {
                     right = pos - 1;
                }
            }
            else{
                if (target >= nums[left] && target < nums[pos])
                {
                    right = pos - 1;    
                }
                else{
                    left = pos + 1;
                }
            }

        }
        return -1;

    }
};