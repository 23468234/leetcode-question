
#include <string>

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		auto GetSamePrefix = [](std::string str1, std::string str2)->std::string {
			int i = 0;
			while (i < str1.length() && i < str2.length() && str1[i] == str2[i]) {
				++i;
			}
			return str1.substr(0, i);
		};

		if (0 == strs.size()) {
			return "";
		}
		std::string str_rst = strs[0];
		for (std::size_t i = 0; i < strs.size(); ++i) {
			str_rst = GetSamePrefix(str_rst, strs[i]);
		}
		return str_rst;
	}
};

int main()
{
	std::vector<std::string> vct_src;
	vct_src.emplace_back("flower");
	vct_src.emplace_back("flow");
	vct_src.emplace_back("flight");
	std::string rst = Solution().longestCommonPrefix(vct_src);

	return 0;
}