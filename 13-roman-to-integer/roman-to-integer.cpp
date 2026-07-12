class Solution {
public:
    int romanToInt(string s) {
    unordered_map<char,int> mp;
      mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
    int sum=mp[s[0]];
    for(int i=1;i<s.size();i++){
        if(mp[s[i]]<=mp[s[i-1]]){
            sum+=mp[s[i]];
        }
        else{
             sum = sum - 2 * mp[s[i-1]] + mp[s[i]];
        }
    }
return sum;
    }
};