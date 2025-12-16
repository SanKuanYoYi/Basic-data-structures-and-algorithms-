/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {

    int l = 0;
    int r = numbersSize - 1;

    while (l < r) {
        if (numbers[l] + numbers[r] == target) {
            break;
        } else if (numbers[l] + numbers[r] > target) {
            r--;
        } else {
            l++;
        }
    }

    int* arr = (int*)malloc(2 * sizeof(int));
    arr[0] = l + 1;
    arr[1] = r + 1;

    *returnSize = 2;

    return arr;
}
