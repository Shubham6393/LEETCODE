class Solution {
public:

    bool isdigit(char c) {
        return c >= '0' && c <= '9';
    }

    int solve(string &s, int i, int sign, long long num) {

        // Base Case
        if (i >= s.length() || !isdigit(s[i])) {

            long long result = sign * num;

            // Clamp if overflow
            if (result <= INT_MIN)
                return INT_MIN;

            if (result >= INT_MAX)
                return INT_MAX;

            return (int)result;
        }

        int digit = s[i] - '0';

        // Check overflow BEFORE num * 10
        if (num > INT_MAX / 10 ||
            (num == INT_MAX / 10 && digit > 7)) {

            if (sign == -1)
                return INT_MIN;

            return INT_MAX;
        }

        // Add current digit
        num = num * 10 + digit;

        // Recursive call
        return solve(s, i + 1, sign, num);
    }

    int myAtoi(string s) {

        int i = 0;

        // Step 1: Ignore leading spaces
        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        int sign = 1;

        // Step 2: Check sign
        if (i < s.length()) {

            if (s[i] == '-') {
                sign = -1;
                i++;
            }
            else if (s[i] == '+') {
                i++;
            }
        }

        // Step 3: Start recursion
        return solve(s, i, sign, 0);
    }
};