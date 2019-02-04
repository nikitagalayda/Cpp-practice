/*
Description: Given a vector of numbers where every number is duplicated except for one, returns that unique number.

Time Complexity: O(N)

LOGIC:

res = 7 ^ 3 ^ 5 ^ 4 ^ 5 ^ 3 ^ 4

Since XOR is associative and commutative, above 
expression can be written as:
res = 7 ^ (3 ^ 3) ^ (4 ^ 4) ^ (5 ^ 5)  
    = 7 ^ 0 ^ 0 ^ 0
    = 7 ^ 0
    = 7
*/

#include <vector>

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single_num = 0;
        
        for(std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
            single_num ^= *it;   
        }
        
        return single_num;
    }
};