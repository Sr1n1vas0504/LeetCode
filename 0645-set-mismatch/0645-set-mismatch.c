#include <stdlib.h>
//ch.sc.u4cse24146
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    for (int i = 0; i < numsSize; i++) {
        int index = abs(nums[i]) - 1;
        if (nums[index] < 0) {
            result[0] = abs(nums[i]);  // Duplicate number
        } else {
            nums[index] = -nums[index];  // Mark as visited
        }
    }
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            result[1] = i + 1; 
            break;
        }
    }

    return result;
}
