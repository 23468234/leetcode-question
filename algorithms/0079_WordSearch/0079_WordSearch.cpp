class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || board[0].size() == 0){
            return false;
        }

        vector<vector<bool>> used(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0 ; i < board.size(); i++){
            for (int j = 0; j < board[i].size(); ++j){                
                if (dfs( board, i, j, word, 0, used)){
                    return true;
                }
            }
        }
        return false;
    }

    bool  dfs(const vector<vector<char>>& board, int row, int column, 
            const string &word, int index, vector<vector<bool>> &used){

        if (board[row][column] != word[index]){
            return false;
        }

        if (index == word.length() - 1){
            return true;
        }
        
        int height = board.size();
        int width = board[0].size();

        used[row ][column] = true;
        // 上
        if (row > 0 && !used[row - 1][column] ){
            if (dfs( board, row - 1, column, word, index + 1, used)){
                return true;
            }
        }

        // 左
        if (column > 0 && !used[row][column - 1] ){
            if (dfs( board, row, column - 1, word, index + 1, used)){
                return true;
            }
        }

         // 下
        if (row + 1 < height && !used[row + 1][column]){
            if (dfs( board, row + 1, column, word, index + 1, used)){
                return true;
            }
        }

        // 右
        if (column + 1 < width  && !used[row][column + 1]){
            if (dfs( board, row, column+ 1, word, index + 1, used)){
                return true;
            }
        }
        used[row][column] = false;
        return false;
    }
};