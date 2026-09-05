class Solution {
public:
int findmax(vector<int>& nums,int i){
    int maxi=INT_MIN;
    for(int j=0;j<=i;j++){
        maxi=max(maxi,nums[j]);
    }
    return maxi;

}
int findmin(vector<int>& nums,int i){
    int mini=INT_MAX;
    for(int j=i;j<=nums.size()-1;j++){
        mini=min(mini,nums[j]);
    }
    return mini;

}

    int firstStableIndex(vector<int>& nums, int k) {
       for(int i=0;i<nums.size();i++){
        if((findmax(nums,i)-findmin(nums,i)) <=k){
            return i;
        }
       }
       return -1;
    }
};