class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int count=0;
        for(int num:st){
            if(st.find(num-1)==st.end()){
                int temp=1;
                while(st.find(num+temp)!=st.end()){
                    temp++;
                }
                count=max(count,temp);
            }
            

        }

        return count;
    }
};