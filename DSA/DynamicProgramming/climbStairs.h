/*
leetcode70:爬楼梯：
假设你正在爬楼梯。需要 n 步你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 步 + 1 步
2.  2 步

示例 2：

输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 步 + 1 步 + 1 步
2.  1 步 + 2 步
3.  2 步 + 1 步
*/
#pragma once
#include"head.h"

class ClimbStairs
{
public:
	/*
	 由于一次只能爬一个或者2个楼梯，则第n个台阶到达楼顶的方法等于第n-1个台阶到达楼顶的方法和n-2个台阶到达楼顶的方法，和fib一致，
	 需要注意的是，第一个楼梯只有一种方法，第二个楼梯2种方法，第三个楼梯3种方法，而fib(1) = 1, fib(2) = 1 fib(3) = 2,所以楼梯数
	 和fib的位数需要进行转换
	*/
	int getWayCount(int stairsCount) {
		
		if (stairsCount == 0) {
			return 0;
		}

		if (stairsCount == 1) {
			return 1;
		}
		int fibLast = stairsCount + 1;


		int first = 1;
		int second = 1;
		for (int i = 2; i < fibLast; i++) {
			int temp = first;
			first = second;
			second = second + temp;
		}
		return second;
	}
private:

};

