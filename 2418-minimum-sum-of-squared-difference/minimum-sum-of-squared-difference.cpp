
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        vector<int> diff(n);
        int maxi = 0;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxi = max(maxi, diff[i]);
            sum += diff[i];
        }

        if (k >= sum) return 0;

        int low = 0, high = maxi;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long need = 0;

            for (int x : diff) {
                if (x > mid)
                    need += x - mid;
            }

            if (need <= k)
                high = mid;
            else
                low = mid + 1;
        }

        long long ans = 0;
        long long used = 0;

        for (int x : diff) {
            int reduced = min(x, low);
            ans += 1LL * reduced * reduced;

            if (x > low)
                used += x - low;
        }

        long long remaining = k - used;

        for (int x : diff) {
            if (remaining == 0) break;

            if (x >= low && x > 0) {
                ans -= 1LL * low * low;
                ans += 1LL * (low - 1) * (low - 1);
                remaining--;
            }
        }

        return ans;
    }
};
