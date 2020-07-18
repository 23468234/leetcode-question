class Solution {
private:
        vector<vector<bool>> mRow;
        vector<vector<bool>> mColumn;
        vector<vector<bool>> mArea;
public:
    void solveSudoku(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0){
            return;
        }
        
        if (!Init(board)){
            return;
        }

        dfs(board, 0, 0);
    }


    bool dfs(vector<vector<char>>& board, int row, int column)
    {   
        if (row == board.size() - 1 && column == board.size() - 1){
            return true;
        }

        if (column >= board.size()){
            row++;
            column = 0;
        }

        if (board[row][column] != '.'){
             dfs(board, row, column + 1);
        }
        else{
        for (int i = 1; i < board.size() + 1; ++i){
            if (!Insert(row, column, i - 1)){
                continue;
            }

            board[row][column] = i + '0';
            if ( dfs(board, row, column + 1)){
                return true;
            }
            board[row][column] = '.';
            Delete(row, column, i - 1);
        }
        }

        
        return false;
    }

    bool Init(vector<vector<char>>& board){
        mRow = vector<vector<bool>>(board.size(), vector<bool>(board.size(), false));
        mColumn = vector<vector<bool>>(board.size(), vector<bool>(board.size(), false));
        mArea = vector<vector<bool>>(board.size(), vector<bool>(board.size(), false));

        for (int i = 0; i < board.size(); ++i){
            for (int j = 0; j < board[0].size(); ++j){
                if (board[i][j] == '.'){
                    continue;
                }

                if (!Insert(i, j, board[i][j] - '1')){
                    return false;
                }
            }
        }
        return true;
    }

    bool Insert(int row, int column, int value){
        if (mRow[row][value]){
            return false;
        }
        
        if (mColumn[column][value]){
            return false;
        }

        if (mArea[row / 3 * 3 + column / 3][value]){
            return false;
        }

        mRow[row][value] = true;
        mColumn[column][value] = true;
        mArea[row / 3 * 3 + column / 3][value] = true;
        return true;
    }

    bool Delete(int row, int column, int value){
        mRow[row][value] = false;
        mColumn[column][value] = false;
        mArea[row / 3 * 3 + column / 3][value] = false;
        return true;
    }
};