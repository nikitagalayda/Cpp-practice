/*
Description:
    Given a vector of strings which contains anagrams, returns a vector 
    of vectors of strings where each of the sub-vectors represents a group 
    of anagrams.

Time Complexity:
    O(N+M) where N is the size of the given vector, and M is the size of the map.
    The sizes are added, as both are iterated through once.
*/

#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<std::vector<std::string> > groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string> > map;
        std::vector< std::vector<std::string> > res;
        
        for(int i = 0; i < strs.size(); i++) {
            std::string unsorted_str = strs[i];

            // By sorting the string, anagrams will always be hashed in the 
            // same way since they will be the same word. 
            std::sort(strs[i].begin(), strs[i].end());
            
            if(map.count(strs[i]) > 0) {
                map[strs[i]].push_back(unsorted_str);
            }
            else {
                std::vector<std::string> tmp;
                tmp.push_back(unsorted_str);
                map[strs[i]] = tmp;
                //res.push_back(map[strs[i]]);
            }
        }
        for(auto x : map) {
            res.push_back(x.second);
        }
        
        return res;
    }
};
