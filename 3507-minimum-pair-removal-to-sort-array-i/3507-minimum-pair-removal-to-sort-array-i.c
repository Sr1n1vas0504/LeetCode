#include <stdio.h>

void adjust(int nums[], int *numsSize, int index){
    for(int i = index; i < (*numsSize)-1; i++){
        nums[i] = nums[i+1];
    }
    (*numsSize)--;
}

int isNonDecreasing(int nums[], int size){
    for(int i = 0; i < size-1; i++){
        if(nums[i] > nums[i+1])
            return 0;
    }
    return 1;
}

int minimumPairRemoval(int* nums, int numsSize) {
    int count = 0;
    while(!isNonDecreasing(nums, numsSize) && numsSize > 1){
        int minSum = nums[0] + nums[1];
        int minIndex = 0;
        for(int i = 0; i < numsSize-1; i++){
            int sum = nums[i] + nums[i+1];
            if(sum < minSum){
                minSum = sum;
                minIndex = i;
            }
        }
        nums[minIndex] = minSum;
        adjust(nums, &numsSize, minIndex+1);
        count++;
    }

    return count;
}
