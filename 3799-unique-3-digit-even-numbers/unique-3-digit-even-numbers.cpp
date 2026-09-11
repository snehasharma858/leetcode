class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);

        for (int d : digits)
            freq[d]++;

        int ans = 0;

        for (int num = 100; num <= 998; num += 2) {
            int x = num;

            int c = x % 10;       // ones
            x /= 10;
            int b = x % 10;       // tens
            x /= 10;
            int a = x;            // hundreds

            vector<int> need(10, 0);
            need[a]++;
            need[b]++;
            need[c]++;

            bool possible = true;

            for (int d = 0; d <= 9; d++) {
                if (need[d] > freq[d]) {
                    possible = false;
                    break;
                }
            }

            if (possible)
                ans++;
        }

        return ans;
    }
};