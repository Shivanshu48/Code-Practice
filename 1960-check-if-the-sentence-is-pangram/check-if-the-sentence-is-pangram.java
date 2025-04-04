class Solution {
    public boolean checkIfPangram(String sentence) {
        Set<Character> letters = new HashSet<>();
        for (char c : sentence.toCharArray()) {
            if (c >= 'a' && c <= 'z') {
                letters.add(c);
            }
        }
        return letters.size() == 26;
    }
}