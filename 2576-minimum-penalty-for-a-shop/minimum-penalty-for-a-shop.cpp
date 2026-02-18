class Solution {
public:
    int bestClosingTime(string customers) {
        int fine = 0;
        int n = customers.length();
        int mfine, closehour = 0;
        for(char c :  customers){
            if(c == 'Y') fine++;
        }
        if(fine == 0) return 0;
        mfine = fine;
        for(int i = 0; i < n; i++){
            if(customers[i] == 'Y') fine--;
            if(customers[i] == 'N') fine++;
            if(fine < mfine){
                mfine  = fine;
                closehour = i+1;
            }
        }
        return closehour;
    }
};