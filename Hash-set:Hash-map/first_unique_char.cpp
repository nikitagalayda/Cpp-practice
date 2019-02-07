/*
Description: 
    Given a string s, returns the index of the first non-repeating
    char. If no such char exists, returns -1.

Time complexity: 
    O(N+M) where N is the length of the string, and M is the size
    of the map;
*/

#include <string>
#include <unordered_map>

struct info {
            int occurrance;
            int position;
};

class Solution {
public:
    int firstUniqChar(string s) {
        std::unordered_map<char, info> map; 
        int res = INT_MAX; 
        
        for(int i = 0; i < s.length(); i++) {
            map[s[i]].occurrance++;
            map[s[i]].position = i;
        }
        
        for(auto x : map) {
            if(x.second.occurrance == 1 && x.second.position < res) {
                res = x.second.position;
            }
        }
        res = (res == INT_MAX) ? -1 : res;
        return res;
    }
};