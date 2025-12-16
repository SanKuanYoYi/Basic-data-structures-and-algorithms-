/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
#include <stdlib.h>

int compare(const void* a, const void* b) { return *(int*)a - *(int*)b; }

int** threeSum(int* nums, int numsSize, int* returnSize,
               int** returnColumnSizes) {

    qsort(nums, numsSize, sizeof(int), compare);

    int** arr = (int**)malloc(numsSize * numsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numsSize * numsSize * sizeof(int));
    int index = 0;

    for (int i = 0; i < numsSize - 2; i++) {

        if (nums[i] > 0) {
            break;
        }

        if (i >= 1 && nums[i] == nums[i - 1]) {
            continue;
        }

        int l = i + 1;
        int r = numsSize - 1;

        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];

            if (sum == 0) {
                arr[index] = (int*)malloc(3 * sizeof(int));
                arr[index][0] = nums[i];
                arr[index][1] = nums[l];
                arr[index][2] = nums[r];

                (*returnColumnSizes)[index] = 3;
                index++;

                while (l < r && nums[l] == nums[l + 1]) {
                    l++;
                }
                while (l < r && nums[r] == nums[r - 1]) {
                    r--;
                }

                l++;
                r--;
            } else if (sum > 0) {
                r--;
            } else if (sum < 0) {
                l++;
            }
        }
    }
    *returnSize = index;

    return arr;
}
