#include <string>
#include <map>


class Solution{
public:
	std::string longestPalindrome(std::string strSrc)
	{
		if (strSrc.length() <= 1)
		{
			return strSrc;
		}
		std::map<int, std::pair<bool,int>> map_result;
		for (int i = 0; i < strSrc.length(); ++i)
		{
			// vitual middle
			int i_low = i;
			int i_high = i + 1;
			while (i_low >= 0 && i_high < strSrc.length() && strSrc.at(i_low) == strSrc.at(i_high))
			{
				--i_low;
				++i_high;
			}
			int i_len = i_high - i_low - 1;
			map_result.insert(std::make_pair(i_len, std::make_pair(true, i)));

			// really middle
			i_low = i - 1;
			i_high = i + 1;
			while (i_low >= 0 && i_high < strSrc.length() && strSrc.at(i_low) == strSrc.at(i_high))
			{
				--i_low;
				++i_high;
			}
			i_len = i_high - i_low - 1;
			map_result.insert(std::make_pair(i_len, std::make_pair(false , i)));
		}

		//over
		std::string str_rst;
		std::pair<bool, int> &it_result = map_result.rbegin()->second;
		int i_len = map_result.rbegin()->first;
		int index = it_result.second;
		bool is_even = it_result.first;
		if (is_even) {
			str_rst = strSrc.substr(index - i_len / 2 + 1, i_len);
		}
		else {
			str_rst = strSrc.substr(index - i_len / 2, i_len);;
		}
		return str_rst;
	}
};

int main()
{
	std::string str_test = "abba";
	auto rst = Solution().longestPalindrome(str_test);

	str_test = "aaa";
	rst = Solution().longestPalindrome(str_test);

	str_test = "abc";
	rst = Solution().longestPalindrome(str_test);

	str_test = "aba";
	rst = Solution().longestPalindrome(str_test);
	
	str_test = "fdsafdasaaabcdaf";
	rst = Solution().longestPalindrome(str_test);

	return 0;
}