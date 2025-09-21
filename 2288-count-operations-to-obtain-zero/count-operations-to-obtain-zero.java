class Solution {
    public int countOperations(int num1, int num2) {
        return helper(num1, num2, 0);
    }

    public int helper(int num1, int num2, int count){
        
        if(num1 == 0 || num2 == 0) return count;
        if(num1 >= num2){
            return helper((num1-num2), num2, ++count);
        }
        return helper(num1, (num2-num1), ++count);
    }
}