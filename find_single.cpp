#include <unordered_set>
#include <vector>

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::unordered_set<int> u_set;
        
        for(std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
            if(u_set.count(*it) == 1) {
                u_set.erase(*it);
            }
            else {
                u_set.insert(*it);
            }
        }
        
        for(std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
            if(u_set.count(*it) == 1) {
                return *it;
            }
        }
        return -1;
    }
};