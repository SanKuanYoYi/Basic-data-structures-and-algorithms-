int maximumCount(int* nums, int numsSize) {

    int postCnt = 0;
    int negtCnt = 0;

    int posPos = numsSize;
    int negPos = -1;

    int left = 0;
    int right = numsSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > 0) {
            posPos = mid;
            right = mid - 1;

        }

        else {
            left = mid + 1;
        }
    }
    postCnt = numsSize - posPos;

    left = 0;
    right = numsSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] < 0) {
            negPos = mid;
            left = mid + 1;

        }

        else {
            right = mid - 1;
        }
    }
    negtCnt = negPos + 1;

    return postCnt > negtCnt ? postCnt : negtCnt;
}
