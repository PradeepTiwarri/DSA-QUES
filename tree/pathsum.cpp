/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool sumcheck(TreeNode* root,int sum,int targetsum){
        
        if(root==NULL){
        return false;
        }
        if(root->left==NULL && root->right==NULL){
             sum+=root->val;
            if(sum==targetsum){
                return true;
            }
            else{
                return false;
            }
        }
        sum+=root->val;
      bool leftans=  sumcheck(root->left,sum,targetsum);
      bool rightans= sumcheck(root->right,sum,targetsum);
      if(leftans==true || rightans==true){
        return true;
      }  
      else{
       return false;
      }
      
    }


     
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        bool ans =sumcheck(root,sum,targetSum);
        return ans;
    }
};

