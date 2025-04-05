class Solution {
    public int maximumPopulation(int[][] logs) {
        int[] yearCount = new int[101];
        for (int[] log : logs) {
            int birth = log[0];
            int death = log[1];
            yearCount[birth - 1950] += 1;
            yearCount[death - 1950] -= 1;
        }
        int maxPopulation = 0;
        int earliestYear = 1950;
        int currentPopulation = 0;
        for (int i = 0; i < yearCount.length; i++) {
            currentPopulation += yearCount[i];
            if (currentPopulation > maxPopulation) {
                maxPopulation = currentPopulation;
                earliestYear = 1950 + i;
            }
        }
        return earliestYear;
    }
}