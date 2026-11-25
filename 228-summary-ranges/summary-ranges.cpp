class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int i=0;
    
       while(i<nums.size()){
            string st = to_string(nums[i]);
            
            int start = nums[i];
            while (i + 1 < nums.size() && nums[i + 1] == nums[i] + 1) {
                i++;
            }
             if (start != nums[i]) {
                st += "->";
                st += to_string(nums[i]);
            }
            ans.push_back(st);
            i++;
            


        }

return ans;
        
    }
};