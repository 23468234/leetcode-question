class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> rst;        
        dfs(rst, board, 0);        
        return rst;
    }

    void dfs(vector<vector<string>> &rst, vector<string> &board, int index){
        if (index == board.size()){
            rst.emplace_back(board);
            return;
        }

        for (int i = 0; i < board.size(); ++i){
            if (!IsValid(board, index, i)){
                continue;
            }
            board[index][i] = 'Q';
            dfs(rst, board,  index + 1);
            board[index][i] = '.';        
        }
    }

    bool IsValid(vector<string> &board, int row, int column){
        for (int i = row; i >= 0; --i){
            if (board[i][column] == 'Q'){
                return false;
            }
        }

        for (int i = row, j = column; i >= 0 && j >= 0; i--, j--){            
            if (board[i][j] == 'Q'){
                return false;
            }
        }
        
        for (int i = row, j = column; i >= 0 && j < board.size(); i--, j++){            
            if (board[i][j] == 'Q'){
                return false;
            }
        }

        return true;
    }
};