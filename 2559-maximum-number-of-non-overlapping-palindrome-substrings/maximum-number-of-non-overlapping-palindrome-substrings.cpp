class Solution {
    public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Find all palindromes
        for (int i = 0; i < n; i++) {
            for (int l = i, r = i; l >= 0 && r < n && s[l] == s[r]; l--, r++)
            pal[l][r] = true;

            for (int l = i, r = i + 1; l >= 0 && r < n && s[l] == s[r]; l--, r++)
            pal[l][r] = true;
        }

        // DP
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];

            for (int j = 0; j < i; j++) {
                if (i - j >= k && pal[j][i - 1])
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        return dp[n];
    }
};
          