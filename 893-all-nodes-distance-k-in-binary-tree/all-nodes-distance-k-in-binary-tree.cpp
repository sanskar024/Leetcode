/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
     unordered_map<TreeNode*, TreeNode*> mp;
     void parent(TreeNode* root){
        if(root==NULL)return;
        if(root->left){
            mp[root->left]=root;
        }
        parent(root->left);
        if(root->right!=NULL){
            mp[root->right]=root;
        }
        parent(root->right);
     }
    vector<int> distanceK(TreeNode* node, TreeNode* target, int k) {
  
      
       parent(node);
       queue<TreeNode*>q;
           vector<int>ans;
       int count=0;
       unordered_set<TreeNode*> vis;
       q.push(target);
           vis.insert(target);
       while(!q.empty()){
        int n=q.size();
        vector<int>level;
      
        for(int i=0;i<n;i++){
              TreeNode* root = q.front();
              q.pop();
               level.push_back(root->val);
            if(root->left&& !vis.count(root->left)){
                q.push(root->left);
                vis.insert(root->left);
                
            }
            if(root->right&&!vis.count(root->right)){
                q.push(root->right);
               vis.insert(root->right);
                
            }
            if(mp[root]&& !vis.count(mp[root])){
                q.push(mp[root]);
             vis.insert(mp[root]);
                 
            }
        }
       
        if(count==k){
            ans=level;
            break;
        }
         count++;
       }
    
   return ans; }
};