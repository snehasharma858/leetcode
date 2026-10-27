class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        unordered_map<string,int> mp;
        for(string word: words){
            mp[word]++;
        }
        int n=words.size();
        int len=words[0].size();
        for(int i=0;i<len;i++){
            int left=i;
            int count=0;
            unordered_map<string,int> curr;
            for(int right=i;right+len<=s.size();right+=len){
                string word = s.substr(right, len);
                // Word is not present in the given words
                if (mp.find(word) == mp.end()){
                    curr.clear();
                    count=0;
                    left=right+len;

                }
                else{
                    curr[word]++;
                    count++;
                    while(curr[word]>mp[word]){
                        string leftWord = s.substr(left, len);
                        curr[leftWord]--;
                        left += len;
                        count--;
                    }
                     if (count == n) {
                        ans.push_back(left);

                        // Move left forward to search for another match
                        string leftWord = s.substr(left, len);
                        curr[leftWord]--;
                        left += len;
                        count--;
                    }
                }

            }

        }
        
        return ans;
    }
};