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

double solve(vector<int>&nums1,vector<int>&nums2,int sa,int ea,int sb,int eb)
{
    //���ÿ����������ֻ��һ��������λ��Ϊ������ƽ����
    cout << "A[" << sa << "," << ea <<"],B[" << sb << "," << eb << "]" << endl;
    int lena = ea - sa+1;
    int lenb = eb - sb+1;
    if(lena == 1 && lenb == 1) return (nums1[sa]+nums2[sb])/2.0;
    int midA = nums1[sa+lena/2];
    int midB = nums2[sb+lenb/2];
    if(midA == midB) return midA;
    else if(midA > midB) return solve(nums1,nums2,sa,ea-lenb/2,sb+lenb/2,eb);   //��λ����A��ǰ��κ�B�ĺ��Ρ�
    else return solve(nums1,nums2,sa+lenb/2,ea,sb,eb-lenb/2);
}

double findMedianSortedArrays(vector<int>& nums1,vector<int>&nums2)
{
    //Ϊ�˴����㣬�ٶ�A�ĳ��ȱ�B�ĳ���
    int n = nums1.size();
    int m = nums2.size();
    if(n > m) return solve(nums1,nums2,0,n-1,0,m-1);
    else return solve(nums2,nums1,0,m-1,0,n-1);
}

int main()
{
    vector<int> A = {1,2,3,4};
    vector<int> B = {2,4,5};
    cout << findMedianSortedArrays(A,B) << endl;
}
