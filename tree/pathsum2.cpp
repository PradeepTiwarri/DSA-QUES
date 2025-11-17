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
    void sumcheck(TreeNode* root,int targetsum,int sum,vector<int>&level,vector<vector<int>>& ans){
      if(root==NULL){
        return ;
      }
      sum+=root->val;
      level.push_back(root->val);
      if(root->right==NULL && root->left==NULL){
        
        if(sum==targetsum){
            
            ans.push_back(level);
            
        }
        level.pop_back();
        return ;
        
      }
     
     
      sumcheck(root->left,targetsum,sum,level,ans);
      sumcheck(root->right,targetsum,sum,level,ans);

      level.pop_back();
      

      
}

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum=0;
        vector<int>level;
        vector<vector<int>> ans;
        sumcheck(root,targetSum,sum,level,ans);
        
        return ans;
    }
};