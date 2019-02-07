/*
Description: 
    Given two arrays, returns a vector of their intersection. Intersection
    of two arrays is the common elements in both arrays. 

Time Complexity: 
    O(N+M) where N is the size of the larger of two arrays, and M is
    the size of the unordered_map.
*/

#include <unordered_map>
#include <vector>

// 1. Copy one of the lists into a map where key is the number and value is the amount of its occurrances
// 2. iterate through the second list checking the values against the map. If there is a match, decrement the map
//    value by 1 to signify a match.


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_map<int, int> map;
        std::vector<int> big_vec = (nums1.size() > nums2.size()) ? nums1 : nums2;
        std::vector<int> res;
        
        for(const auto &x : big_vec) {
            if(map.find(x) != map.end()) {
                (map[x])++;
            }
            else {
                map[x] = 1;
            }
        }
        
        std::vector<int> small_vec = (big_vec == nums1) ? nums2 : nums1;
        
        for(auto &it : small_vec) {
            if(map.find(it) != map.end() && map[it] != 0) {
                map[it] -= 1;
                res.push_back(it);
            }
            else {
                map.erase(it);
            }
        }        
        return res;
    }
};