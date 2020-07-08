class Solution {
public:
    vector<vector<int>> combine(int n, int k) { 
        if (n < k){
            return {};
        }
        vector<vector<int>> rst;
        std::vector<int> tmp;
        dfs(rst, tmp, n, k, 0);
        return rst;
    }

    void dfs(vector<vector<int>> &rst, std::vector<int> &tmp,  int n, int k, int index){
        // k个数已经满足
        if (tmp.size() >= k){
            rst.push_back(tmp);
            return ;
        }

        // 因为单个结果中数字从小到大放的
        // 所以如果剩余的数字个数不能填充tmp到k个，就可以放弃了
        if (n - index < k - tmp.size()){
            return;
        }

        for (int i = tmp.size() + 1; i <= n; ++i){
            // 结果需要从小到大，去重
            if (tmp.size() > 0 && tmp[tmp.size() - 1] >= i){
                continue;                
            }

            tmp.push_back(i);
            dfs(rst, tmp,  n, k, i);
            tmp.pop_back();
        }
    }
};
