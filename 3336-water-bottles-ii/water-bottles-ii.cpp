class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int full = numBottles;
        int empty = 0;
        int total = 0;
        int need = numExchange;

        while(full){
            total += full;
            empty += full;
            full = 0;
            while(empty >= need){
                empty -= need;
                full++;
                need++;
            }
        }
        return total;
    }
};