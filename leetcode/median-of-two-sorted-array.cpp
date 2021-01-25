/*
Problem Statement:

Median of Two Sorted Array:

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

*/

class Solution {
public:
    double findSingleArrayMedian(vector<int>& nums,int n)
    {
        if(n % 2 != 0)
            return (nums[n/2] + nums[n/2 + 1])/2.0;
        else
            return nums[n/2];
    }
    double findMultipleArrayMedian(vector<int>& nums1,int len1,vector<int>& nums2,int len2)
    {
        int pos = (len1 + len2 + 1)/2;
        int l1 = 0,h1 = len1;
        int mid1,l2;
        while(l1 <= h1)
        {
            mid1 = (l1 + h1)/2;
            l2 = pos - mid1;
            if(mid1 < h1 && nums2[l2-1] > nums1[mid1])
                l1 = mid1 + 1;
            else if(mid1 > l1 && nums1[mid1-1] > nums2[l2])
                h1 = mid1 - 1;
            else
            {
                int l,r;
                if(mid1 == 0)
                    l = nums2[l2-1];
                else if(l2 == 0)
                    l = nums1[mid1-1];
                else
                    l = max(nums2[l2-1],nums1[mid1-1]);
                if((len1 + len2) % 2 != 0)
                    return l;
                if(mid1 == len1)
                    r = nums2[l2];
                else if(l2 == len2)
                    r = nums1[mid1];
                else
                    r = min(nums2[l2],nums1[mid1]);
                return (l+r)/2.0;
                    
            }
        }
        return 0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if(len1 == 0)
        {
            return findSingleArrayMedian(nums2,len2-1);
        }
        else if(len2 == 0)
        {
            return findSingleArrayMedian(nums1,len1-1);
        }
        else if(len1 <= len2)
        {
            return findMultipleArrayMedian(nums1,len1,nums2,len2);
        }
        else
        {
            return findMultipleArrayMedian(nums2,len2,nums1,len1);
        }
        
    }
};

/*

Input:
nums1 = [1,3]
nums2 = [2]

Output:
ans = 2.00000

*/
