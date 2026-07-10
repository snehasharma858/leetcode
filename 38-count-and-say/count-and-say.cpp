class Solution {
public:
string runencoding(string &s){
     string ans = "";
        int count = 1;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                ans += to_string(count);
                ans += s[i - 1];
                count = 1;
            }
        }

        // Add the last group
        ans += to_string(count);
        ans += s.back();

        return ans;
    


}
string solve(int n){
    if(n==1){
        return "1";
    }

    string s=solve(n-1);
    return runencoding(s) ;
}
    string countAndSay(int n) {
    string ans;
    return solve(n);
    
    }
};