double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    int res;
    int low = 0, high = nums1Size, mid1 = 0, mid2 = 0;
    int finishFlag=0;   // For exiting the loop.
    // Binary search for both arrays. 
    // but looking them as one array by locating
    // left and right elements technical places.
    while(low <= high && !finishFlag) {
        mid1 = (low + high) / 2;
        mid2 = ((nums1Size + nums2Size + 1)/2) - mid1;
        
        if (mid2 > 0 && mid1 < nums1Size && *(nums2 + mid2 - 1) > *(nums1 + mid1)) {
            low = mid1 + 1;
        }
        else if(mid1 > 0 && mid2 < nums2Size && *(nums1 + mid1 - 1) > *(nums2 + mid2)) {
            high = mid1 - 1;
        } else {    // If we made the arrangement for the not merged big array.
            finishFlag = 1;    // With the flag, exit the loop.
            if(mid1 == 0) {
                res = *(nums2 + mid2 - 1);
            }
            else if(mid2 == 0) {
                res = *(nums1 + mid1 - 1);
            } else {
                // Look for the biggest one.
                res = (nums1[mid1-1] > nums2[mid2-1]) ? nums1[mid1-1] : nums2[mid2-1];
            }
        }
    }
    if ((nums1Size + nums2Size) % 2 == 1) {
        return (double)res;
    }
    if(mid1 == nums1Size) {
        return (res + nums2[mid2]) / 2.0;
    }
    if(mid2 == nums2Size) {
        return (res + nums1[mid1]) / 2.0;
    }

    return (res + ( (nums1[mid1] > nums2[mid2]) ? nums2[mid2] : nums1[mid1] ) ) / 2.0;
}