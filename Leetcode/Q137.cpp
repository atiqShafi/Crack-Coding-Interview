//���������������Σ�����һ��������һ��

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i=0;i<=31;i++)
        {
            int s = 0;
            for(int j=0;j<nums.size();j++)
            {
                s+=(nums[j] && 1 << i);
                if(s%3 == 1) result+=(1 << i);
            }
        }
        return result;
    }
};