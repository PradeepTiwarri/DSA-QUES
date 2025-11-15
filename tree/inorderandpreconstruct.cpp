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
 void createmapping(vector<int>inorder,int size,map<int,int> &nodetoindex){
    for(int i=0;i<size;i++){
        nodetoindex[inorder[i]]= i;
    }
 }
    TreeNode * solve(vector<int>&inorder,vector<int> &postorder,int &index,int inorderstart,int inorderend,int size,map<int,int> &nodetoindex){
        if(index<0 || inorderstart > inorderend){
            return NULL;
        }

        int  element =postorder[index--];
        TreeNode* root= new TreeNode(element);
        int position = nodetoindex[element];

        root->right= solve(inorder,postorder,index,position+1,inorderend,size,nodetoindex);
        root->left= solve(inorder,postorder,index,inorderstart,position-1,size,nodetoindex);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int size= inorder.size();
        int postorderindex=size-1;
        map<int,int>nodetoindex;
        createmapping(inorder,size,nodetoindex);
        TreeNode* ans= solve(inorder,postorder,postorderindex,0,size-1,size,nodetoindex);
        return ans;
    }
};