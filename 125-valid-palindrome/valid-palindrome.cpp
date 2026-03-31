class Solution {
public:
    bool isPalindrome(string s) {
        string ss = s;
        /*for(char c : s){
            if(isalnum(c)){;
                if(isupper(c)){
                    c = tolower(c);
                }
                ss = ss + c;
            }
        }
        //string cp = ss;*/

        int left = 0;
        int right = ss.length()-1;
        bool flag = true;
        while(left < right){
            if(isalnum(ss[left]) && isalnum(ss[right])){

                if(tolower(ss[left]) != tolower(ss[right])){
                    flag = false;
                    break;
                }
                left++;
                right--;
            }
            else if(!isalnum(ss[left]) && isalnum(ss[right])){
                left++;
            }
            else{
                right--;
            }
            
        }
        return flag;
    }
};