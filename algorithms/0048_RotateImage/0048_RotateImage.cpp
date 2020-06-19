class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++ ) {       // 第i个方框
            int side = n - 2 * i;                // 第i个方框的边长
            for (int j = 0; j < side - 1; j ++){ //每个方框交换边长减1次
                int tmp = matrix[i][i + j];
                matrix[i][i + j] = matrix[i + side - 1 - j][i];
                matrix[i + side - 1 - j][i] = matrix[i + side - 1 ][i + side - 1 - j];
                matrix[i + side - 1 ][i + side - 1 - j] = matrix[i + j][i + side - 1];
                matrix[i + j][i + side - 1] =  tmp;
            }
        }
    }
};

