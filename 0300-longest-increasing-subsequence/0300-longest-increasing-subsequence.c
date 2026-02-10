//ch.sc.u4cse24146
int lengthOfLIS(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int* dp = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;
    }
    int maxLen = 1;
    for (int i = 1; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                if (dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > maxLen)
            maxLen = dp[i];
    }
    free(dp);
    return maxLen;
}
