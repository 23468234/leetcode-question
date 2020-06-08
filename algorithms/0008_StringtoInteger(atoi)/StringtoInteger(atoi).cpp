class Solution {
public:
    int myAtoi(std::string str) {

        // part 1 ,delete the blank;
        int index = 0;
        while(index < str.length()){
            if (str.at(index) != ' ')
            {
                break;
            }
            ++index;
        }

        if (index >= str.length())
        {
            return 0;
        }

        //获取符号
        int flag = 1;
        if (str.at(index) != '-' && str.at(index) != '+' && (str.at(index) < '0' || str.at(index) > '9'))
        {
            return 0;
        }

        if (str.at(index) == '-')
        {
            flag = -1;
            index++;
        }
        else   if (str.at(index) == '+')
        {
            flag = 1;
            index++;
        }

        long long ll_ret = 0;
        while(index < str.length() && str.at(index) >= '0' && str.at(index) <= '9')
        {
            ll_ret = ll_ret * 10 + str.at(index) - '0';
            if (ll_ret * flag < (int)0x80000000){
                return 0x80000000;
            }
            else if (ll_ret * flag > (int)0x7FFFFFFF){
                return 0x7FFFFFFF;
            }
            ++index;
        }
        ll_ret = ll_ret * flag;
        return ll_ret;
    }
};