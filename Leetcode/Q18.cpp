//4sum.

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4) return {};

        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        for(int i=0;i<nums.size()-3;++i)
        {
            if(i-1 >= 0 && nums[i-1] == nums[i]) continue; //ȥ��
            for(int j = i+1;j<nums.size()-2;++j)
            {
                if(j-1 >= i+1 && nums[j-1] == nums[j]) continue; //ȥ�ص�˼·��Ϊ�˷�ֹ����������ͬ��ǰ׺,����Ӱ����ͬԪ�ؿ������.
                //if(nums[i]+nums[j] > target) continue; //��仰�Ǵ����,��Ϊ������ͻ�������sum��С.����[1,-2,-5,-4,-3,3,3,5],-11
                int p = j+1,q = nums.size() - 1;
                int t =  target - nums[i] - nums[j];
                while(p < q)
                {
                    cout << p << "," << q << endl;
                    if(nums[p] + nums[q] > t)
                    {
                        while(nums[q] == nums[q-1]) q--;
                        q--;
                    }
                    else if(nums[p] + nums[q] < t)
                    {
                        while(nums[p] == nums[p+1]) p++;
                        p++;
                    }
                    else
                    {
                        result.push_back({nums[i],nums[j],nums[p],nums[q]});
                        while(nums[q] == nums[q-1]) q--;
                        while(nums[p] == nums[p+1]) p++;
                        p++;q--;
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<int> test = {1,2,3,4,5,6,3,1,2,23,5,5};
    Solution s;
    s.fourSum(test,0);
    return 0;
}



//�ڶ���
//ȥ��˼·��3sum��ͬ
//ͬ��������Ȼ��̶�i,j,ͨ��two-pointerȷ��k,m
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4) return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        for(int i = 0;i<nums.size()-3;++i)
        {
            //��һλȥ��
            if(i-1 >= 0 && nums[i-1] == nums[i]) continue;
            for(int j = i+1;j<nums.size()-2;++j)
            {
                //�ڶ�λȥ��
                if(j-1 >= i+1 && nums[j-1] == nums[j]) continue;

                int sum = target - nums[i] - nums[j];
                int p = j+1;
                int q = nums.size()-1;
                while(p < q)
                {
                    if(nums[p] + nums[q] == sum)
                    {
                        result.push_back({nums[i],nums[j],nums[p],nums[q]});
                        //whileѭ������ȥ��
                        while(nums[q] == nums[q-1]) q--; //ѡ����q֮��q֮ǰ��nums[q]��ͬ�Ĳ�Ҫ
                        while(nums[p] == nums[p+1]) p++; //ͬ��
                        q--;p++; //
                    }
                    else if(nums[p] + nums[q] > sum)
                    {
                        while(nums[q] == nums[q-1]) q--; //��ͬ�Ĳ�����Ķ�ȥ��
                        q--;
                    }
                    else
                    {
                        while(nums[p] == nums[p+1]) p++;
                        p++;
                    }
                }
            }
        }
        return result;
    }
};