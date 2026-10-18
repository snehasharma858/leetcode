class Solution {
public:
string findline(int i,int j,int eachgaddhaspace,int extraspacegaddhe,vector<string>& words,int maxWidth){
    string line;
    for(int k=i;k<j;k++){
        line+=words[k];

        if(k<j-1){
        for(int z=1;z<=eachgaddhaspace;z++){
            line+=" ";
        }
        }
        if(extraspacegaddhe>0){
            line+=" ";
            extraspacegaddhe--;
        }
    }
        
    while(line.length()<maxWidth){
            line+=" ";
    }


    return line;
}
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n=words.size();
        int i=0;
        while(i<n){
            int lettercount=words[i].length();
            int j=i+1;
            int gaddhe=0;
            while(j<n && words[j].length()+1+gaddhe+lettercount<=maxWidth){
                lettercount+=words[j].length();
                gaddhe+=1;
                j++;
            }
            int remaininggaddhe=maxWidth-lettercount;
            int eachgaddhaspace=gaddhe==0 ? 0 : remaininggaddhe/gaddhe;
            int extraspacegaddhe=gaddhe==0 ? 0 : remaininggaddhe%gaddhe;
            if(j==n){
                  eachgaddhaspace=1;
             extraspacegaddhe=0;
            }
            result.push_back(findline(i,j,eachgaddhaspace,extraspacegaddhe,words,maxWidth));
            i=j;
        }
        return result;
    }
};