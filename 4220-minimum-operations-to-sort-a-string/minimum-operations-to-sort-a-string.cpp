class Solution {
public:
    int minOperations(string s) {
        int len = s.length();
        bool ok = true;
        for(int i = 1; i < len; i++)
        {
            if(s[i] < s[i - 1])
            {
                ok = false;
                break;
            }
        }

        if(ok) return 0;
        if(len == 2) return -1;
        string arr = s;
        string brr = s;
        int fre[26] = {0};
        for(char c : arr) fre[c - 'a']++;
        int p = 0;
        for(int i = 0; i < 26; i++)
        {
            while(fre[i] > 0)
            {
                brr[p++] = char('a' + i);
                fre[i]--;
            }
        }
        int le = 0, ri = len - 1;
        while(le < len && arr[le] == brr[le]) le++;
        while(ri >= 0 && arr[ri] == brr[ri]) ri--;

        if(ri - le + 1 < len) return 1;
        char mx = arr[0], mn = arr[0];

        for(int i = 1; i < len; i++)
        {
            if(arr[i] > mx) mx = arr[i];
            if(arr[i] < mn) mn = arr[i];
        }

        bool ux = (arr[0] == mx);
        int cnt = 0;

        if(ux)
        {
            for(int i = 1; i < len; i++)
            {
                if(arr[i] == mx)
                {
                    ux = false;
                    break;
                }
            }
        }

        bool un = (arr[len - 1] == mn);
        bool flg = false;

        if(un)
        {
            for(int i = 0; i < len - 1; i++)
            {
                if(arr[i] == mn)
                {
                    un = false;
                    break;
                }
            }
        }
        if(ux && un) return 3;
        return 2;
    }
};