class Solution {
    public int[][] flipAndInvertImage(int[][] image) {
        int lr=image.length;
        int[][] arr=new int[lr][lr];
        for(int i=0;i<lr;i++)
        {
            int lc=image[i].length;
            for(int j=0;j<image[i].length;j++)
            {
                lc--;
                arr[i][j]=image[i][lc];
            }

            for(int j=0;j<image[i].length;j++)
            {
                if(arr[i][j]==1)
                {
                    arr[i][j]=0;
                }
                else
                {
                    arr[i][j]=1;
                }
            }
        }
        return arr;
    }
}