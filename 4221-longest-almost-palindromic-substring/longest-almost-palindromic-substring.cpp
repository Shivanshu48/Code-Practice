class Solution {
public:
    int almostPalindromic(string s) {
         int n = s.length();
        int maxLen = 1;
        
        for (int i = 0; i < n; i++) {
            int j = n - 1;
            while (j > i) {
                int left = i, right = j;
                int removals = 0;
                bool valid = true;
                
                while (left < right) {
                    if (s[left] == s[right]) {
                        left++;
                        right--;
                    } else {
                        if (removals == 0) {
                            int tempLeft = left + 1;
                            int tempRight = right;
                            bool leftValid = true;
                            
                            while (tempLeft < tempRight) {
                                if (s[tempLeft] != s[tempRight]) {
                                    leftValid = false;
                                    break;
                                }
                                tempLeft++;
                                tempRight--;
                            }
                            
                            if (!leftValid) {
                                tempLeft = left;
                                tempRight = right - 1;
                                bool rightValid = true;
                                
                                while (tempLeft < tempRight) {
                                    if (s[tempLeft] != s[tempRight]) {
                                        rightValid = false;
                                        break;
                                    }
                                    tempLeft++;
                                    tempRight--;
                                }
                                
                                if (!rightValid) {
                                    valid = false;
                                    break;
                                }
                            }
                            break;
                        } else {
                            valid = false;
                            break;
                        }
                    }
                }
                
                if (valid) {
                    maxLen = max(maxLen, j - i + 1);
                    break;
                }
                j--;
            }
        }
        
        return maxLen;
    }
};