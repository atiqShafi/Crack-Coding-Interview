//�ж�s�ǲ���t���ִ�����һ��������abc  ahbgdc
//��ΪҪ���ִ��������Դ�������ɨ�裬����һ�μ��ɡ�������ͬ�Ĺ�ͬ����ɨ�������t������ֱ���ҵ�
//ƥ���
//���t�ܳ�������t���䣿
//��t����HashMap��valueλ��ţ�multimap),��sɨ�裬����Ҳ�����¼������false,����ÿ��ȡ����¼��
//�õ���С��Index��why)��������һ����


bool solve(string s,string t)
{
    int num = 0;
    for(int i=0,j=0;i<s.size() && j<t.size();)
    {
        if(s[i] == t[j]) {i++;j++;num++;}
        else j++;
    }
    if(num == s.size()) return true;
    return false;
}
