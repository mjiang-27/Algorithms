#include "TwoSum_II.h"

std::vector<int> Solution::twoSum(std::vector<int>& nums, int target)
{
    std::vector<int> ret;
        
    int numsSize = nums.size();
    if (numsSize < 2)
    {
        return ret;
    }
        
    int left = 0;
    int right = numsSize - 1;
    int sum = 0;
    while (left < right)
    {
        if (nums[left] + nums[left + 1] > target || nums[right] + nums[right - 1] < target)
        {
            break;
        }
            
        sum = nums[left] + nums[right];
            
        if (sum == target)
        {
            ret.push_back(left + 1);
            ret.push_back(right + 1);
            return ret;
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
        
    return ret;
}
