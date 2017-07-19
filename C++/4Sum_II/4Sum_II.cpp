#include <unordered_map>

#include "4Sum_II.h"

int Solution::fourSumCount_V1(std::vector<int>& A, std::vector<int>& B, std::vector<int>& C, std::vector<int>& D)
{
    int size = A.size();

    std::unordered_map<int, int> sum1, sum2;

    int outIndex = 0;
    for (; outIndex < size; outIndex++)
    {
        int inIndex = 0;
        for (; inIndex < size; inIndex++)
        {
            ++sum1[A[outIndex] + B[inIndex]];
            ++sum2[C[outIndex] + D[inIndex]];
        }
    }

    int ret = 0;
    for (auto elem: sum1)
    {
        ret += sum2[-elem.first] * elem.second;
    }

    return ret;
}

// Optimization for the V1, in order to reduce the total time
int Solution::fourSumCount_V2(std::vector<int>& A, std::vector<int>& B, std::vector<int>& C, std::vector<int>& D) 
{
    std::unordered_map<int, int> sum;

    for (auto a: A)
    {
        for (auto b: B)
        {
            ++sum[a + b];
        }
    }

    int ret = 0;
    for (auto c: C)
    {
        for (auto d: D)
        {
            auto iter = sum.find(-1 * (c + d));
            if (iter != sum.end())
            {
                ret += iter->second;
            }
        }
    }

    return ret;
}
