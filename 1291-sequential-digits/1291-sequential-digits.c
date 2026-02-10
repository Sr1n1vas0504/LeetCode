//ch.sc.u4cse24146
int* sequentialDigits(int low, int high, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int)); // Allocate enough space
    int count = 0;
    for (int length = 2; length <= 9; length++) {
        for (int start = 1; start <= 10 - length; start++) {
            int num = 0;
            for (int i = 0; i < length; i++) {
                num = num * 10 + (start + i);
            }
            if (num >= low && num <= high) {
                result[count++] = num;
            }
        }
    }
    *returnSize = count;
    return result;
}
