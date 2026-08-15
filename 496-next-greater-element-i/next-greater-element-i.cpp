class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> mp;
        stack<int> st;

        // Find next greater element for every element in nums2
        for (int x : nums2) {

            while (!st.empty() && st.top() < x) {
                mp[st.top()] = x;
                st.pop();
            }

            st.push(x);
        }

        // Remaining elements have no greater element
        while (!st.empty()) {
            mp[st.top()] = -1;
            st.pop();
        }

        // Build answer for nums1
        vector<int> result;

        for (int x : nums1) {
            result.push_back(mp[x]);
        }

        return result;
    }
};