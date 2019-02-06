/*
Desciption: Given two vectors containing strings, returns a vector of strings
with the least list index sum, which is the least sum of indeces of common
strings in both lists. 

Time Complexity: O(N+M) where N and M are lengths of the lists. 
*/

#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<std::string> findRestaurant(std::vector<std::string>& list1, std::vector<std::string>& list2) {
        std::unordered_map<std::string, int> map;
        std::vector<std::string> result;
        
        // Turn the first vector into the map so that we can
        // compare the strings in the second vector against it.
        for(int i = 0; i < list1.size(); i++) {
            map[list1[i]] = i;
        }

        int least = 9999;
        for(int i = 0; i < list2.size(); i++) {
            if(map.count(list2[i])) {

                int sum = i + map[list2[i]];
                if(sum < least) {
                    least = sum;

                    // Clear the vector since the old strings in it are no 
                    // longer the minimum.
                    result.clear();
                    result.push_back(list2[i]);
                }
                else if(sum == least) {
                    result.push_back(list2[i]);
                }
            }
        }
        return result;
    }
};