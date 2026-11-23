class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mp1;
        unordered_map<string,char> mp2;
        int j=0;
        for(int i=0;i<pattern.size();i++){
            string word="";
            while(j<s.size() && s[j]!=' '){
                    word+=s[j];
                    j++;
                }
                if(word==""){
                return false;
            }
            if(mp1.find(pattern[i])!=mp1.end()){
                
                if(mp1[pattern[i]]!=word){
                    return false;
                }
                
            }
            else{
                mp1[pattern[i]]=word;
            }
            
            if(j<s.size()){
                j++;
            }
        }
       for(auto it:mp1){
        if(mp2.find(it.second)!=mp2.end()){
            if(mp2[it.second]!=it.first){
                return false;
            }
        }
        else{
            mp2[it.second]=it.first;
        }

       }
       if(j < s.size()){
            return false;
        }
        return true;
    }
};