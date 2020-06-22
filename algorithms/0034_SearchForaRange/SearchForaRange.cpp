class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int index  = search(nums, 0 ,nums.size()-1, target);
        if(index == -1) return {-1, -1};
        // 开始左查找
        int left_end = index - 1;
        while(left_end >= 0 && nums[left_end] == target){
            left_end = search(nums, 0, left_end, target) - 1;
        }
        // 开始右查找
        int right_start = index + 1;
        while(right_start < nums.size()  && nums[right_start] == target){
            right_start = search(nums, right_start, nums.size()-1, target) + 1;
        }

        // 返回结果
        return {left_end + 1, right_start - 1};
    }
private:
    int search(vector<int>& nums, int start, int end, int target){
        while(start <= end){
            int mid = (start + end)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return -1;
    }
};
