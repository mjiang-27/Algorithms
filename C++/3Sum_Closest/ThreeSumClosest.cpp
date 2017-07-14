#include "stdafx.h"

#include <cmath>
#include <iostream>
#include <algorithm>

#include "ThreeSumClosest.h"

int Solution::threeSumClosest(std::vector<int>& nums, int target)
{
	int ret = 0;

	// Special cases
	if (nums.size() <=3 ) 
	{
		for (auto elem: nums)
		{
			ret += elem;
		}

		return ret;
	}

	// Common case
	sort(nums.begin(), nums.end());

	ret = nums[0] + nums[1] + nums[2];

	int index = 0;
	for (; index < nums.size(); index++)
	{
		int left = index + 1;
		int right = nums.size() - 1;

		while (left < right)
		{
			int sum = nums[index] + nums[left] + nums[right];
			
			if (abs(sum - target) < abs(ret - target))
			{
				ret = sum;

				if (ret == target)
				{
					return ret;
				}
			}

			if (sum < target)
			{
				left++;
			}
			else
			{
				right--;
			}
		}
	}

	return ret;
}