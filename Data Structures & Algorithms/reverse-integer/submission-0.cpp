class Solution {
public:
    int reverse(int x) {
        int res = 0;

        while (x != 0) {
            int digit = x % 10;

            // Overflow check
            if (res > INT_MAX / 10 || 
               (res == INT_MAX / 10 && digit > 7))
                return 0;

            // Underflow check
            if (res < INT_MIN / 10 || 
               (res == INT_MIN / 10 && digit < -8))
                return 0;

            res = res * 10 + digit;
            x /= 10;
        }

        return res;
    }
};