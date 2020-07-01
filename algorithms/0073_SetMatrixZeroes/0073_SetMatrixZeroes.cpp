class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0){
            return ;
        }

        int m = matrix.size();
        int n = matrix[0].size();

        vector row(m, 0);
        vector column(n, 0);
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (matrix[i][j] == 0){
                    row[i] = 1;
                    column[j] = 1;
                }                
            }
        }

        for (int i = 0; i < m; ++i){
            if (row[i] == 1){
                for (int k = 0; k < n; ++k){
                    matrix[i][k] = 0;
                }
            }
        }

         for (int i = 0; i < n; ++i){
            if (column[i] == 1){
                for (int k = 0; k < m; ++k){
                    matrix[k][i] = 0;
                }
            }
        }
    }
};