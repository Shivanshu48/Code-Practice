class Solution {
public:
    bool validDigit(int n, int x) {
        bool found = false;
        int t = n;

        if (n == 0 && x == 0) found = true;

        while (t != 0) {
            if (t % 10 == x) {
                found = true;
            }
            t /= 10;
        }

        int first = n;
        while (first >= 10) {
            first /= 10;
        }

        if (found && first != x) {
            return true;
        }

        return false;

    }
};