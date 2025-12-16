/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */

int compare(const void* a, const void* b) { return *(int*)a - *(int*)b; }

int** fourSum(int* nums, int numsSize, int target, int* returnSize,
              int** returnColumnSizes) {

    if (numsSize < 4) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    qsort(nums, numsSize, sizeof(int), compare);

    int** arr = (int**)malloc(numsSize * numsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numsSize * numsSize * sizeof(int));
    int index = 0;

    for (int i = 0; i < numsSize - 3; i++) {

        if (i >= 1 && nums[i] == nums[i - 1]) {
            continue;
        }

        for (int j = i + 1; j < numsSize - 2; j++) {

            if (j >= i + 2 && nums[j] == nums[j - 1]) {
                continue;
            }

            int l = j + 1;
            int r = numsSize - 1;

            while (l < r) {
                long long sum =
                    (long long)nums[i] + nums[j] + nums[l] + nums[r];

                if (sum == target) {
                    arr[index] = (int*)malloc(4 * sizeof(int));
                    arr[index][0] = nums[i];
                    arr[index][1] = nums[j];
                    arr[index][2] = nums[l];
                    arr[index][3] = nums[r];

                    (*returnColumnSizes)[index] = 4;
                    index++;

                    while (l < r && nums[l] == nums[l + 1]) {
                        l++;
                    }
                    while (l < r && nums[r] == nums[r - 1]) {
                        r--;
                    }

                    l++;
                    r--;
                } else if (sum > target) {
                    r--;
                } else if (sum < target) {
                    l++;
                }
            }
        }
        *returnSize = index;
    }

    return arr;
}
