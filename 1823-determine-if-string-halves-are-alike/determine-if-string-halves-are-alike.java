class Solution {
    public boolean halvesAreAlike(String s) {
       int n = s.length();
        String a = s.substring(0, n / 2);
        String b = s.substring(n / 2);

        return countVowels(a) == countVowels(b);
    }

    private static int countVowels(String str) {
        Set<Character> vowels = new HashSet<>(Arrays.asList(
            'a', 'e', 'i', 'o', 'u',
            'A', 'E', 'I', 'O', 'U'
        ));
        
        int count = 0;
        for (char c : str.toCharArray()) {
            if (vowels.contains(c)) {
                count++;
            }
        }
        return count;
    } 
}