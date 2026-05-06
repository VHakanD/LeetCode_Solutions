void moveZeroes(int* nums, int numsSize) {
    int i, j=0, numZero=0;
    int *temp = nums;
    if(numsSize == 1) return ;

    for(i=0;i<numsSize;i++) {
        if(*(nums+i) == 0) {
            numZero += 1;
        }
    }

    for(i=0;i<numsSize;i++) {
        if(*(nums+i) != 0) {
            *(temp+j) = *(nums+i);
            j++;
        }
    }
    
    while(j < numsSize) {
        *(temp+j) = 0;
        j++;
    }

    for(i = 0; i < numsSize; i++) {
        *(nums+i) = *(temp+i);
    }
}