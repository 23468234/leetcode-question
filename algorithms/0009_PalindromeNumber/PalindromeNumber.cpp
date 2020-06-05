
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 ||  x> 0 && ((x % 10 ) == 0))
        {
            return false;
        }
        
        int src = x;
        long long target = 0;

        while(src)
        {
            target = target * 10 + src % 10;
            src = src / 10;
        }

        return (target == x);
    }
};
int main(int argc, char *argv[])
{
	Solution().reverse(-44445524);
	return 0;
}
