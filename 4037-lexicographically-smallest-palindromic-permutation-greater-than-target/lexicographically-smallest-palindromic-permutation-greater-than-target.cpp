class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        // Check if a palindrome is possible
        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                odd++;
                mid = 'a' + i;
            }
        }

        if (odd > 1)
            return "";

        // Counts for the left half
        vector<int> cnt(26);
        for (int i = 0; i < 26; i++)
            cnt[i] = freq[i] / 2;

        int m = n / 2;
        string left;

        // Build the smallest string using remaining characters
        auto build = [&](string half, vector<int> remaining) {
            for (int i = 0; i < 26; i++) {
                while (remaining[i]--) {
                    half += char('a' + i);
                }
            }

            string ans = half;

            if (n % 2)
                ans += mid;

            string right = half;
            reverse(right.begin(), right.end());
            ans += right;

            return ans;
        };

        // Match target's left half
        for (int i = 0; i < m; i++) {
            int x = target[i] - 'a';

            // Can match target[i]
            if (cnt[x] > 0) {
                left += target[i];
                cnt[x]--;
            } else {
                // Cannot match: choose smallest character > target[i]
                for (int c = x + 1; c < 26; c++) {
                    if (cnt[c] > 0) {
                        left += char('a' + c);
                        cnt[c]--;

                        return build(left, cnt);
                    }
                }

                // Need to backtrack
                break;
            }
        }

        // If we matched the complete left half
        if ((int)left.size() == m) {
            string candidate = left;

            if (n % 2)
                candidate += mid;

            string right = left;
            reverse(right.begin(), right.end());
            candidate += right;

            if (candidate > target)
                return candidate;
        }

        // Backtrack: increase one previous character
        for (int pos = (int)left.size() - 1; pos >= 0; pos--) {
            int old = left[pos] - 'a';
            cnt[old]++;

            for (int c = old + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    string prefix = left.substr(0, pos);
                    prefix += char('a' + c);

                    cnt[c]--;

                    return build(prefix, cnt);
                }
            }
        }

        return "";
    }
};