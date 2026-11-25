class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int i=0;
        vector<vector<int>> ans;
        while(i<points.size()){
            int start=points[i][0];
            int end=points[i][1];
            while(i+1<points.size() && points[i+1][0]<=end){
                i++;
                end=min(end,points[i][1]);
            }
            ans.push_back({start,end});
            i++;
        }
        return ans.size();
        
    }
};