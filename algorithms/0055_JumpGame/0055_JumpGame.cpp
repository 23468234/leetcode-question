class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach= 0;
        for (int i = 0; i < nums.size(); ++i){
            if (i > reach){
                return false;
            }

            reach = reach > (nums[i] + i) ? reach : (nums[i] + i) ;
        }

        return true;
    }
};