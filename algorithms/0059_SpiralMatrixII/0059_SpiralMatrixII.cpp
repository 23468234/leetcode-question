class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>vct_rst;
        for (int i = 0; i < n; ++i){
            vct_rst.push_back(vector<int>(n));
        }

        int num = 1;
        int loops = (n + 1) / 2; // 共填充多少方框
        for (int i = 0; i < loops; ++i){
            int len = n - 2 * i; // 方框边长
            if(len == 1) { //n为基数的情况
                vct_rst[i][i] = num;
                break;
            }

            int leftx = i;   // 当前方框的左上角
            int lefty = i;   // 当前方框的左上角
            int rightx = i + len - 1; //当前方框的右下角
            int righty = i + len - 1;//当前方框的右下角

            for (int j = leftx; j < rightx; ++j){
                vct_rst[leftx][j] = num;
                num++;
            }

            for (int j = lefty; j < righty; ++j) {
                vct_rst[j][rightx] = num;
                num++;
            }

            for (int j = rightx; j > leftx; --j) {
                vct_rst[righty][j] = num;
                num++;
            }

            for (int j = righty; j > lefty; --j) {
                vct_rst[j][leftx] = num;
                num++;
            }
        }

        return vct_rst;        
    }
};