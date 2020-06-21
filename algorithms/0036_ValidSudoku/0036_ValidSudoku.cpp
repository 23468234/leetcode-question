class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {};
        int colum[9][9] = {};
        int rectangle[9][9] = {};

        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j){
                char tmp = board[i][j];
                if (!(tmp >= '1' && tmp <= '9')){
                    continue;
                }
                // check row
                if (row[i][tmp - '1'] == 1)
                {
                    return false;
                }
                row[i][tmp - '1'] = 1;

                // check colum
                if (colum[j][tmp - '1'] == 1)
                {
                    return false;
                }
                colum[j][tmp - '1'] = 1;

                // check rectangle
                if (rectangle[i/3 *3 + j/3][tmp - '1'] == 1)
                {
                    return false;
                }
                rectangle[i/3 *3 + j/3][tmp - '1']= 1;
            }
        }

        return true;

    }
};