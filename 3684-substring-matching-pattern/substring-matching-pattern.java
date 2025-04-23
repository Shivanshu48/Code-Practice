class Solution {
    public boolean hasMatch(String s, String p) {
        int starIndex = p.indexOf('*');
        String prefix = p.substring(0, starIndex);
        String suffix = p.substring(starIndex + 1);

        int minLength = prefix.length() + suffix.length();

        for (int i = 0; i <= s.length() - minLength; i++) {
            int end = i + minLength;
           
            while (end <= s.length()) {
                String sub = s.substring(i, end);
                if (sub.startsWith(prefix) && sub.endsWith(suffix)) {
                    return true;
                }
                end++;
            }
        }
        return false;
    }
}