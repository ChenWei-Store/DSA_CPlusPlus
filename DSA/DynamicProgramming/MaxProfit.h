
/*
leetocde121:买卖股票的最佳时机


给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

注意你不能在买入股票前卖出股票。

示例 1:

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。

示例 2:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
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

