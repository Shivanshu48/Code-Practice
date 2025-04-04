class Solution {
    public int diagonalSum(int[][] mat) {
        int leftd=0,rigd=0;
        for(int i=0;i<mat.length;i++)
        {
            for(int j=0;j<mat.length;j++)
            {
                if(i==j)
                {
                    leftd+=mat[i][j];
                }
                if((i+j==mat.length-1) && i!=j)
                {
                    rigd+=mat[i][j];
                }
            }
        }
        return (leftd+rigd);
    }
}