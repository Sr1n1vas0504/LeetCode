//ch.sc.u4cse24146
#define MAX_RESULT 150
#define MAX_COMB 100
void backtrack(int* candidates, int candidatesSize, int target, int* current, int currSize,
               int start, int** result, int* returnSize, int** returnColumnSizes) {
    if (target == 0) {
        // Found a valid combination
        result[*returnSize] = (int*)malloc(currSize * sizeof(int));
        for (int i = 0; i < currSize; i++) {
            result[*returnSize][i] = current[i];
        }
        (*returnColumnSizes)[*returnSize] = currSize;
        (*returnSize)++;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {
        if (candidates[i] <= target) {
            current[currSize] = candidates[i];
            backtrack(candidates, candidatesSize, target - candidates[i], current, currSize + 1,
                      i, result, returnSize, returnColumnSizes);  // i → allow reuse
        }
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target,
                     int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int** result = (int**)malloc(MAX_RESULT * sizeof(int*));
    *returnColumnSizes = (int*)malloc(MAX_RESULT * sizeof(int));
    int* current = (int*)malloc(MAX_COMB * sizeof(int)); 
    backtrack(candidates, candidatesSize, target, current, 0, 0, result, returnSize, returnColumnSizes);
    free(current);
    return result;
}
