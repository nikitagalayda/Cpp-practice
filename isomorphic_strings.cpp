/*
Description: Given two strings, s and t, checks whether or not the strings are isomorphic.
Two strings are isomorphic if the characters in s can be replaced to get t.

Time complexity: O(N) at worst. 
*/

#include <string>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {        
        std::unordered_map<char, char> map;
        std::unordered_set<char> set;
        
        if(s.length() != t.length()) {
            return false;
        }
        
        for(int i = 0; i < s.length(); i++) {

            // Current letter of s is in the map
            if(map.find(s[i]) != map.end()) {
                if(map[s[i]] != t[i]) {             // The letter of s is in the map, but its pair doesn't match with
                    return false;                   // the current letter of t. There is more than 1 letter in t matching
                                                    // the current letter of s. 
                                                    // ex: s = aa, t = ab. a would match with a, and on the second loop
                                                    // a would try to match with b, which is wrong. Hence false is returned.
                }
            }
            // Current letter of s is not in the map
            else {
                if(set.find(t[i]) != set.end()) {   // If the given letter of t is already in the set, it means it 
                    return false;                   // cannot be mapped to again. If this is attempted, false is returned.
                }
                map.insert(make_pair(s[i], t[i]));
                set.insert(t[i]);
            }
        }
        return true;
    }
         
};