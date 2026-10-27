class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0;i<board.size();i++){
            unordered_map<char, int> mp;
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == '.') continue;
                mp[board[i][j]]++;
                if(mp[board[i][j]]>=2){
                    return false;
                }
                
            }
        }
        for(int i=0;i<board[0].size();i++){
            unordered_map<char, int> mp;
            for(int j=0;j<board.size();j++){
                
                 if(board[j][i] == '.') continue;
                mp[board[j][i]]++;
                if(mp[board[j][i]]>=2){
                    return false;
                }
                
            }
        }
        for(int r=0;r<9;r+=3){
            for(int c=0;c<9;c+=3){
                unordered_map<char, int> mp;
                for(int i=r;i<r+3;i++){
                    for(int j=c;j<c+3;j++){
                        if(board[i][j]=='.') continue;

                     mp[board[i][j]]++;
                     if(mp[board[i][j]]>=2){
                        return false;
                     }
                    }
                   
                }
            }
        }
        return true;
        
    }
};