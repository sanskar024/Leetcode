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
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        queue<TreeNode*>q;
          if (root == nullptr) return ans;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            int maxval=INT_MIN;
            for(int i=0;i<size;i++){
                auto node=q.front();
                q.pop();
                maxval=max(maxval,node->val);
                if(node->left!=NULL)
                q.push(node->left);
                if(node->right!=NULL)
                q.push(node->right);
            
            }
                ans.push_back(maxval);
        }
   return ans; }
};