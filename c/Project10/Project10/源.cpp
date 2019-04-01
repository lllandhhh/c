#include<stdio.h>
#include<string.h>
int* twoSum(int* nums, int numsSize, int target)
{
	int i;int m = numsSize-1;
	for (i = 0;;)
	{
		if (nums[i] + nums[m] == target)
		{
			printf("[%d,%d]", i, m);
			return 0;
		}
		if (nums[i] + nums[m]<target)
			i++;
		if (nums[i] + nums[m]>target)
			m--;
		if (i == m)return 0;
	}
	return 0;
}

int main()

{
	int nums[4] = { 2,7,11,15 };
	twoSum(nums,4,14);
	getchar();
	return 0;
}