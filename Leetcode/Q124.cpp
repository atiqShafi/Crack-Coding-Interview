//124. Binary Tree Maximum Path Sum

//��Ϊ�������ͬʱ��������������Ϊ�ж��Ƿ�������������������Ե����ϵķ�ʽ��
//��Ŀ����˼������ͨ��·�������Դ�����������������·��
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
    int maxPathSum(TreeNode* root) {
        result = INT_MIN;
        solve(root);
        return result;
    }
    int result;
    int solve(TreeNode * root) //sum��ʾ����ǰroot�ڵ�ʱ���ܺͣ���ĳ���㿪ʼ���ýڵ㣬���Կ����ýڵ����ֵ��
    {
        if(root==NULL) return 0;
        int l = solve(root->left);
        int r = solve(root->right);
        int s = l + r;
        int sum = root->val;
        if(l <=0 && r<=0)
        {
            if(result < sum) result = sum;
            return sum;
        }
        else
        {
            if(l > 0 && r > 0) sum+=s;
            else sum+=max(l,r);
            if(result < sum) result = sum;
            return root->val+max(l,r);
        }
    }
};


[1,2,3]
[-5,0,0]
[3,6,8,-10,3,5,3,null,6,-7,null,null,10,-21]
[3,5,3,null,6,-7,null,null,10,5,3,2,null,4,null,1,34,0,0,null,34,0,0,0,1,43,34,9,0,8,0]
[0,0,0,-1,0,0]
[1,-2,3]