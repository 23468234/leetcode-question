class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {

        std::string str_rst;
        str_rst.resize(num1.length() + num2.length(), '0');

        for (int i = num1.length() -1; i >= 0; i--)
        {
            for (int j = num2.length() - 1; j >= 0; j--)
            {
               int tmp = str_rst[i + j + 1] - '0' + (num1[i] - '0') * (num2[j] - '0');
                str_rst[i + j + 1] = tmp % 10 + '0';
                str_rst[i + j] = str_rst[i + j] + tmp / 10;
            }
        }

        auto pos = str_rst.find_first_not_of('0');
        if (pos != std::string::npos)
        {
            str_rst = str_rst.substr(pos, str_rst.length() - pos);
        }
        else
        {
            return "0";
        }

        return str_rst;
    }
};