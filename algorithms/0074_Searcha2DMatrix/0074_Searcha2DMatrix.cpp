#if 0
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0){
            return false;
        }

        int m = matrix.size();
        int n = matrix[0].size();

        int i = 0;
        int j = n - 1;

        while(i < m && j >= 0){
            if (matrix[i][j] == target){
                return true;
            }
            else if (matrix[i][j] < target){
                i++;
            }
            else{
                j--;
            }
        }

        return false;        
    }
};
#endif

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0){
            return false;
        }

        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0; 
        int right = m * n - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            int row = mid / n;
            int column = mid % n;
            if (matrix[row][column] == target){
                return true;
            }
            else if (matrix[row][column] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return false;        
    }
};