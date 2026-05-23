/*
11. Container With Most Water
Time Complexity: O(n) as we traverse the height array once with two pointers.
Space Complexity: O(1) as we are using only a constant amount of extra space to store variables for the two pointers and the maximum area.
Approach: We use a two-pointer technique to find the maximum area of water 
that can be contained between the vertical lines represented by the height array.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;

        int left = 0, right = height.size() - 1;

        while(left < right){
            int storage = min(height[left], height[right]) * (right - left);
            if(storage > ans) ans = storage;

            if(height[left] < height[right]) left++;
            else right --;
        }

        return ans;
    }
};