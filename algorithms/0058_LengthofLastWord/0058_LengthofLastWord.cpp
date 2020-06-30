class Solution {
public:
    int lengthOfLastWord(string s) {
        int i_len = s.length();

        int i = i_len - 1;
        while(i >= 0){if (s[i] != ' ')break;i--;}
        if (i < 0){return 0;}

        int end = i + 1;
        while(i >= 0){if (s[i] == ' ')break; i--;}

        int start = i + 1;
        return end- start;
    }
};