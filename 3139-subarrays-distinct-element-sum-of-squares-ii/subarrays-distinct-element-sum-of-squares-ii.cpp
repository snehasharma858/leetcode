
class Solution {
public:
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum = 0;
        long long sq = 0;
        long long lazy = 0;
    };

    vector<Node> seg;

    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;

        seg[node].sq = (
            seg[node].sq
            + 2LL * val % MOD * seg[node].sum % MOD
            + len % MOD * val % MOD * val % MOD
        ) % MOD;

        seg[node].sum =
            (seg[node].sum + len * val) % MOD;

        seg[node].lazy =
            (seg[node].lazy + val) % MOD;
    }

    void push(int node, int l, int r) {
        if (seg[node].lazy == 0 || l == r)
            return;

        int mid = (l + r) / 2;

        apply(node * 2, l, mid, seg[node].lazy);
        apply(node * 2 + 1, mid + 1, r, seg[node].lazy);

        seg[node].lazy = 0;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, 1);
            return;
        }

        push(node, l, r);

        int mid = (l + r) / 2;

        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);

        seg[node].sum =
            (seg[node * 2].sum + seg[node * 2 + 1].sum) % MOD;

        seg[node].sq =
            (seg[node * 2].sq + seg[node * 2 + 1].sq) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        seg.assign(4 * n, Node());
        vector<int> last(100001, -1);

        long long ans = 0;

        for (int j = 0; j < n; j++) {
            int prev = last[nums[j]];

            update(1, 0, n - 1, prev + 1, j);

            // Root stores the sum of squares for
            // all subarrays ending at index j.
            ans = (ans + seg[1].sq) % MOD;

            last[nums[j]] = j;
        }

        return ans;
    }
};
