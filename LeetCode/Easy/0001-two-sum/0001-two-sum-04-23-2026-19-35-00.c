/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i, j, a, b;
    int* result = (int*)malloc(2*sizeof(int));
    *returnSize = 2;
    for (i=0;i<numsSize;i++) {
        for (j = i+1;j < numsSize;j++) {
            a=nums[i];
            b=nums[j];
            if(a + b == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    free(returnSize);
    return NULL;
}