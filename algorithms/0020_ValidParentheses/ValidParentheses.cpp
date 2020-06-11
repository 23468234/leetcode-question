class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) {
                    return false;
                }
                char c_top = st.top();
                st.pop();
                if ((c_top == '(' && c != ')') ||
                    (c_top == '{' && c != '}') ||
                    (c_top == '[' && c != ']') ) {
                    return false;
                }
            }
        }

        if (!st.empty()) {
            return false;
        }

        return true;
    }
};

作者：zhanganan0425
链接：https://leetcode-cn.com/problems/valid-parentheses/solution/zhan-de-ji-chu-ying-yong-by-zhanganan0425/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。