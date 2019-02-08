/*
Description:
    Given a vector of integers, and an integer k, returns whether or not there are
    two equal integers, at different indeces, whose absolute index difference is 
    at most k.

Time Complexity: 
    O(N) where N is the size of the given vector. This is because the vector is
    only iterated once, and unordered_map lookup time can be assumed to be constant.
*/

#include <unordered_map>
#include <cmath>
#include <vector>
#include <iostream>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> map;
        
        for(int i = 0; i < nums.size(); i++) {
            if(map.count(nums[i]) > 0) {
                // i will never be negative, and neither will nums[i], 
                // hence the subtraction effectively returns an absolute value.
                if(i - map[nums[i]] <= k) {
                    return true;
                }
                else {
                    // If the subtraction did not return a valid result, then
                    // the value in the key is too "far" from other values (since
                    // it already failed the comparison between it and the next 
                    // closest same value with different index). Hence it is replaced
                    // with the next number with same value and different index.
                    map[nums[i]] = i;
                }
            }
            else {
                map[nums[i]] = i;
            }
        }
        return false;
    }
};