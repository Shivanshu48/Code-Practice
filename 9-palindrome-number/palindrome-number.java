class Solution {
    public boolean isPalindrome(int x) {
        int revNum = 0;
        int copy = x;
        while (x > 0) {
            int d = x%10;
            revNum = (revNum*10)+d;
            x = x/10;
        }
        if (copy == revNum) {
            return true;
        } else {
            return false;
        }
    }
}