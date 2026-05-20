/*
3. Longest Substring Without Repeating Characters
    Time complexity: O(n) where n is the length of the input string.
    space complexity: O(1) as this uses vector of length 256 each time.
    Approach: We use a sliding window technique to maintain a window of characters that contains no duplicates.
    We use two pointers, left and right, to represent the current window.
    We also use a hash map (or an array) to store the last index of each character we have seen.
    As we move the right pointer to expand the window, we check if the current character has been seen before and is within the current window. 
    If it has, we move the left pointer to the right of the last index of that character to ensure there are no duplicates in the window.
    We calculate the length of the current window and update the maximum length found so far.
    Finally, we return the maximum length of the substring without repeating characters.    
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        int left = 0, right = 0;
        int n = s.length();
        vector<int> hash(256, -1);

        while(right < n){
            if(hash[s[right]] != -1){
                //to avoid backward movement of left pointer we use max function 
                left = max(left,hash[s[right]] + 1);
            }
            int length = right - left + 1;
            max_length = max(max_length, length);
            hash[s[right]] = right;
            right++;
        }
        return max_length;
    }
};