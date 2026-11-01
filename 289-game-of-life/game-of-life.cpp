class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

       

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int count=0;
                for(int x= -1;x<=1;x++){
                    for(int y=-1;y<=1;y++){
                        if(x==0 && y==0){
                            continue;}

                        int r=x+i;
                        int c=y+j;
                        if(r >= 0 && r < m && c >= 0 && c < n){
                            if(board[r][c]==1 || board[r][c]==2){
                                count++;
                            }
                        }
                    }
                }
                if(board[i][j]==1){
                     if(count < 2 || count > 3) {
                        board[i][j] = 2;
                    }
                }
                 else if(board[i][j] == 0) {

                   
                    if(count == 3) {
                        board[i][j] = 3;
                    }

            }
            }
        }
         for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(board[i][j] == 2) {
                    board[i][j] = 0;
                }
                else if(board[i][j] == 3) {
                    board[i][j] = 1;
                }
            }
        }
    }
};