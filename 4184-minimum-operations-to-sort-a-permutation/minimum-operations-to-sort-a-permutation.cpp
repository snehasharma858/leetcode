
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int start = nums[0];

        bool increasing = true;
        bool decreasing = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] != (start + i) % n) {
                increasing = false;
            }

            if (nums[i] != (start - i + n) % n) {
                decreasing = false;
            }
        }

        if (increasing) {
            // Number of left rotations needed to bring 0 to front
            int k = (n - start) % n;

            // Direct rotations, or reverse-rotate-reverse
            return min(k, n - k + 2);
        }

        if (decreasing) {
            // After reversing, find the position of 0
            int k = n - 1 - start;

            // Reverse and rotate in the cheaper direction
            return min(k, n - k) + 1;
        }

        return -1;
    }
};
