//ch.sc.u4cse24146
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int m = matrixSize;
    int n = *matrixColSize;
    int* result = (int*)malloc(m * n * sizeof(int));
    int index = 0;
    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;
    while (top <= bottom && left <= right) {
        // Move left to right
        for (int i = left; i <= right; i++)
            result[index++] = matrix[top][i];
        top++;
        // Move top to bottom
        for (int i = top; i <= bottom; i++)
            result[index++] = matrix[i][right];
        right--;
        // Move right to left
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                result[index++] = matrix[bottom][i];
            bottom--;
        }
        // Move bottom to top
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                result[index++] = matrix[i][left];
            left++;
        }
    }
    *returnSize = index;
    return result;
}
