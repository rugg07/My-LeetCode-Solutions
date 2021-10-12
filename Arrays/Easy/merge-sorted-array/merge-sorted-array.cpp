class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k=(m+n-1); //point to last index after adding both sizes m&n
        int i=m-1, j=n-1; //point to last index of each array
        while(i>=0 and j>=0) //go from the last element till the first element so >=0
        {
            if(nums1[i]>nums2[j])
            {
                nums1[k]=nums1[i]; //greater number gets added to the end and we decrement the pointers
                k--;
                i--;
            }
            else{
                nums1[k]=nums2[j]; //greater number gets added to the end and we decrement the pointers
                k--;
                j--;
            }
        }
        while(i>=0) //if any values still remaining we add those one by one from the back
        {
            nums1[k--]=nums1[i--];
        }
        while(j>=0) //if any values still remaining we add those one by one from the back
        {
            nums1[k--]=nums2[j--];
        }
    }
};
