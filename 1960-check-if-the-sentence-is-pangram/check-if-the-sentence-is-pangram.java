class Solution {
    public boolean checkIfPangram(String sentence) {
        boolean[] check = new boolean[26];
        for (int i = 0; i < sentence.length(); i++) {
            char c = sentence.charAt(i);
            check[c - 'a'] = true;
        }
        for (boolean letterSeen : check) {
            if (!letterSeen) {
                return false;
            }
        }
        return true;
    }
}