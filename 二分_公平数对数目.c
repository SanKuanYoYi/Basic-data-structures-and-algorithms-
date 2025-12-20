int compare(const void* a, const void* b) { return *(int*)a - *(int*)b; }

long long cntPairs(int* nums, int numsSize, int target) {

    long long cnt = 0;
    int left = 0;
    int right = numsSize - 1;

    while (left <= right) {
        if (nums[left] + nums[right] <= target) {
            cnt += right - left;
            left++;
        } else {
            right--;
        }
    }

    return cnt;
}

long long countFairPairs(int* nums, int numsSize, int lower, int upper) {

    qsort(nums, numsSize, sizeof(int), compare);

    long long cntUpper = cntPairs(nums, numsSize, upper);

    long long cntLower = cntPairs(nums, numsSize, lower - 1);

    return cntUpper - cntLower;
}

