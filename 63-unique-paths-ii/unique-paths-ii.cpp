class Solution {
public:
int solve(vector<vector<int>>& obstacleGrid,int &count ,int i,int j,vector<vector<int>> &dp){
    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();
   
    if(i>=m || j>=n|| obstacleGrid[i][j] == 1){
        return 0;
    }
    if(dp[i][j]!=0){
        return dp[i][j];
    }
     if(i==m-1 && j==n-1){
       
        return 1;
    }
int right=0;
    if(j + 1 < n && obstacleGrid[i][j+1]==0){
        right=solve(obstacleGrid,count,i,j+1,dp);
    }
    int down=0;
    if(i + 1 < m && obstacleGrid[i+1][j]==0){
       down=  solve(obstacleGrid,count,i+1,j,dp);

    }
    return dp[i][j]=right+down;

}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int count=0;
          int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();
         if (obstacleGrid[0][0] == 1)
            return 0;
        vector<vector<int>> dp(m,vector<int> (n,0));
        
        return solve(obstacleGrid,count,0,0,dp);
        
    }
};