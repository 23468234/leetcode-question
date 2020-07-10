
class Solution {
public:
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        int i_total = 0;        
        dfs(i_total, board, 0);        
        return i_total;
    }

    void dfs(int &i_total, vector<string> &board, int index){
        if (index == board.size()){
            i_total++;
            return;
        }

        for (int i = 0; i < board.size(); ++i){
            if (!IsValid(board, index, i)){
                continue;
            }
            board[index][i] = 'Q';
            dfs(i_total, board,  index + 1);
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