class Solution {
public
    vectorint grayCode(int n) {
        vectorintrst (1, 0);
        for (int i = 0; i  n; ++i){
            for (int j = rst.size() -1 ; j = 0; j--){
                int num = rst.at(j) + (1  i) ;
                rst.push_back(num);
            }
        }
        return rst;
    }
};
