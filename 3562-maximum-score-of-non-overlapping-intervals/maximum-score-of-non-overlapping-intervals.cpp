class Solution {
public:
    struct State {
        long long score = 0;
        vector<int> ids;
    };

    // Returns true if a is lexicographically smaller than b
    bool smaller(const vector<int>& a, const vector<int>& b) {
        return lexicographical_compare(
            a.begin(), a.end(),
            b.begin(), b.end()
        );
    }

    State better(State a, State b) {
        if (a.score != b.score)
            return (a.score > b.score ? a : b);

        return smaller(a.ids, b.ids) ? a : b;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // {right, left, weight, original_index}
        vector<array<long long, 4>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({
                intervals[i][1],
                intervals[i][0],
                intervals[i][2],
                i
            });
        }

        // Sort by right endpoint
        sort(v.begin(), v.end());

        // Right endpoints for binary search
        vector<long long> rights(n);
        for (int i = 0; i < n; i++)
            rights[i] = v[i][0];

        // p[i] = number of intervals before i that end
        // strictly before interval i starts
        vector<int> p(n);

        for (int i = 0; i < n; i++) {
            long long left = v[i][1];

            // first right >= left
            int pos = lower_bound(rights.begin(), rights.begin() + i, left)
                      - rights.begin();

            p[i] = pos;
        }

        // dp[i][k]:
        // first i intervals, at most k selected
        vector<vector<State>> dp(n + 1, vector<State>(5));

        for (int i = 1; i <= n; i++) {
            int idx = i - 1;

            for (int k = 1; k <= 4; k++) {

                // Option 1: don't take this interval
                State skip = dp[i - 1][k];

                // Option 2: take this interval
                State take;

                take.score =
                    v[idx][2] + dp[p[idx]][k - 1].score;

                take.ids = dp[p[idx]][k - 1].ids;
                take.ids.push_back((int)v[idx][3]);

                // We need the indices sorted because the final answer
                // is compared lexicographically.
                sort(take.ids.begin(), take.ids.end());

                dp[i][k] = better(skip, take);
            }
        }

        return dp[n][4].ids;
    }
};