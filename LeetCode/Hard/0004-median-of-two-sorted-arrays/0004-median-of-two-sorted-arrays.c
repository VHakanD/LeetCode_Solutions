double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    double res;
    int mid;
    int merged[nums1Size+nums2Size];
    int i=0, j=0, k=0;
    while((i < nums1Size) && (j < nums2Size)) {
        if(nums1[i] < nums2[j]) {
            merged[k] = nums1[i];
            i++;
            k++;
        } else {
            merged[k] = nums2[j];
            j++;
            k++;
        }
    }
    if(i == nums1Size) {
        while(j<nums2Size) {
            merged[k]=nums2[j];
            j++;
            k++;
        }
    } else {
        while(i<nums1Size) {
            merged[k]=nums1[i];
            i++;
            k++;
        }
    }

    if(k%2 == 1) {
        mid=merged[(nums1Size+nums2Size)/2];
        res=(double)mid;
        return(res);
    } else {
        res=((double)((merged[(nums1Size+nums2Size)/2])+(merged[((nums1Size+nums2Size)/2)-1])))/2;
        return(res);
    }
}