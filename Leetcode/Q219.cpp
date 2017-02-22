class Solution {
public:
//�˷������⣺nums.end()-k,�����k������δ���в���
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k >= nums.size()) k = nums.size()-1; //����Ĳ�ֵ���Ϊsize-1
        for(auto it=nums.begin();it!=nums.end()-k;++it)
        {
            if(find(it+1,it+k+1,*it) != (it+k+1)) return true;
        }
        return false;
    }

    //AC
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       map<int,int>dict;
       for(int i=0;i<nums.size();++i)
       {
            if(dict.find(nums[i]) == dict.end()) //���û��¼
                dict[nums[i]]=i;
            else
            {
                if(i - dict[nums[i]] <= k) return true;
                else dict[nums[i]] = i;
            }
       }
       return false;
    }
};