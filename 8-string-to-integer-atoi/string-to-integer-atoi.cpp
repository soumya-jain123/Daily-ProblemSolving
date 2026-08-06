class Solution {
public:
    int myAtoi(string s) {
        long long i = 0, sign = 1, result = 0;

        while(i < s.length() && s[i] == ' ') i++;

        if(i < s.length() && (s[i] == '+' || s[i] == '-')){
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while(i < s.length() && s[i] >= '0' && s[i] <= '9'){
            int digit = s[i] - '0';

            if(result > INT_MAX / 10 || (result == INT_MAX/10 && digit > (sign == 1? 7 : 8 )))
                return (sign == 1) ? INT_MAX : INT_MIN;

            result = result * 10 + digit;
            i++;
        }

        return sign * result;
    }
};