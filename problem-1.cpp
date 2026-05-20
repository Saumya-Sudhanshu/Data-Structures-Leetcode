/*
 * Approach 1: Sorting + Two Pointers
 * Time Complexity: O(N log N)
 * Space Complexity: O(N)
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
        vector<pair<int, int>> sorted_nums;
        for (int i = 0; i < n; i++) {
            sorted_nums.push_back({nums[i], i});
        }

        sort(sorted_nums.begin(), sorted_nums.end());

        int left = 0, right = n - 1;
        while (left < right) {
            int current_sum = sorted_nums[left].first + sorted_nums[right].first;
            
            if (current_sum == target) {
                return {sorted_nums[left].second, sorted_nums[right].second};
            } else if (current_sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {};
    }
};