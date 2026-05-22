/*
5. Longest Palindromic Substring
Given a string s, return the longest palindromic substring in s.

time complexity: O(n^2) where n is the length of the input string.
space complexity: O(1) as we are using only a few variables to keep track of the longest palindrome and its starting index.
Approach: We use a center expansion technique to find the longest palindromic substring.
*/

#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() <= 1) return s;

        int max_length = 1;
        int start_idx = 0;
        
        auto expandAroundCenter = [&](int left, int right){
            while(left >=0 && right <s.length() && s[left] == s[right]){
                int current_length = right - left + 1;
                if(current_length > max_length){
                    max_length = current_length;
                    start_idx = left;
                }
                left--;
                right++;
            }
        };
        for (int i = 0; i < s.length(); i++){
            expandAroundCenter(i,i);
            expandAroundCenter(i,i+1);
        }
        return s.substr(start_idx, max_length);
    }
};