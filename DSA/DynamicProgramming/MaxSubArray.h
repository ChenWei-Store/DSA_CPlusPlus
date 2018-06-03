/*
leetcode53 ��������
����һ���������� nums ���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�

ʾ��:

����: [-2,1,-3,4,-1,2,1,-5,4],
���: 6
����: ���������� [4,-1,2,1] �ĺ����Ϊ 6��

����:

������Ѿ�ʵ�ָ��Ӷ�Ϊ O(n) �Ľⷨ������ʹ�ø�Ϊ����ķ��η���⡣
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

