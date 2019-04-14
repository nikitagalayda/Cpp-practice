/*
	Given a string s, find smallest substring in s, which contains all characters of t (amount included)

	The idea is to use sliding window technique. A window is created, which is expanded until all of the letters in t are in the window. 
	Then, the window is contracted, until the window no longer contains all letters in t, at which point the window is expanded to the right.
	If the expansion again matches all the letters in window with t, and the new window is smaller than one previously saved, it is the new
	shortest window.

	Shortest window is returned.
*/

class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0;		// l points to left border of window, r to right
        int r = 0;
        unordered_map<char, int> t_map;		// map of characters in t, key is a character, value is amount of the character in t
        
        for(int i = 0; i < t.size(); i++) {
            t_map[t[i]]++;
        }
  
        int required = t_map.size();		// how many letters are required to match in window with t
        unordered_map<char, int> window_map;// map of chars in current window
        int formed = 0;						// matches between number of letters in window and t
        int ans[] = {-1, 0, 0};				// answer in format {substrlength, left boundary, right boundary}
        
        while(r < s.length()) {
            char c = s[r];					// add the current character in window to map
            window_map[c]++;
            
            //cout << "now on letter " << c << endl;
            
            if(t_map.count(c) > 0 && window_map[c] == t_map[c]) {			// check if current letter amount in window matches the same letter amount in t
                cout << "formed on letter " << c << endl;
                formed++;
            }
        
            while(l <= r && formed == required) {							// when we have all letters of t (and same amount) in the window, we can start contracting the window
                c = s[l];
                if(ans[0] == -1 || r - l + 1 < ans[0]) {					// record current smallest window
                    ans[0] = r - l + 1;
                    ans[1] = l;
                    ans[2] = r;
                }
                
                window_map[c]--;											// contract window
                if(window_map.count(c) > 0 && window_map[c] < t_map[c]) {	// remove letter pointed to by l, if the removal causes mismatch between window and t, r will move
                    cout << "decremented letter " << c << endl;
                    formed--;
                }

                l++;
            }
            r++;
            cout << "r is " << r << endl;
        }
        return ans[0] == -1 ? "" : s.substr(ans[1], ans[0]);
    }  
};