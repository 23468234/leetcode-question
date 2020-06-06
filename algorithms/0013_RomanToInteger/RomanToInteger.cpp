

#include <string>
#include <map>
class Solution {
public:
    int romanToInt(std::string s) {
        std::map<char, int> map_value{
            std::map<char, int>::value_type('I',             1),
            std::map<char, int>::value_type('V',            5),
            std::map<char, int>::value_type('X',             10),
            std::map<char, int>::value_type('L',             50),
            std::map<char, int>::value_type('C',             100),
            std::map<char, int>::value_type('D',             500),
            std::map<char, int>::value_type('M',             1000)
        };

        int ret = 0;
        int num_bk = 0;
        int len = s.length();
        while(len > 0)
        {
            int tmp =  map_value.at(s.at(len - 1));
            if (num_bk > tmp){
                ret = ret -tmp;
            }
            else{
                ret = ret + tmp;
            }
            num_bk =tmp;

            len --;
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
	Solution().romanToInt("IV");
	return 0;
}
