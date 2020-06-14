class Solution {
public:
    string countAndSay(int n) {
        return countAndSay("1", n - 1);
    }

private:
    string countAndSay(std::string str, int n)
    {
        if (n <= 0)
        {
            return str;
        }

        std::string str_tmp;
        int i = 0;
        while(i < str.length())
        {
            auto pos = str.find_first_not_of(str[i], i);
            if (std::string::npos != pos)
            {
                str_tmp += std::to_string(pos - i);
                str_tmp.push_back(str[i]);
            }
            else{
                str_tmp += std::to_string(str.length() - i);
                str_tmp.push_back(str[i]);
                break;
            }
            i = pos;
        }

        return countAndSay(str_tmp, n - 1);
    }
};