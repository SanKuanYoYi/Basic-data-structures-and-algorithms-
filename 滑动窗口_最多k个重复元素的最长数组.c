
int maxSubarrayLength(int* nums, int numsSize, int k) {

    int maxNum = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > maxNum)
            maxNum = nums[i];
    }

    int* count = (int*)calloc(maxNum + 1, sizeof(int));
    int left = 0;
    int maxLen = 0;

    for (int right = 0; right < numsSize; right++) {
        count[nums[right]]++;

        while (count[nums[right]] > k) {
            count[nums[left]]--;
            left++;
        }

        int currentLen = right - left + 1;
        if (currentLen > maxLen) {
            maxLen = currentLen;
        }
    }

    free(count);
    return maxLen;
}
