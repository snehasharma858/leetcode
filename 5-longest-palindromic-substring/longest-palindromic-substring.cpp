class Solution {
public:
bool palindrome(string &a,int i,int j){
    
    while(i<=j){
        if(a[i]!=a[j]){
            
          
            return false;
        }
            i++;
            j--;
    }
    return true;
}


    string longestPalindrome(string s) {
    pair<int,string> ans={0,""};
    for(int i=0;i<s.size();i++){
        for(int j=i;j<s.size();j++){
            if(palindrome(s,i,j)){
                if(ans.first<j-i+1){
                    ans.first=j-i+1;
                    ans.second=s.substr(i,j-i+1);
                }
               
            }
        }
    }
    return ans.second;

    }
};