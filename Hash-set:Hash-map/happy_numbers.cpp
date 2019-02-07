/*
Description: 
	Given an integer, returns whether or not a number is happy. A number is happy if: 
	Starting with any positive integer, replace the number by the sum of the squares 
	of its digits, and repeat the process until the number equals 1 (where it will stay), 
	or it loops endlessly in a cycle which does not include 1. Those numbers for which 
	this process ends in 1 are happy numbers.

Time Complexity: 
	O(k), where k is the number of loops we run through in order to reach
	the result of 1. This would most likely be constant time complexity, as we check for
	looping in the program. 

*/

// calculate the resulting number from the digits of the current number.
// check if we have seen this number before.
// if we have, it's a loop, we stop execution and return false.
// if we have not, continue
#include <vector>
#include <unordered_set>
#include <iostream>
#include <cmath>

class Solution {
private:
    std::unordered_set<int> seen_set;
public:
    bool isHappy(int n) {

    	while(n != 1) {

	    	if(seen_set.count(n) > 0) {
	    		return false;
	    	}
	    	seen_set.insert(n);
            n = calc_num(n);
   		}
   		return true;
    }
    
    int calc_num(int n) {
        int sum = 0;
	    while(n) {
	        sum += pow(n % 10, 2);
			n /= 10;
        }
        return sum;
    }
};