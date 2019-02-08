/* 
Description:
    Given strings J representing the types of stones that are jewels (each char
    is a jewel), and S representing the stones you have (each char is a stone), returns how many stones are also jewels. 
    Ex: 
        Input: J = "aA", S = "aAAbbbb"
        Output: 3

Time Complexity:
    O(N+M) where N is the size of the string J, and M is size of string S.
*/

#include <unordered_set>
#include <string>

class Solution {
public:
    int numJewelsInStones(std::string J, std::string S) {
        std::unordered_set<char> set;
        int jewels = 0;
        
        for(auto c : J) {
            set.insert(c);
        }
        
        for(auto c : S) {
            if(set.count(c) > 0) {
                ++jewels;
            }
        }
        return jewels;
    }
};