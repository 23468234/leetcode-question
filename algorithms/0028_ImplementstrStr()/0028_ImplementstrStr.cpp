class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()){
            return 0;
        }

        for (int i = 0; i < haystack.length(); ++i){
            if (haystack[i] == needle[0]){

                int j = i;
                int k = 0;
                while(j < haystack.length()&& k < needle.length())
                {
                    if (haystack[j] != needle[k]){
                       break;
                    }
                    j++;
                    k++;
                }

                if (k == needle.length())
                return j - needle.length();
            }
        }
        return -1;
        
    }
};