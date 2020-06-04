
/*

3. 无重复字符的最长子串
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/



#include <string>
#include <set>

class Solution {
public:
	int lengthOfLongestSubstring(std::string s) {
		int i_max_len = 0;
		int i_read_index = 0;
		std::set<char> set_cache;

		for (int i = 0; i < s.length(); ++i)
		{
			if (i > 0)
			{
				set_cache.erase(s[i - 1]);
			}

			while(i_read_index < s.length() && set_cache.count(s[i_read_index]) <= 0)
			{
				set_cache.insert(s[i_read_index]);
				++i_read_index;
			}

			i_max_len = i_max_len > (int)set_cache.size() ? i_max_len : (int)set_cache.size();
		
		}
		return i_max_len;
	}
};


int main()
{
	std::string str_abc= "fdafdasgadf";

	Solution().lengthOfLongestSubstring(str_abc);
	return 0;
}
