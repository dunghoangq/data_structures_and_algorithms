/*
SUMMARY RANGES

Given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

e.g.1,

Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]

Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"

e.g.2,

Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]

Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"

-----------------------------

ALGORITHM

Pointer
- Time: O(n)
- Space:

SUMMARY-RANGES(nums)
    start = 0
    result = []

    for i = 1 .. nums.length - 1
        if nums[i] == nums[o-1] + 1 and i != nums.length - 1
            continue
        else
            result.append("nums[start]->nums[i-1]")
            start = i
    
    return result
*/

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> summaryRanges(std::vector<int>& nums) {
    int start = 0;
    std::vector<std::string> result;

    if (nums.size() == 0) return result;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i-1] + 1)
            continue;
        else {
            if (start != i-1)
                result.push_back(std::to_string(nums[start]) + "->" + std::to_string(nums[i-1]));
            else
                result.push_back(std::to_string(nums[start]));
                
            start = i;
        }
    }

    if (nums.size() != start + 1)
        result.push_back(std::to_string(nums[start]) + "->" + std::to_string(nums.back()));
    else
        result.push_back(std::to_string(nums.back()));

    return result;
}