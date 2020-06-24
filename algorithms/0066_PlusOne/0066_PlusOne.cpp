class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1, carry=1; i>-1; digits[i--] %= 10){
            digits[i] = digits[i] + carry;
            carry = digits[i] > 9;
        }
        if(!digits[0]) digits.insert(digits.begin(), 1);
        return digits;
    }
};
