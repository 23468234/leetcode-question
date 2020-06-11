class Solution {
public:
	std::vector<std::string> generateParenthesis(int n) {
		std::vector<std::pair<int, std::string>> vct_rst;
		vct_rst.push_back(std::make_pair(-1, "("));

		//一共有2*n个字符，已经确定第一个是‘(’
		for (int i = 0; i < n * 2 - 1; ++i) {
			std::vector<std::pair<int, std::string>> vct_temp;
			for (int j = 0; j < vct_rst.size(); ++j) {
				auto pair_tmp = vct_rst[j];

				//即使剩下的字符个数填‘)'，可以凑成合法的括号
				if (n * 2 - i - 1 + pair_tmp.first > 0) {
					vct_temp.push_back(std::pair<int, std::string>(pair_tmp.first - 1, pair_tmp.second + "("));
				}

				// 前面还有未匹配的‘(’
				if (pair_tmp.first < 0) {
					vct_temp.push_back(std::pair<int, std::string>(pair_tmp.first + 1, pair_tmp.second + ")"));
				}
			}
			vct_rst = vct_temp;
		}

		std::vector<std::string> rst;
		for (int i = 0; i < vct_rst.size(); ++i) {
			auto pair_tmp = vct_rst[i];
			rst.push_back(pair_tmp.second);
		}
		return rst;
	}
};
