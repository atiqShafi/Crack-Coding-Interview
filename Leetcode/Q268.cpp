//����һ��ȱʧ����,0~nȱ��һ�������������0~n����ת��Ϊ�ж�������������Σ�һ������һ�Σ�
//ʹ�������

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = 0;
        int i=0;
        for(i=0;i<nums.size();i++)
        {
            result^= nums[i];
            result^= i;
        }
        result^=i;
        return result;
    }
};