/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findPeakGrid(int** mat, int matSize, int* matColSize, int* returnSize) {

    int* ans = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    ans[0] = ans[1] = 0;

    int left = 0;
    int right = *matColSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        int max_row = 0;
        for (int row = 1; row < matSize; row++) {
            if (mat[row][mid] > mat[max_row][mid]) {
                max_row = row;
            }
        }

        int left_val = (mid > 0) ? mat[max_row][mid - 1] : -1;
        int right_val = (mid < *matColSize - 1) ? mat[max_row][mid + 1] : -1;

        if (mat[max_row][mid] > left_val && mat[max_row][mid] > right_val) {
            ans[0] = max_row;
            ans[1] = mid;
            return ans;
        } else if (mat[max_row][mid] < left_val) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}
