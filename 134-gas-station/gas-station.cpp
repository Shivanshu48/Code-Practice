class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int toGas = 0, toCost = 0;
        for(int val : gas){
            toGas += val;
        }

        for(int val : cost){
            toCost += val;
        }

        if(toGas < toCost) return -1;

        int start = 0, currGas = 0;
        for(int i=0; i<gas.size(); i++){
            currGas += (gas[i] - cost[i]);

            if(currGas < 0){
                start = i+1;
                currGas = 0;
            }
        }
        return start;
    }
};