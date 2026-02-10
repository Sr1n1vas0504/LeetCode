//ch.sc.u4cse24146
#define MOD 1000000007
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int powerOfTwo(int n) {
    long long res = 1, base = 2;
    while (n > 0) {
        if (n % 2 == 1) {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        n /= 2;
    }
    return (int)res;
}
int numSubseq(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), compare);
    int left = 0, right = numsSize - 1;
    int result = 0;
    while (left <= right) {
        if (nums[left] + nums[right] <= target) {
            result = (result + powerOfTwo(right - left)) % MOD;
            left++;
        } else {
            right--;
        } }return result;
}