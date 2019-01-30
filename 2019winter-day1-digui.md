# 题目

给定一个 N 叉树，找到其最大深度。

最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。

例如，给定一个 3叉树 :

# 思路

- 1. “自顶向下”的解决方案
> “自顶向下”意味着在每个递归层次上，我们首先访问节点以获得一些值，然后在调用递归函数时，将这些值传给子节点。

传递参数：子节点，answer

伪代码：
  1. 对于null 节点返回一个特定值
  2. 如果有需要对当前的answer进行更新
  3. for each child node root.child[k]
    ans[k] = top_down(root.child[k],new_params[k]);
  4. 如果有需要 ，返回答案answer
2. “自底向上”的解决方法

> "自底向上" 意味着在每个递归层次上，我们首先为每个子节点递归地调用函数，然后根据返回值和根节点本身的值给出相应结果。
伪代码:

1. 对于 null 节点返回一个特定值
2. for each child node root.children[k]:
3.    ans[k] = bottom_up(root.children[k]) // 为每个子节点递归地调用函数
4. 返回答案 answer  

```c++

```