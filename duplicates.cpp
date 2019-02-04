/* A class which finds whether there are duplicates in the passed vector */

#include <unordered_set>
#include <vector>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> u_set;
        
        for(std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
            if(u_set.count(*it) > 0) {
                return true;
            }
            u_set.insert(*it);
        }
        return false;
    }
};