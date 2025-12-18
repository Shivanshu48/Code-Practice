class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int a, b, c, d;
        string real, imag;

        stringstream ss1(num1);
        getline(ss1, real, '+');
        getline(ss1, imag, 'i');
        a = stoi(real);
        b = stoi(imag);

        stringstream ss2(num2);
        getline(ss2, real, '+');
        getline(ss2, imag, 'i');
        c = stoi(real);
        d = stoi(imag);

        int realRes = a*c - b*d;
        int imagRes = a*d + b*c;

        return to_string(realRes) + "+" + to_string(imagRes) + "i";
    }
};