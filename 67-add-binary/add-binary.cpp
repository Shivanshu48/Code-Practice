class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";

        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0) {
            int digitA = (i >= 0) ? a[i] - '0' : 0;
            int digitB = (j >= 0) ? b[j] - '0' : 0;

            int sum = digitA + digitB + carry;
            carry = sum / 2;

            result.push_back((sum % 2) + '0');

            i--;
            j--;
        }

        if (carry != 0) {
            result.push_back(carry + '0');
        }

        reverse(result.begin(), result.end());
        return result;
    }
};