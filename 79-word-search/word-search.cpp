class Solution {
public:
bool solve(vector<vector<char>>& board,string &word,int i,int j,int k){
   if(k == word.size()){
    return true;}
    if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()){
    return false;
    }
    if(board[i][j]!=word[k]){
        return false;
    }
    char ch = board[i][j];
    board[i][j] = '#';
    bool left=solve(board,word,i-1,j,k+1);
    bool right=solve(board,word,i+1,j,k+1);
    bool up=solve(board,word,i,j-1,k+1);
    bool down=solve(board,word,i,j+1,k+1);
    board[i][j] = ch;
    return left || right || up || down;

}
    bool exist(vector<vector<char>>& board, string word) {
    for(int i = 0; i < board.size(); i++) {
    for(int j = 0; j < board[0].size(); j++) {

        if(solve(board, word, i, j, 0))
            return true;
    }
}
return false;
    }
};