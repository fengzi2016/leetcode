# 二叉树的后序遍历
给定一个二叉树，返回它的 后序 遍历。

示例:

输入: [1,null,2,3]  

    1

      \
     
       2

    /

    3 

输出: [3,2,1]

# 思路
- 递归。

```c++
    void __postorderTraversal(TreeNode* node, vector<int> &res){

        if( node ){
            __postorderTraversal(node->left, res);
            __postorderTraversal(node->right, res);
            res.push_back(node->val);
        }
    }

```

