class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string ans;
        int i=0;
        while(i<path.size()){
            string temp="";
            while(i<path.size() && path[i]=='/'){
                i++;
            }
            //read one folder name 
            while(i<path.size() && path[i]!='/'){
                temp+=path[i];
                i++;
            }
            if(temp=="." || temp==""){
                continue;
            }
            else if(temp==".."){
                if (!st.empty()) {
                    st.pop();
                }
            }
             else {
                st.push(temp);
            }
        }
        while(!st.empty()){
            ans='/'+st.top()+ans;
            st.pop();
        }
        if(ans==""){
            return "/";
        }
        return ans;
    }
};