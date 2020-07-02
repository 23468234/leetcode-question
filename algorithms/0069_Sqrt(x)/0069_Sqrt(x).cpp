class Solution {
public:
    int mySqrt(int x) {
        if (x <= 0){
            return 0;
        }

        int left = 0;
        int right = x;
        int ans = -1;

        while(left <= right){
            int mid = (left + right) / 2;
            if ((long long)mid * mid <= x){
                left = mid + 1;
                ans = mid;
            }else{
                right = mid - 1;
            }
        }
        return ans;        
    }
};