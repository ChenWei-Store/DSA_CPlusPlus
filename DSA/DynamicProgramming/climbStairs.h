/*
leetcode70:��¥�ݣ�
������������¥�ݡ���Ҫ n ������ܵ���¥����

ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�

ע�⣺���� n ��һ����������

ʾ�� 1��

���룺 2
����� 2
���ͣ� �����ַ�����������¥����
1.  1 �� + 1 ��
2.  2 ��

ʾ�� 2��

���룺 3
����� 3
���ͣ� �����ַ�����������¥����
1.  1 �� + 1 �� + 1 ��
2.  1 �� + 2 ��
3.  2 �� + 1 ��
*/
#pragma once
#include"head.h"

class ClimbStairs
{
public:
	/*
	 ����һ��ֻ����һ������2��¥�ݣ����n��̨�׵���¥���ķ������ڵ�n-1��̨�׵���¥���ķ�����n-2��̨�׵���¥���ķ�������fibһ�£�
	 ��Ҫע����ǣ���һ��¥��ֻ��һ�ַ������ڶ���¥��2�ַ�����������¥��3�ַ�������fib(1) = 1, fib(2) = 1 fib(3) = 2,����¥����
	 ��fib��λ����Ҫ����ת��
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

