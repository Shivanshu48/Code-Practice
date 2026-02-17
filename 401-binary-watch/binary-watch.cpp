class Solution {
public:
    vector<string> result;
    vector<int> leds = {8,4,2,1,32,16,8,4,2,1};

    void dfs(int idx, int turnedOn, int hour, int minute) {
        if (hour > 11 || minute > 59) return;

        if (turnedOn == 0) {
            string time = to_string(hour) + ":";
            if (minute < 10) time += "0";
            time += to_string(minute);
            result.push_back(time);
            return;
        }

        for (int i = idx; i < 10; i++) {
            if (i < 4)
                dfs(i + 1, turnedOn - 1, hour + leds[i], minute);
            else
                dfs(i + 1, turnedOn - 1, hour, minute + leds[i]);
        }
    }
    
    vector<string> readBinaryWatch(int turnedOn) {
        dfs(0, turnedOn, 0, 0);
        return result;
    }
};