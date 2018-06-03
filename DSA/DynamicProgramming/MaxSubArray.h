/*
leetcode53 最大子序和
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
*/

#pragma once
#include"head.h"
#include<vector>

class MaxSubArray
{
public:
	int getMaxSubArray(vector<int>& nums) {
		vector<int> maxSubCount;
		maxSubCount.push_back(nums.at(0));
		for (int i = 1; i < nums.size(); i++) {
			int prevCount = maxSubCount.at(i - 1);
			int num = nums.at(i);
			if (num < num + prevCount) {
				maxSubCount.push_back(prevCount + num);
			}
			else
			{
				maxSubCount.push_back(num);
			}
		}

		int max = maxSubCount.at(0);
		for (int i = 1; i < maxSubCount.size(); i++) {
			if (max < maxSubCount.at(i)) {
				max = maxSubCount.at(i);
			}
		}
		return max;
	}

private:

};

