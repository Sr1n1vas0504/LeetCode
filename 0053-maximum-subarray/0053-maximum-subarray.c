//ch.sc.u4cse24146
int maxSubArray(int* nums, int numsSize) {
    int maxSum = nums[0];
    int currentSum = nums[0];

    for (int i = 1; i < numsSize; i++) {
        // Decide whether to add to current sum or start new subarray
        if (currentSum < 0) {
            currentSum = nums[i];
        } else {
            currentSum += nums[i];
        }

        // Update maxSum if needed
        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
    }

    return maxSum;
}
