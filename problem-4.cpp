/*
4 Median of Two Sorted Arrays
time complexity: O(log(min(n1,n2))) where n1 and n2 are the lengths of the two input arrays.
space complexity: O(1) as we are using only a constant amount of extra space to store variables for the binary search.
Approach: We use a binary search technique to partition the two arrays such that 
the left half of the combined array contains the smaller elements and the right half contains the larger elements. 
We then calculate the median based on the maximum of the left half and the minimum of the right half.
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1+n2;

        if(n1>n2) return findMedianSortedArrays(nums2,nums1);

        int low = 0;
        int high = n1;
        int left = (n1+n2+1)/2;

        while(low<=high){

            int mid1 = (low+high)/2;
            int mid2 = left - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if(mid1<n1) r1 = nums1[mid1];
            if(mid2<n2) r2 = nums2[mid2];
            if(mid1-1>=0) l1 = nums1[mid1-1];
            if(mid2-1>=0) l2 = nums2[mid2-1];

            if(l1<=r2 && l2<=r1){
                if(n%2==1) return max(l1,l2);
                return (double)((max(l1,l2)+min(r1,r2))/2.0);
            }
            else if(l1>r2) high = mid1-1;
            else low = mid1+1;
        }
        return 0;
    }
};