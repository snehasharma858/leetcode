class Solution {
public:
vector<int> zFunction(string s) {
    int n = s.size();
    vector<int> z(n);

    int L = 0, R = 0;

    for (int i = 1; i < n; i++) {

        if (i <= R)
            z[i] = min(R - i + 1, z[i - L]);

        while (i + z[i] < n &&
               s[z[i]] == s[i + z[i]])
            z[i]++;

        if (i + z[i] - 1 > R) {
            L = i;
            R = i + z[i] - 1;
        }
    }

    return z;
}
    long long sumScores(string s) {

        vector<int> z=zFunction(s);
          long long ans = s.size();
        for (int x : z)
            ans += x;

    return ans;
    }
};