class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0){
            return 0;
        }
        // from left
        vector<int> from_left(height.size(), 0);
        from_left[0] = height[0];
        for (int i = 1; i < height.size(); ++i){
            from_left[i] = from_left[i - 1] > height[i] ? from_left[i - 1] : height[i];
        }

        // from right
        vector<int> from_right(height.size(), 0);
        from_right[height.size() - 1] = height[height.size() - 1];
        for (int i = height.size() - 2; i >= 0; --i){
            from_right[i] = from_right[i + 1] > height[i] ? from_right[i + 1] : height[i];
        }

        int ans = 0;
        for (int i = 0; i < height.size(); ++i){
            int tmp = from_left[i] < from_right[i] ? from_left[i] : from_right[i];
            ans += tmp - height[i];
        }

        return ans;
    }
};