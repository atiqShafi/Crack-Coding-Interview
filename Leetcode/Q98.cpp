//�ж�һ��tree�ǲ���BST��������������
//BST���ʣ�
//(1)һ�ÿ���
//(2)�����������գ��������������ҵĽڵ�ֵ��С�ڸ��ڵ��ֵ
//(3)�����������գ��������������ҵĽڵ�ֵ��С�ڸ��ڵ��ֵ

//depth-first

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        int tmax,tmin;
        tmax = INT_MIN;
        tmin = INT_MAX;
    }

    bool solve(TreeNode *root,int &tmax,int &tmin)
    {
        if(root == NULL)
        {
            return true;
        }
        else
        {
            int lmax=tmax,lmin=tmin;
            bool l = solve(root->left,lmax,lmin);
            if(l && lmax < root->val)
            {
                int rmax = tmax,rmin = tmin;
                bool r = solve(root->right,rmax,rmin);
                if(r && rin > root->val)
                {
                    tmax = max(max(lmax,rmax),root->val);
                    tmin = min(min(lmin,rmin),root->val);
                    return true;
                }
                else return false;
            }
            else return false;
        }
    }
};


[2,1,3]
[1,2,3]
[6,5,8,3,6]
[]
[0,0]
[10,7,9,3,9,6]
[10,7,9,3,9,6,9]
[2147483647]