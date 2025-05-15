class Solution {
    public int romanToInt(String s) {
         Map<Character, Integer> romanMap = new HashMap<>();
        romanMap.put('I', 1);
        romanMap.put('V', 5);
        romanMap.put('X', 10);
        romanMap.put('L', 50);
        romanMap.put('C', 100);
        romanMap.put('D', 500);
        romanMap.put('M', 1000);

        int total = 0;
        int prevValue = 0;

        // Iterate from the end of the string to the beginning
        for (int i = s.length() - 1; i >= 0; i--) {
            int currentValue = romanMap.get(s.charAt(i));

            // If the current value is smaller than the previous one, we subtract
            if (currentValue < prevValue) {
                total -= currentValue;
            } else {
                // Otherwise, we add
                total += currentValue;
            }

            prevValue = currentValue;
        }

        return total;
    }
}