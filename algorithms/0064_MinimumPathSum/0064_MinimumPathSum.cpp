class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0  || grid[0].size() == 0){
            return 0;
        }

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vct_tmp(m, vector<int>(n, 0));

        // 填充左上角
		vct_tmp[0][0] = grid[0][0];

		// 填充 第0 行
        for (int i = 1; i < n; ++i){
            vct_tmp[0][i] = grid[0][i] + vct_tmp[0][i - 1];  
        }
		
		// 填充第0列
        for (int i = 1; i < m; ++i){
            vct_tmp[i][0] = grid[i][0] + vct_tmp[i - 1][0];  
        }

		// 填充其他
        for (int i = 1; i < m; ++i){
            for (int j = 1; j < n; ++j){
                int top = vct_tmp[i - 1][j];
                int left = vct_tmp[i][j - 1];
                int min = top < left ? top : left;
                vct_tmp[i][j] =  min + grid[i][j];
            }
        }

        return vct_tmp[m - 1][n - 1];        
    }
};