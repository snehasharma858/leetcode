class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()){
            return "";
        }
        unordered_map<char,int> mp;
        for(auto ch:t){
            mp[ch]++;
        }
        int i=0,j=0;
        int countreq=t.size();
        int minwindow=INT_MAX;
        int start=0;
        while(j<s.size()){
            char ch=s[j];
            mp[ch]--;
            if(mp[ch]>=0){
                countreq--;
            }
            while(countreq==0){
                int currwindow=j-i+1;
                
                if (currwindow < minwindow) {
                    minwindow = currwindow;
                    start = i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    countreq++;
                }
                i++;
             
            }
            j++;     
            
        }
        if(minwindow==INT_MAX){
            return "";
        }
        return s.substr(start,minwindow);

    }
};