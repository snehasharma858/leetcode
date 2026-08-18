class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        set<int> st;
        unordered_map<int,int> mp;
        int left=0;
        int i=0;
        int right=0;
       
        while (right < nums.size()) {
            
            st.insert(nums[right]);
            right++;
            i++;
            
           
            if (i == k) {

        for (auto it : st) {
            mp[it]++;
        }
           i=0;
           st.clear();
           left++;
           right=left;
            
        }
        }
        int ans=-1;
         for (auto j : mp) {
            if (j.second == 1) {
                ans = max(ans, j.first);
            }
        }
        return ans;


    }
};