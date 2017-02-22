//sell stock (multi trade)
//buy[i] ��ʾ��i��״̬����Ϊ�����õ���������
//sell[i] ��ʾ��i��״̬����Ϊ������õ���������
//��i�첻���������i�������Ϊ opt[i-1]
//opt[i] ��ʾ��i���õ���������

//buy[i] = opt[i-1] - prices[i];
//sell[i] = prices[i]+buy[i-1];

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy,sell;
        sell = prices[0]; //Error��ʼ���������� sell = 0;��һ��sellӦ����0;
        buy = -prices[0];
        for(int i=1;i<prices.size();++i)
        {
            int tmpS = sell;
            int tmpB = buy;
            sell = max(prices[i] + tmpB,tmpS);
            buy = max(tmpS - prices[i],tmpB);
        }
        return max{sell,buy};
    }
};

//[3,6,5,2,1,6,7,8,23,22,11,23,6,4]