class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<int> rst(m, 1);
        for (int j = 1; j < n; ++j)
        {
            for (int i = 1; i < m; ++i){
                rst[i] = rst[i - 1] + rst[i];
            }
        }

        return rst[m - 1];

    }
};