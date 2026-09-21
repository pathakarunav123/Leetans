#include <string>
#include <algorithm>

class Solution {
public:
    std::string addStrings(std::string num1, std::string num2) {
        std::string result = "";
        int carry = 0;
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        while (i >= 0 || j >= 0 || carry > 0) {
            int digit1 = (i >= 0) ? num1[i] - '0' : 0;
            int digit2 = (j >= 0) ? num2[j] - '0' : 0;
            int total = digit1 + digit2 + carry;
            carry = total / 10;
            result.push_back((total % 10) + '0');
            i--;
            j--;
        }
        reverse(result.begin(), result.end());
        
        return result;
    }
};