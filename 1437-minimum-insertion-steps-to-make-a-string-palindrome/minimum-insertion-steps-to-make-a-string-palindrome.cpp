class Solution {
public:
 int solve(string &s, int i, int j,vector<vector<int>> &dp) {
        // Base case
        if (i >= j)
            return 0;

        // Characters match
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if (s[i] == s[j])
            return solve(s, i + 1, j - 1,dp);

        // Characters don't match
        dp[i][j]= 1 + min(solve(s, i + 1, j,dp),
                       solve(s, i, j - 1,dp));
                       return dp[i][j];
    }
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
      return solve(s,0,s.size()-1,dp);
    }
};