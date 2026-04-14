class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.length() == 0) {
            return s.length() == 0;
        }

        bool first_char_matched = false;
        if(s.length() > 0 && (p[0] == s[0] || p[0] == '.')) {
            first_char_matched = true;
        }
        
        if (p.length() >= 2 && p[1] == '*') {
            return (isMatch(s, p.substr(2)) ||
                    (first_char_matched && isMatch(s.substr(1), p)));
        } else {
            return first_char_matched && isMatch(s.substr(1), p.substr(1));
        }
    }
};