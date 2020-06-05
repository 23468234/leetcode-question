
class Solution {
public:
    int reverse(int x) {

        int flag = (x < 0) ? -1 : 1;
        long long  src = ( long long)x * flag;
        long long  dst = 0;
        while(src != 0)
        {   
            dst = dst * 10 + src %10;
            src = src / 10;
        }

        if (dst < (int)0x80000000 ||   dst > (int)0x7FFFFFFF)
        {
            return 0;
        }
        return dst * flag;

    }
};

int main(int argc, char *argv[])
{
    Solution().reverse(-44445524);
}
