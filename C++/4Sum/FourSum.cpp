#include "stdafx.h"

#include "FourSum.h"

#include <algorithm>

// TODO: solve the problem with 3Sum.
// Refering: https://discuss.leetcode.com/topic/9712/4sum-c-solution-with-explanation-and-comparison-with-3sum-problem-easy-to-understand

std::vector<std::vector<int>> Solution::fourSum(std::vector<int>& nums, int target)
{
    std::vector<std::vector<int>> res;

    int numsSize = nums.size();
    if (numsSize < 4)
    {
        return res;
    }

    sort(nums.begin(), nums.end());

    int firstIndex = 0;
    for (; firstIndex < numsSize - 3; firstIndex++)
    {
        // Skip duplicated integer for the first index
        // It must start from the second element in nums, or some cases will be ignored.
        if (firstIndex > 0 && nums[firstIndex] == nums[firstIndex - 1])
        {
            continue;
        }

        int secondIndex = firstIndex + 1;
        for (; secondIndex < numsSize - 2; secondIndex++)
        {
            // Skip duplicated integer for the second index
            // It must start from firstIndex + 2 element in nums, or some cases will be ignored.
            if (secondIndex > firstIndex + 1 && nums[secondIndex] == nums[secondIndex - 1])
            {
                continue;
            }

            int thirdIndex = secondIndex + 1;
            int forthIndex = numsSize - 1;
            while (thirdIndex < forthIndex)
            {
                int sum = nums[firstIndex] + nums[secondIndex] + nums[thirdIndex] + nums[forthIndex];
                if (sum < target)
                {
                    thirdIndex++;
                }
                else if (sum > target)
                {
                    forthIndex--;
                }
                else
                {
                    std::vector<int> elem;
                    elem.push_back(nums[firstIndex]);
                    elem.push_back(nums[secondIndex]);
                    elem.push_back(nums[thirdIndex]);
                    elem.push_back(nums[forthIndex]);

                    // Add a solution for the problem
                    res.push_back(elem);

                    thirdIndex++;
                    forthIndex--;

                    // Skip duplicated integer for the third index
                    while (thirdIndex < forthIndex && nums[thirdIndex] == nums[thirdIndex - 1])
                    {
                        thirdIndex++;
                    }

                    // Skip duplicated integer for the forth index
                    while (thirdIndex < forthIndex && nums[forthIndex + 1] == nums[forthIndex])
                    {
                        forthIndex--;
                    }
                }
            }
        }
    }

    return res;
}