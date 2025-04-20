class Solution {
    public String sortSentence(String s) {
        String[] words = s.split(" ");
        String[] result = new String[words.length];
        for (String word : words) {
            int len = word.length();
            int pos = word.charAt(len - 1) - '1';
            result[pos] = word.substring(0, len - 1);
        }
        return String.join(" ", result);
    }
}