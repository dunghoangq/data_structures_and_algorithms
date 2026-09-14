/*
MEDIAN OF TWO SORTED ARRAYS

Given two sorted arrays nums1 and nums2 of size m and n, return the median of the two sorted arrays.

The runtime complexity should be O(log (m+n)).

e.g.1,

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000

Explanation: merged array = [1,2,3] and median is 2.

e.g.2,

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000

Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

-------------------------------------

ALGORITHM

Binary search
- Time: 
- Space: 

- Split two arrays:
    - # items in combined left partition = combined right partition (+ 1 if odd)
    - left partion value <= right partition value



FIND-MEDIAN-SORTED-ARRAYS(nums1, nums2)
    if nums1.length > nums2.length
        return FIND-MEDIAN-SORTED-ARRAYS(nums2, nums1)
    
    m = nums1.length
    n = nums2.length

    low = 0
    high = m

    while low <= high
        i = (low + high) / 2
        j = (m + n + 1) / 2 - i

        max_left1 = nums1[i-1] or -inf if i = 0
        min_right1 = nums1[i] or inf if i = m
        max_left2 = nums2[j-1] or -inf if j = 0
        min_right2 = nums2[j] or inf if j = n

        if max_left1 <= min_right2 and max_left2 <= min_right1
            if m + n odd
                median = max(max_left1, max_left2)
            else
                median = (max(max_left1, max_left2) + min(min_right1, min_right2)) / 2
            return median
        if max_left1 > min_right2
            high = i - 1
        if max_left2 > min_right1
            low = i + 1 
*/

#include <iostream>
#include <vector>
#include <limits>
#include <climits>

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    if (nums1.size() > nums2.size())
        return findMedianSortedArrays(nums2, nums1);
    
    int m = nums1.size();
    int n = nums2.size();
    int low = 0;
    int high = m;

    while (low <= high) {
        int i = low + (high - low)/2;
        int j = (m + n + 1) / 2 - i;

        int max_left1 = (i == 0) ? INT_MIN : nums1[i-1];
        int min_right1 = (i == m) ? INT_MAX : nums1[i];
        int max_left2 = (j == 0) ? INT_MIN : nums2[j-1];
        int min_right2 = (j == n) ? INT_MAX : nums2[j];

        if (max_left1 <= min_right2 && max_left2 <= min_right1) {
            if ((m + n) % 2 == 1)
                return std::max(max_left1, max_left2);
            else
                return (
                    std::max(max_left1, max_left2) +  std::min(min_right1, min_right2)
                ) / 2.0;
        }
        else if (max_left1 > min_right2)
            high = i - 1;
        else
            low = i + 1;
    }
    return 0.0;
}

int main() {
    std::vector<int> nums1 = {1,3};
    std::vector<int> nums2 = {2};
    std::cout << findMedianSortedArrays(nums1, nums2); // 2

    nums1 = {1, 2};
    nums2 = {3, 4};
    std::cout << findMedianSortedArrays(nums1, nums2); // 2.5

    return 0;
}