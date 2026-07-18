/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void solve(TreeNode* point, string &s, vector<string> &ans){
     if(point == NULL)
            return;

       int len = s.size();  
       s += to_string(point->val);
        if(point->left == NULL && point->right == NULL) {
            ans.push_back(s);
        }

           else {
            s += "->";
            solve(point->left, s, ans);
            solve(point->right, s, ans);
        }
         s.resize(len);   

}
    vector<string> binaryTreePaths(TreeNode* root) {
         vector<string> ans;
        string s;

        solve(root, s, ans);

        return ans;
    }
};