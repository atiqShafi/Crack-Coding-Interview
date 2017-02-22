class Solution {
public:
    int compareVersion(string version1, string version2) {
        //version ���ܶ��'.'
        if(version1 == version2) return 0;
        
        version1+=".";
        version2+=".";
        istringstream in1(version1);
        istringstream in2(version2);
        int v1=-1,v2=-1;
        char c1,c2;
        while(in1>>v1>>c1 && in2>>v2>>c2)
        {
            if(v1 > v2) return 1;
            else if(v1 < v2) return -1;
            v1 = v2 = -1;
        }
        //�����v1����ʧ��,˵��v1û������,��v2��һ��
        //���v1�����룬˵��v2û�����ˡ�

        if(v1 == -1) //v1û����
        {
            while(in2 >> v2 >> c2)
            {
                if(v2 > 0) return -1;
            }
            if(v2 == -1||v2==0) //v2Ҳû���ݻ��ߺ���һ��0
                return 0;
        }
        else //v1�����ݣ�v2û����
        {
            if(v1 > 0) return 1; //����v2ʧ��ʱv1�е�����
            while(in1 >> v1 >> c1)
            {
                if(v1 > 0) return 1;
            }
            if(v1 == 0) return 0;
        }
        return 0;
    }
};