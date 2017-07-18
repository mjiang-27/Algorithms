#include "stdafx.h"

#include "FourSum.h"

#include <algorithm>

// This is much easier to understand comparing with the solution submitted yesterdy.
// Using the solution of 3Sum.

std::vector<std::vector<int>> Solution::fourSum_1(std::vector<int>& nums, int target)
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

std::vector<std::vector<int>> Solution::fourSum_2(std::vector<int>& nums, int target)
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
        int secondIndex = firstIndex + 1;
        for (; secondIndex < numsSize - 2; secondIndex++)
        {
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
                    // Add a solution for the problem
                    std::vector<int> elem;
                    elem.push_back(nums[firstIndex]);
                    elem.push_back(nums[secondIndex]);
                    elem.push_back(nums[thirdIndex]);
                    elem.push_back(nums[forthIndex]);
                    res.push_back(elem);

                    // Update the value for the third and forth index
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

            // Skip duplicated integer for the second index
            while (secondIndex + 1 < numsSize - 2 && nums[secondIndex] == nums[secondIndex + 1])
            {
                secondIndex++;
            }
        }

        // Skip duplicated integer for the first index
        while (firstIndex + 1 < numsSize - 3 && nums[firstIndex] == nums[firstIndex + 1])
        {
            firstIndex++;
        }
    }

    return res;
}
