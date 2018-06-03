/*************leetcode300 最长递增子序列(leetcode300. Longest Increasing Subsequence)******************
问题描述：

Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,

Given [10, 9, 2, 5, 3, 7, 101, 18],

1

The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?

给定一个未经排序的整数数组，寻找最长递增子序列的长度。
*/
#pragma once
#include<vector>
#include"head.h"
class LIS
{
public:
	/*
	 *思路：数列有a-n个数，假设第k个数n是最大的，则找到前面所有数中比n小且比其他数大的，使用该数的最长递增子序列+1，如果没有，则为1
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

