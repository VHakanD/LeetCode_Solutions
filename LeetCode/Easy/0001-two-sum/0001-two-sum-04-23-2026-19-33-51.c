#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define HASH_SIZE 20000

typedef struct {
    int key;  
    int index;
    bool occupied; 
} HashNode;

int hash(long long key) {
    int h = key % HASH_SIZE;
    return h < 0 ? h + HASH_SIZE : h;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    HashNode* table = (HashNode*)calloc(HASH_SIZE, sizeof(HashNode));
    
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int h = hash(complement);

        while (table[h].occupied) {
            if (table[h].key == complement) {
                result[0] = table[h].index;
                result[1] = i;
                free(table);
                return result;
            }
            h = (h + 1) % HASH_SIZE;
        }

        int currentHash = hash(nums[i]);
        while (table[currentHash].occupied) {
            currentHash = (currentHash + 1) % HASH_SIZE;
        }
        table[currentHash].key = nums[i];
        table[currentHash].index = i;
        table[currentHash].occupied = true;
    }

    free(table);
    return NULL;
}