
#include"head.h"
#include "lis.h"
#include"climbStairs.h"
#include"MaxProfit.h"
#include"MaxSubArray.h"
#include"rob.h"
//using namespace std;
int main() {

	cout << "请选择题目序号" << endl;
	cout << "1.最长递增子序列" << endl;
	cout << "2.爬楼梯" << endl;
	cout << "3.买卖股票的最佳时机" << endl;
	cout << "4.最大子序和" << endl;
	cout << "5.打家劫舍" << endl;
	int num;
	cin >> num;
	switch (num)
	{
	case 1:
	{
		vector <int>nums;
		//int input[] = {1,3,6,7,9,4,10,5,6};
		int input[] = { 10,9,2,5,3,7,101,18 };
		for (int i = 0; i < 9; i++) {
			nums.push_back(input[i]);
		}
		LIS lis;
		int count = lis.lengthOfLIS(nums);
		cout << "result: " << count << endl;
		break;
	}
	case 2: 
	{
		int n = 3;
		ClimbStairs cs;
		int input;
		while (true)
		{

			cin >> input;
			if (input == -1) {
				break;
			}
			int count = cs.getWayCount(input);
			cout << count << endl;

		}
		
		break;
	}
	case 3: {
		vector <int>nums;
		int input[] = {7,6,4,3,1};
		//int input[] = { 7,1,5,3,6,4 };
		for (int i = 0; i < sizeof(input) / sizeof(input[0]); i++) {
			nums.push_back(input[i]);
		}

		MaxProfit maxProfit;
		int result = maxProfit.getMaxProfit(nums);
		cout<<result<<endl;
		break;
	}
	case 4: {
		vector <int>nums;
		int input[] = { -2,1,-3,4,-1,2,1,-5,4};
		//int input[] = { 7,1,5,3,6,4 };
		for (int i = 0; i < sizeof(input) / sizeof(input[0]); i++) {
			nums.push_back(input[i]);
		}

		MaxSubArray maxSubArray;
		int result = maxSubArray.getMaxSubArray(nums);
		cout << result<<endl;
		break;
	}
	case 5: {
		vector <int>nums;
		int input[] = { 2,7,9,3,1 };
		//int input[] = { 7,1,5,3,6,4 };
		for (int i = 0; i < sizeof(input) / sizeof(input[0]); i++) {
			nums.push_back(input[i]);
		}

		Rob rob;
		int result = rob.getMaxMoney(nums);
		cout << result << endl;
		break;
	}
	default:
		break;
	}
}




