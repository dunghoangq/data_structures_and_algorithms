/*
MOVE ZEROES

Given an integer array nums, move all 0's to the end of nums while maintaining the relative order of non-zero numbers.

Note that you must do this in-place without making a copy of the array.

e.g.1,

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

e.g.2,

Input: nums = [0]
Output: [0]

-----------------------------

ALGORITHM

2 pointer
- Time: 
- Space: O(1)

MOVE-ZEROES(nums)
    if nums.length == 1
        return

    start = 0
    end = 1

    while end < nums.length
        if start == end
            end++
        if nums[start] == 0 and nums[end] != 0
            nums[start] = nums[end]
            nums[end] = 0
        start++
        end++
*/

#include <iostream>
#include <vector>

void moveZeroes(std::vector<int>& nums) {
    int n = nums.size();
    if (nums.size() == 1) return;

    int start = 0;
    int end = 1;

    while (end < n) {
        if (start == end) end++;
        if (nums[start] == 0) {
            if (nums[end] != 0) {
                nums[start] = nums[end];
                nums[end] = 0;
                start++;
                end++;
            }
            else end++;
        }
        else {
            start++;
            end++;
        }
    }
}