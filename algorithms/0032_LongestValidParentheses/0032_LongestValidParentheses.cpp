
#if 0
class Solution {
public:
    int longestValidParentheses(string s) {
        int rst = 0;

        stack<int> stack_tmp;
        stack_tmp.push(-1);
        for (int i = 0; i < s.length(); ++i){
            if (s.at(i) == '('){
                stack_tmp.push(i);
            }
            else{
                stack_tmp.pop();

                if (stack_tmp.empty()){
                    stack_tmp.push(i);
                }else{
                    rst  = rst > i - stack_tmp.top() ? rst : i - stack_tmp.top();
                }
            }
        }
        
        return rst;
    }
};
#endif

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty()){
            return 0;
        }

        std::vector<int>rst(s.length(), 0);
        for (int i = 0; i < s.length(); ++i){
            if (s.at(i) == ')'){
                // 判断挨着的有多长
                if (i - 1 < 0){
                    continue;
                }
                int len = rst[i - 1];

                // 获取上一个左括号
                if (i - len - 1 < 0){
                    continue;
                }

                if (s.at(i-len-1) != '('){
                    continue;
                }                
                rst[i] = len + 2;

                // 获取左括号左边的长
                if (i-len-2 < 0){
                    continue;
                }                

                rst[i] += rst[i-len-2];
            }
        }

        // 遍历rst
        int target = 0;
        for (auto value : rst){
            if (value > target){
                target = value;
            }
        }

        return target;
    }
};


