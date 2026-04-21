class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        double a = sides[0];
        double b = sides[1];
        double c = sides[2];

        if (a + b <= c || a + c <= b || b + c <= a) {
            return {};
        }

        const double PI = acos(-1.0);
        double A = acos((b*b + c*c - a*a) / (2*b*c)) * 180.0 / PI;
        double B = acos((a*a + c*c - b*b) / (2*a*c)) * 180.0 / PI;
        double C = acos((a*a + b*b - c*c) / (2*a*b)) * 180.0 / PI;

        vector<double> ans = {A, B, C};
        sort(ans.begin(), ans.end());

        return ans;
    }
};