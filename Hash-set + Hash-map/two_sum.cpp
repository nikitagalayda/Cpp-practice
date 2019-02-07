/*
Description: 
	Given an vector of unique integers, and a target integer value, 
	returns indeces of two integers in the vector such that they add up to the 
	target value.

Time Complexity: 
	At most O(N), where N is the size of the vector. We reach 
	this complexity if we have to iterate through the whole vector, which can occur
	if one the values of the answer pair is at the end of the vector. 
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        std::vector<int> res;
        
        for(int i = 0; i < nums.size(); ++i) {
            int comp = target - (nums[i]);
            
            if(map.count(comp)) {
                res.push_back(map[comp]);
                res.push_back(i);
                return res;
            }
            map.insert(std::make_pair(nums[i], i));
        }
        return res;
    }
};