// Assign Cookies
// ÿ�����Ӷ�cookier�Ĵ�С����͵�����g_i,ÿ�����ɴ�СΪs_j
// �Ի��ںͱ��ɷֱ�����
//ÿ�ξ����ܸ�����С�ĺ��ӣ�ʹ������ĺ�����ࡣ��Ϊ���������С�ĺ��Ӷ��������㣬�����������������ĺ��ӡ�
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int k = g.size() < s.size() ? g.size():s.size();
        int i=0,j=0;
        while(i<k&&j<k)
        {
            if(s[k] >= g[k])
            {
                i++;j++;
            }
            else
            {
                j++;
            }
        }
        return i; //���һ��������ĺ���Ϊi-1���ܸ���Ϊi
    }
};