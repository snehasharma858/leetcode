class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=haystack.size()-1;
        int n=needle.size()-1;
        for(int i=0;i<=m-n;i++){
            for(int j=0;j<=n;j++){
                if(haystack[i+j]!=needle[j]){
                    break;
                }
                if(j==n){
                    return i;
                }
            }
        }
        return -1;
        
    }
};