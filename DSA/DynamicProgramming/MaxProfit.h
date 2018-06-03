
/*
leetocde121:������Ʊ�����ʱ��


����һ�����飬���ĵ� i ��Ԫ����һ֧������Ʊ�� i ��ļ۸�

��������ֻ�������һ�ʽ��ף������������һ֧��Ʊ�������һ���㷨�����������ܻ�ȡ���������

ע���㲻���������Ʊǰ������Ʊ��

ʾ�� 1:

����: [7,1,5,3,6,4]
���: 5
����: �ڵ� 2 �죨��Ʊ�۸� = 1����ʱ�����룬�ڵ� 5 �죨��Ʊ�۸� = 6����ʱ��������������� = 6-1 = 5 ��
ע���������� 7-1 = 6, ��Ϊ�����۸���Ҫ��������۸�

ʾ�� 2:

����: [7,6,4,3,1]
���: 0
����: �����������, û�н������, �����������Ϊ 0��
*/
#pragma once
#include "head.h"
#include <vector>
class MaxProfit
{
public:
	int getMaxProfit(vector<int>& prices) {
		if (prices.empty()) {
			return 0;
		}

		if (prices.size() == 1) {
			return 0;
		}
		vector<int> profits;
		profits.push_back(0);
		for (int i = 1; i < prices.size(); i++) {
			int buyStock = 0;
			int sellStock = prices.at(i);
			for (int j = i - 1; j >= 0; j--) {

				if (j == i - 1) 
				{
					buyStock = prices.at(j);
				}else
				{
					int tempBuyStock = prices.at(j);
					if (tempBuyStock < buyStock) {
						buyStock = tempBuyStock;
					}
				}

			}

			int profit = sellStock - buyStock;
			if (profit < 0) {
				profit = 0;
			}
			profits.push_back(profit);
		}

		int maxProfit = profits.at(0);
		for (int i = 1; i < profits.size(); i++) {
			int tempProfit = profits.at(i);
			if (maxProfit < tempProfit) {
				maxProfit = tempProfit;
			}
		}


		return maxProfit;

	}

private:

};

