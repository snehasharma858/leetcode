class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        map<pair<int,int>,int> mp;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                mp[{i,j}]=matrix[i][j];
            }
        }        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(mp[{i,j}]==0){
                    for(int k=0;k<n;k++){
                        matrix[k][j]=0;
                    }
                    for(int m=0;m<matrix[0].size();m++){
                        matrix[i][m]=0;
                    }
                }
            }
        }
    }
};