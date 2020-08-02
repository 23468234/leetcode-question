class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int row = matrix.size();
        if (row == 0){
            return 0;
        }
        int column = matrix[0].size();
        if (column == 0){
            return 0;
        }

        int max_rect = 0;
        vector<vector<int>> dp(row, vector<int>(column, 0));
        for (int i = 0; i < row; ++i){
            for (int j = 0; j < column; ++j){
                int width = 0;
                if (matrix[i][j] == '1'){
                     width = j > 0 ? dp[i][j - 1] + 1 : 1;
                }
                dp[i][j] = width;


                for (int k = i; k >= 0; --k){
                    width = dp[k][j] < width ? dp[k][j] : width; 
                    if (0 == width){
                        break;
                    }
                    max_rect = max_rect > (i - k + 1) * width ? max_rect : (i - k + 1) * width ;
                }

            }
        }

        return max_rect;
    }
};