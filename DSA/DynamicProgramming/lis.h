/*************leetcode300 �����������(leetcode300. Longest Increasing Subsequence)******************
����������

Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,

Given [10, 9, 2, 5, 3, 7, 101, 18],

1

The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?

����һ��δ��������������飬Ѱ������������еĳ��ȡ�
*/
#pragma once
#include<vector>
#include"head.h"
class LIS
{
public:
	/*
	 *˼·��������a-n�����������k����n�����ģ����ҵ�ǰ���������б�nС�ұ���������ģ�ʹ�ø����������������+1�����û�У���Ϊ1
	 */
	int lengthOfLIS(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		int size = nums.size();
		if (size == 1) {
			return 1;
		}
		vector <int> counts;
		counts.push_back(1);
		for (int i = 1; i < size; i++) {
			int last = nums.at(i);
			int tempCount = 1;
			bool hasSmaller = false;
			for (int j = 0; j < i; j++) 
			{
				int temp = nums.at(j);
				if (tempCount == 1) {
					if (temp < last) {
						hasSmaller = true;
						tempCount = counts.at(j);
					}
				}else
				{
					if (temp < last && tempCount < counts.at(j)) {
						hasSmaller = true;
						tempCount = counts.at(j);
					}

				}
				
			}
			if (hasSmaller) {
				counts.push_back(tempCount + 1);
			}
			else {
				counts.push_back(tempCount);
			}

		}

		cout << "-------" << endl;
		int largest = counts.at(0);

		for (int i = 1; i < size; i++) {
			cout << "i:" << i << endl;
			cout << "count:" << counts.at(i) << endl;

			if (counts.at(i) > largest) {
				largest = counts.at(i);
			}
		}

		return largest;
	}

private:

};

