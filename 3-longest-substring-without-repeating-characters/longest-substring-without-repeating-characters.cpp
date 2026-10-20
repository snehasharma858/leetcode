class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int ans=0;
        unordered_map<char,bool> mp;
        int right=0;

        for(right;right<s.size();right++){
            if(mp[s[right]]==1){
                while(mp[s[right]]==1){
                    mp[s[left]]=0;
                    left++;
                }

            }
            
            mp[s[right]]=1;
            ans = max(ans, right - left + 1);
            

        }
      
        return ans;
    }
};