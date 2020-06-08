class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows <= 1){
            return s;
        }

        std::string str_ret;
        for (int i = 0; i < numRows; ++i)
        {
            //
            //Read one line
            //
            int j = i;

            //Read first word
            if ( j < s.length())
            {
                str_ret.push_back(s.at(j));
            }
    
            while(j < s.length())
            {
                // part 1
                int decrease = (numRows - i - 1) * 2;
                j = j + decrease;
                if (decrease > 0 && j < s.length())
                {
                    str_ret.push_back(s.at(j));
                }
                
                // part 2
                decrease = 2 * i;
                j = j + decrease;
                if (decrease > 0 && j < s.length())
                {
                    str_ret.push_back(s.at(j));
                }
            }
        }
        return str_ret;
    }
};

int main(int argc, char *argv[])
{
    std::string str_t = "PAYPALISHIRING";
    qDebug () << Solution().convert(str_t, 4).c_str();
    qDebug () << "PINALSIGYAHRPI";
    return a.exec();
}

