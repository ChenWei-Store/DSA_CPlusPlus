/*
leetcode198 打家劫舍
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

示例 1:

输入: [1,2,3,1]
输出: 4
解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
偷窃到的最高金额 = 1 + 3 = 4 。

示例 2:

输入: [2,7,9,3,1]
输出: 12
解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
偷窃到的最高金额 = 2 + 9 + 1 = 12 。
*/
#pragma once
#include"head.h"
#include<vector>
class Rob
{
public:
	int getMaxMoney(vector<int>& nums) {
		if (nums.size() == 0) {
			return 0;
		}

		if (nums.size() == 1) {
			
			return nums.at(0);
		}

		if (nums.size() == 2) {
			return nums.at(0) > nums.at(1) ? nums.at(0) : nums.at(1);
		}

		if (nums.size() == 3) {
			int sum = nums.at(0) + nums.at(2);
			return sum > nums.at(1) ? sum : nums.at(1);
		}
		vector<int> moneys;
		moneys.push_back(nums.at(0));
		moneys.push_back(nums.at(0) > nums.at(1) ? nums.at(0) : nums.at(1));
		moneys.push_back(nums.at(0) + nums.at(2));
		for (int i = 3; i < nums.size(); i++) {
			int count1 = moneys.at(i - 2);
			int count2 = moneys.at(i - 3);
			if (count1 > count2) {
				moneys.push_back(count1 + nums.at(i));
			}
			else {
				moneys.push_back(count2 + nums.at(i));
			}
		}

		int max = moneys.at(moneys.size() - 1);
		if (max < moneys.at(moneys.size() - 2)) {
			max = moneys.at(moneys.size() - 2);
		}
		return max;
	}
private:

};



