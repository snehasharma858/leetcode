class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> rows(numRows);
        int currrow=0;
        int direction=1;
        if(numRows==1 || numRows>s.size()){
            return s;
        }
        for(int i=0;i<s.size();i++){
            rows[currrow]+=s[i];
            if(currrow==0){
                direction=1;
            }
            else if(currrow==numRows-1){
                direction=-1;
            }
            currrow+=direction;
            
            
        }
        string ans="";
        for(string row:rows){
            ans+=row;
        }
       return ans; 
    }

};