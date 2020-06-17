class Solution {
public:
     double myPow(double x, int n) {
      int temp_n=n;
      double ans=1;
        while(n!=0){
            if((n&1)!=0){//和1与取末尾
                ans*=x;
            }
            x*=x;
            n/=2;//相当于数字右移，每次取新的位做末位
        }
        return temp_n>=0?ans:1/ans;

    }
};
