class Solution {
    public int largestAltitude(int[] gain) {
        int maxal=0;
        int currgain=0;
        for(int i=0;i<gain.length;i++)
        {
            currgain+=gain[i];
            maxal=Math.max(maxal,currgain);
        }
        return maxal;
    }
}