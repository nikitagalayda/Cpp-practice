/*
Description: 
	Returns the intersection of two vectors (intersection being the numbers that both vectors contain)
	in the form of a vector.

Time Complexity: 
	O(N)
*/

#include <unordered_set>
#include <vector>

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> u_set;
        vector<int> res;
        
        for(std::vector<int>::iterator it = nums1.begin(); it != nums1.end(); ++it) {
            u_set.insert(*it);
        }
        
        for(std::vector<int>::iterator it = nums2.begin(); it != nums2.end(); ++it) {
            if(u_set.count(*it)) {      // Check if this number has been seen in the other vector
                res.push_back(*it);     // and if so, we insert it into the vector.
                u_set.erase(*it);       // Erase the inserted number to avoid duplicates.
            }
        }
        
        return res;
    }
};