
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
class Solution {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::map<int, int> map_num;
		for (std::size_t i = 0; i < nums.size(); ++i)
		{
			int another = target - nums[i];
			if (map_num.find(another) != map_num.end())
			{
				std::vector<int> vct_ret;
				vct_ret.push_back(i);
				vct_ret.push_back(map_num[another]);
				return vct_ret;
			}
			else
			{
				map_num.insert(std::pair<int, int>(nums[i], i));
			}
		}

		return std::vector<int>();
	}
};

int main()
{
	int nums[] = { 2,7,3,7,11,15};
	int target = 9;

	std::vector<int> vect_array(nums, nums+ 4);
	Solution().twoSum(vect_array, target);
	return 0;
}
