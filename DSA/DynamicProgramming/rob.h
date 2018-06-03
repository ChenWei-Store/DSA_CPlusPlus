/*
leetcode198 ��ҽ���
����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݡ�ÿ�䷿�ڶ�����һ�����ֽ�Ӱ����͵�Ե�Ψһ��Լ���ؾ������ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ�������

����һ������ÿ�����ݴ�Ž��ķǸ��������飬�������ڲ���������װ�õ�����£��ܹ�͵�Ե�����߽�

ʾ�� 1:

����: [1,2,3,1]
���: 4
����: ͵�� 1 �ŷ��� (��� = 1) ��Ȼ��͵�� 3 �ŷ��� (��� = 3)��
͵�Ե�����߽�� = 1 + 3 = 4 ��

ʾ�� 2:

����: [2,7,9,3,1]
���: 12
����: ͵�� 1 �ŷ��� (��� = 2), ͵�� 3 �ŷ��� (��� = 9)������͵�� 5 �ŷ��� (��� = 1)��
͵�Ե�����߽�� = 2 + 9 + 1 = 12 ��
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



