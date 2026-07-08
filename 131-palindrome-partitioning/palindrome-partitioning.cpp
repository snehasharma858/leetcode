class Solution {
public:
 bool palindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
void solve(string &s,int index,vector<string> &temp,vector<vector<string>> &ans){
    if(index>=s.length()){
       ans.push_back(temp);
    }

    for(int i=index;i<s.length();i++){
        if(palindrome(s,index,i)){
            temp.push_back(s.substr(index,i-index+1));
            solve(s,i + 1,  temp, ans);

                temp.pop_back();

        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s,0,temp,ans);
        return ans;

    }
};