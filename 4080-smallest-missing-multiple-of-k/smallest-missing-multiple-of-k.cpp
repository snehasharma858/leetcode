class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,bool> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=1;
        }
        int i=1;
       while (true) {
            int j = i * k;

            if (mp.find(j) == mp.end()) {
                return j;
            }

            i++;
        }
    }
};