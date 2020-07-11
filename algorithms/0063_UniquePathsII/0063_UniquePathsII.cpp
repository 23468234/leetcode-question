class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()){
            return 0;
        }

        int row = obstacleGrid.size();
        int column = obstacleGrid[0].size();

        vector<vector<int>> board(row, vector<int>(column, 0));
        if (obstacleGrid[0][0] == 1){
            return 0;
        }

        board[0][0] = 1;
        for (int i = 1; i < column; ++i){
            board[0][i] = (obstacleGrid[0][i] == 1) ? 0 : board[0][i - 1] ;
        }

        for (int i = 1; i < row; ++i){
            board[i][0] = (obstacleGrid[i][0] == 1) ? 0 : board[i - 1][0];
        }

        for (int i = 1; i < row; i ++){
            for (int j = 1; j < column; ++j){
                board[i][j] = (obstacleGrid[i][j] == 1) ? 0 : board[i - 1][j] + board[i][j - 1];
            }
        }

        return board[row - 1][column - 1];
    }
};