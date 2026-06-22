class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int bc = 0, ac = 0, lc = 0, oc = 0, nc = 0;
        for(char c : text){
            if(c == 'b') bc++;
            else if(c == 'a') ac++;
            else if(c == 'l') lc++;
            else if(c == 'n') nc++;
            else if(c == 'o') oc++;
        }
        lc = lc / 2;
        oc = oc / 2;
        return min({bc, ac, lc, nc, oc});
    }
};