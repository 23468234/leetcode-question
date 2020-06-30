class Solution {
public:
    int climbStairs(int n) {
        if (n == 1){
            return 1;        
        }
        if (n == 2){
            return 2;
        }

        int ret = 0;
        int b1 = 1;
        int b2 = 2;
        for (int i = 2; i < n;++i){
            ret = b1 + b2;
            b1 = b2;
            b2 = ret;
        }

        return ret;
    }
};