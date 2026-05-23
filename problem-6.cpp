/*
6. ZigZag Conversion
Time Complexity: O(n^2) due to two for loops 
Space Complexity: O(n) as we are using a vector of strings to store the characters in each row of the zigzag pattern.
Approach: We use a vector of strings to represent the rows of the zigzag pattern. 
We iterate through the input string and append each character to the appropriate row based on the current direction of movement (down or up). 
Finally, we concatenate the rows to form the final zigzag string.
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        
        vector<char> bucket[numRows];
        string ans = "";

        int movingDown = 0;
        int i = 0;

        for(auto &it : s){
            if(i == 0 || i == numRows - 1) movingDown = !movingDown;
            if(movingDown == 1) bucket[i++].push_back(it);
            else bucket[i--].push_back(it);
        }

        for(int j = 0; j < numRows; j++){
            for(auto &it : bucket[j]){
                ans += it;
            }
        }

        return ans;
    }
};
