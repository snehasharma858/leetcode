class Solution {
public:
int solve(vector<int>& nums,int i,vector<int> &dp){
    if(i>=nums.size()-1){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int ans=INT_MAX;
    for(int j=1;j<=nums[i];j++){

       
        if(i+j<nums.size()){
           int next = solve(nums, i + j,dp);

                if (next != INT_MAX) {
                    int jump = 1 + next;
                    ans = min(ans, jump);}
             
        }
       
    }
    dp[i]=ans;
    return dp[i];
}
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solve(nums,0,dp);
    }
};