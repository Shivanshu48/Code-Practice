class Solution {
public:
    string decodeString(string s){
        int i=0;
        return decode(s,i);
    }

    string decode(string& s,int& i){
        string res="";
        int k=0;

        while(i<s.size()){
            if(isdigit(s[i])){
                k=k*10+(s[i]-'0');
            }
            else if(s[i]=='['){
                i++;
                string temp=decode(s,i);
                while(k--){
                    res+=temp;
                }
                k=0;
            }
            else if(s[i]==']'){
                return res;
            }
            else{
                res+=s[i];
            }
            i++;
        }
        return res;
    }
};