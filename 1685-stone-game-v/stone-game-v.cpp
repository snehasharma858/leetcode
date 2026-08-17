class Solution {
public:

    int solve(vector<int>& stoneValue,
              vector<vector<int>>& dp,
              vector<int>& prefix,
              int s, int e) {

        if (s == e)
            return 0;

        if (dp[s][e] != -1)
            return dp[s][e];

        int ans = 0;

        for (int k = s; k < e; k++) {

            int left = prefix[k + 1] - prefix[s];
            int right = prefix[e + 1] - prefix[k + 1];

            if (left < right) {

                ans = max(ans,
                          left + solve(stoneValue, dp, prefix, s, k));

            }
            else if (left > right) {

                ans = max(ans,
                          right + solve(stoneValue, dp, prefix, k + 1, e));

            }
            else {

                ans = max({
                    ans,
                    left + solve(stoneValue, dp, prefix, s, k),
                    right + solve(stoneValue, dp, prefix, k + 1, e)
                });
            }
        }

        return dp[s][e] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {

        int n = stoneValue.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(stoneValue, dp, prefix, 0, n - 1);
    }
};