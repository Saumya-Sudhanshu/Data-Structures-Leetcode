/*
27 Remove Element
time complexity: O(n) where n is the length of the input array.
space complexity: O(1) as we are using only a constant amount of extra space 
Approach: linear search technique to iterate through the array and overwrite the elements that are not equal to the target value.
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int count = 0;

        for (auto &it : nums){
            if(it != val){
                count++;
                nums[i] = it;
                i++;
            }
        }

        return count;
    }
};