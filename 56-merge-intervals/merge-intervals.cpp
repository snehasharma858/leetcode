class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int i=0;
       while(i<intervals.size()){
           
            int start = intervals[i][0];
            int end = intervals[i][1];
            while(i+1<intervals.size() && intervals[i+1][0]<=end){
                i++;
                end=max(end,intervals[i][1]);
            }
            ans.push_back({start, end});
            i++;

        }
        return ans;
    }
};