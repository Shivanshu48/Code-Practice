class Solution {
    public int[] closestDivisors(int num) {
         int[] res1 = findClosestDivisors(num + 1);
        int[] res2 = findClosestDivisors(num + 2);

        // Choose the one with the smaller absolute difference
        if (Math.abs(res1[0] - res1[1]) <= Math.abs(res2[0] - res2[1])) {
            return res1;
        } else {
            return res2;
        }
    }

    private int[] findClosestDivisors(int target) {
        int sqrt = (int) Math.sqrt(target);
        for (int i = sqrt; i >= 1; i--) {
            if (target % i == 0) {
                return new int[]{i, target / i};
            }
        }
        return new int[]{};
    }
}