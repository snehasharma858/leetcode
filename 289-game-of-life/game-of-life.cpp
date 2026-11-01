class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> temp = board;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                int count = 0;

                if(i-1>=0 && j-1>=0 && temp[i-1][j-1]==1) count++;
                if(i-1>=0 && temp[i-1][j]==1) count++;
                if(j-1>=0 && temp[i][j-1]==1) count++;
                if(i+1<m && j+1<n && temp[i+1][j+1]==1) count++;
                if(i+1<m && temp[i+1][j]==1) count++;
                if(j+1<n && temp[i][j+1]==1) count++;
                if(i-1>=0 && j+1<n && temp[i-1][j+1]==1) count++;
                if(i+1<m && j-1>=0 && temp[i+1][j-1]==1) count++;

                if(temp[i][j] == 1) {
                    if(count < 2 || count > 3) {
                        board[i][j] = 0;
                    }
                }
                else {
                    if(count == 3) {
                        board[i][j] = 1;
                    }
                }
            }
        }
    }
};