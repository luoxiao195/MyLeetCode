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
        int rob(TreeNode* root) {
        if(root==NULL)
			return 0;
		Money sum=dfs(root);
		return sum.curr;
    }
	struct Money
	{
		int pre;
		int curr;
		Money():pre(0),curr(0){}
	};
	Money dfs(TreeNode * root)
	{
		if(root==NULL)
			return Money();
		Money left=dfs(root->left);
		Money right=dfs(root->right);
		
		Money sum;
		sum.pre=left.curr+right.curr;
		sum.curr=max(root->val+left.pre+right.pre,sum.pre);
		return sum;
	}
};