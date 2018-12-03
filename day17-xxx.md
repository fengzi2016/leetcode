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
      int min(TreeNode* root) {
        while(root->left) {
            root = root->left;
        }
        return root->val;
    }
    int max(TreeNode* root) {
        while(root->right){
            root = root -> right;
        }
        return root->val;
    }
    bool isValidBST(TreeNode* root) {
       
        bool left = true;
        bool right = true;
        if(root) {
            int val = root->val;
            if(root -> left){
                left = isValidBST(root->left) && (val>max(root->left));
            }
            if(root -> right) {
          
               right = isValidBST(root->right)&&(val<min(root->right));
        
             }
        if (!root->left && !root->right) {
                return true;
        }
        return left&&right;
     }
     return true;
    }
  
};