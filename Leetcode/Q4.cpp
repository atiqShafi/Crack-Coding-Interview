#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

/*
ע�����
1 �����ǵȳ�����������
2 log(m+n)���Ӷ�
*/

//�ؼ�˼·����1��Find-Cut���ҳ���������ķָ�㡣�������ǵȳ��������λ������ô��Ȼ������������ķָ�λC1��C2��ʹ�úϲ���C1,C2���ľ�С���Ҳ�ģ�C1+C2ռһ��������
// ��2����ΰ�����ż��ͳһ��������Ȼ�ܶ�߽����� - �������λ�á���Ϊ��ѷָ��Ҳ��Ϊһ��λ�ã��������㴦����Ȼ����ż����˵���ָ�㲻���ڡ�
// ͨ�����ַ�����cut��λ��
//����C1,C2�͹̶������Բ�������һ�����ɡ����Ӷ�O(log min(n1,n2)).�Խ�С������Ϊ�������ֲ���C2��λ�á�

//A1: [# 1 # 2 # 3 # 4 # 5 #]    (N1 = 5, N1_positions = 11)
//A2: [# 1 # 1 # 1 # 1 #]     (N2 = 4, N2_positions = 9)

// A1 = [L1 C1 R1]
// A2 = [L2 C2 R2]
//����ڻ���C1,C2,����Ӧ�ñ�֤L1 < R1 && L1 < R2 && L2 < R2 && L2 < R1�����ϲ���ķָ�㣬��������С�������Ҳ�
//����L1 < R1,L2 < R2 ���Ѿ���֤�ģ�����Ҫ��֤����L1 < R2�Լ�L2 < R1
//��ô���ڷָ�C2�����L1 > R2 ˵�� L1���й����large number������Ӧ�ðѷָ��C1����(��Ӧ��C2����)��Ҳ��ζ�ŷָ��λ�ò��ҷ�Χ������ǰһ�롣

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int N1 = nums1.size();
    int N2 = nums2.size();
    if (N1 < N2)
        return findMedianSortedArrays(nums2, nums1); // Make sure A2 is the shorter one.

    if (N2 == 0)
        return ((double)nums1[(N1 - 1) / 2] + (double)nums1[N1 / 2]) / 2; // If A2 is empty

    int lo = 0, hi = N2 * 2; //0��N2*2
    while (lo <= hi)
    {
        int mid2 = (lo + hi) / 2;  // Try Cut 2
        int mid1 = N1 + N2 - mid2; // Calculate Cut 1 accordingly

        double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1 - 1) / 2]; // Get L1, R1, L2, R2 respectively
        double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2 - 1) / 2];
        double R1 = (mid1 == N1 * 2) ? INT_MAX : nums1[(mid1) / 2];
        double R2 = (mid2 == N2 * 2) ? INT_MAX : nums2[(mid2) / 2];

        if (L1 > R2)
            lo = mid2 + 1; // A1's lower half is too big; need to move C1 left (C2 right)
        else if (L2 > R1)
            hi = mid2 - 1; // A2's lower half too big; need to move C2 left.
        else
            return (max(L1, L2) + min(R1, R2)) / 2; // Otherwise, that's the right cut.
    }
    return -1;
}

int main()
{
    vector<int> A = {1, 2, 3, 4};
    vector<int> B = {2, 4, 5};
    cout << findMedianSortedArrays(A, B) << endl;
}



//myself

class Solution {
public:
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();

    //nums1Ϊ�ϴ�ģ�nums2Ϊ��С��
    if(n1 < n2) return findMedianSortedArrays(nums2,nums1);
    if(n2 == 0) {
        double res = (nums1[(n1-1)/2] + nums1[n1/2]) / 2.0;
        return res;
    }
    
    //��A2Ϊ��׼���ҷָ��C2����0~2*N2.��ô��Ӧ��C1�ķָ��ΪN1+N2-C2.
    //���Թ۲쵽�ɷָ��C2�õ�L2������ָ��C2Ϊ���λ�ã���L2����C2,����ָ��Ϊ���֣���L2���һ��λ�á�
    //�ܽ����� L2 = Nums2[(C2-1)/2],R2 = Nums2[C2/2]
    int low = 0,high = n2*2; //��ʼ���ҷ�Χ
    while(low <= high)
    {
        int mid2 = (low + high) / 2;
        int mid1 = n1 + n2 - mid2;

        double l1 = (mid1 == 0) ? INT_MIN : nums1[(mid1-1)/2];
        double l2 = (mid2 == 0) ? INT_MIN : nums2[(mid2-1)/2];
        double r1 = (mid1 == n1*2) ? INT_MAX : nums1[mid1/2];
        double r2 = (mid2 == n2*2) ? INT_MAX : nums2[mid2/2];

        if(l1 > r2)
            low = mid2 + 1;
        else if(l2 > r1)
            high = mid2 - 1;
        else
            return (max(l1,l2) + min(r1,r2))/2.0;
    }
    return -1;
}
};


//�ڶ���
//����ַ���ָ��C1,C2
//�������������ܺ���Ϊż��(2*N1+1 + 2*N2+1 = 2(N1+N2+1))
//���е�m1,m2֮��ΪN1+N2

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size();
        int N2 = nums2.size();
        if(N1 < N2) return findMedianSortedArrays(nums2,nums1);

        if(N2 == 0) return ((nums1[(N1-1)/2] + nums1[N1/2]))/2.0;

        //1#2#3#4#5# ��ΧΪ[0,n2*2]
        //���λ����ʵ��λ�õ�ӳ���ϵ  (i-1)/2
        int l = 0,r = N2*2; //�������������ϲ���
        while(l<=r)
        {
            int mid2 = (l+r)/2;
            int mid1 = N1+N2-mid2;

            double l1 = (mid1 == 0) ? INT_MIN: nums1[(mid1-1)/2];
            double l2 = (mid2 == 0) ? INT_MIN: nums2[(mid2-1)/2];
            double r1 = (mid1 == N1*2) ? INT_MAX:nums1[mid1/2];
            double r2 = (mid2 == N2*2) ? INT_MAX:nums2[mid2/2];

            if(l1 > r2)
                l = mid2 + 1; //mid2����,�����Ҳ����
            else if(l2 > r1)
                r = mid2 - 1;
            else
                return (max(l1,l2) + min(r1,r2))/2.0;
        }

    }
};